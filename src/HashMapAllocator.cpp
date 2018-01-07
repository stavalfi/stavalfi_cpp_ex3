#include "HashMapAllocator.h"
#include <cmath>
#include <nss.h>

HashMapAllocator::HashMapAllocator()
        : arrayLength(0), array(nullptr) {}

char *HashMapAllocator::get(std::size_t desiredBlockSize) {
    std::size_t index = getArrayIndexBySize(desiredBlockSize);
    if (index >= this->arrayLength)
        // the request is too big for this heap.
        return nullptr;

    // find a free block and split it
    for (std::size_t i = index; i < arrayLength; ++i)
        if (!this->array[i].isEmpty())
            return splitAndReallocate(i, desiredBlockSize);

    // there is no space left for this request.
    return nullptr;
}

void HashMapAllocator::insert(char *freeBlock, std::size_t freeBlockSize) {
    if (freeBlockSize == 0)
        // we come to insert method after every split.
        // if there is no extra spase after the split,
        // then freeBlockSize=0.
        return;

    std::size_t index = getArrayIndexBySize(freeBlockSize);

    // check if this request is too big for this heap
    if (index >= this->arrayLength) {
        // we need to move the current array to a
        // bigger array and then deal with this request.
        std::size_t newArrayLength = index + 1;
        reallocateArray(newArrayLength);
        // this recursion can't be more then one time.
        insert(freeBlock, freeBlockSize);
        // end of deallocation
        return;
    }

    // allocate a given free block in our heap

    // freeBlockSize can be stored in my heap
    // because if not, we weren't be here.
    std::size_t sizeLeftToAllocate = freeBlockSize;
    for (std::size_t i = this->arrayLength - 1; sizeLeftToAllocate > 0 && i >= 0; i--) {
        std::size_t cellSize = pow(2, i);
        if (cellSize <= sizeLeftToAllocate) {
            this->array[i].insertSorted(freeBlock);
            sizeLeftToAllocate -= cellSize;
            freeBlock += cellSize;
        }
    }

    // end of deallocation
}

HashMapAllocator::~HashMapAllocator() {
    // call destructor for each set in the array.
    for (std::size_t i = 0; i < arrayLength; ++i)
        this->array[i].~Set();

    free(array);
}

std::size_t HashMapAllocator::getArrayIndexBySize(std::size_t size) const {
    assert(size > 0);
    std::size_t powOf2 = static_cast<int>(log2(size));
    if (pow(2, powOf2) < size)
        return powOf2 + 1;
    return powOf2;
}

void HashMapAllocator::reallocateArray(std::size_t newArrayLength) {
    this->arrayLength = newArrayLength;
    if (this->array == nullptr) {
        this->array = static_cast<Set<char *> *>(malloc(newArrayLength * sizeof(Set<char *>)));
        assert(this->array != nullptr);
        return;
    }
    this->array = static_cast<Set<char *> *>(realloc(this->array, newArrayLength * sizeof(Set<char *>)));
    assert(this->array != nullptr);
}

char *HashMapAllocator::splitAndReallocate(std::size_t indexOfArray, std::size_t desiredBlockSize) {
    assert(!this->array[indexOfArray].isEmpty());
    char *freeBlock = this->array[indexOfArray].removeFirst();
    std::size_t fullBlockSize = pow(2, indexOfArray);
    std::size_t sizeLeftAfterSplit = fullBlockSize - desiredBlockSize;
    insert(freeBlock + desiredBlockSize, sizeLeftAfterSplit);

    return freeBlock;
}
