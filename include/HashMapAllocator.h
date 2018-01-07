#ifndef STAVALFI_CPP_EX3_HASH_MAP_ALLOCATOR_H
#define STAVALFI_CPP_EX3_HASH_MAP_ALLOCATOR_H

#include <cmath>
#include <cstddef>
#include "Set.h"
#include "Pool.h"

class HashMapAllocator {
    std::size_t arrayLength;
    Set<char *> *array;

    /**
     * @param number
     * @return the power of 2 which 2^x is the smallest
     * and bigger or equal to this number.
     */
    std::size_t getArrayIndexBySize(std::size_t size) const;

    /**
     * copy the old array to a new allocated array
     * @param newArrayLength
     */
    void reallocateArray(std::size_t newArrayLength);

    /**
     * split the first block in the given set's node.
     * @param indexOfArray
     * @return he desired free block.
     */
    char *splitAndReallocate(std::size_t indexOfArray, std::size_t desiredBlockSize);

public:

    HashMapAllocator(std::size_t initialBlockSize);

    char *get(std::size_t desiredBlockSize) {
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

    void insert(char *freeBlock, std::size_t freeBlockSize) {
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

    ~HashMapAllocator() {
        // call destructor for each set in the array.
        for (std::size_t i = 0; i < arrayLength; ++i)
            this->array[i].~Set();

        free(array);
    }
};


#endif //STAVALFI_CPP_EX3_HASH_MAP_ALLOCATOR_H
