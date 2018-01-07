#include "HashMapAllocator.h"
#include <cmath>

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
    std::size_t index = getArrayIndexBySize(freeBlockSize);

    // check if this request is too big for this heap
    if (index >= this->arrayLength) {
        // we need to move the current array to a
        // bigger array and then deal with this request.
        reallocateArray(index);
        // this recursion can't be more then one time.
        insert(freeBlock, freeBlockSize);
        // end of deallocation
        return;
    }

    // allocate a given free block in our heap

    // freeBlockSize can be stored in my heap
    // because if not, we weren't be here.
    std::size_t sizeLeftToAllocate = freeBlockSize;
    for (std::size_t i = this->arrayLength - 1; sizeLeftToAllocate >= 0 || i >= 0; i--) {
        std::size_t cellSize = pow(2, i);
        if (cellSize <= sizeLeftToAllocate) {
            this->array[i].insertSorted(std::move(freeBlock));
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
    return 0;
}

void HashMapAllocator::reallocateArray(std::size_t newArrayLength) {

}

char *HashMapAllocator::splitAndReallocate(std::size_t indexOfArray, std::size_t desiredBlockSize) {
    return nullptr;
}

HashMapAllocator::HashMapAllocator()
        : arrayLength(0), array(nullptr) {}
