#ifndef STAVALFI_CPP_EX3_HASH_MAP_ALLOCATOR_H
#define STAVALFI_CPP_EX3_HASH_MAP_ALLOCATOR_H

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

    HashMapAllocator();;

    char *get(std::size_t desiredBlockSize);

    void insert(char *freeBlock, std::size_t freeBlockSize);

    ~HashMapAllocator();
};


#endif //STAVALFI_CPP_EX3_HASH_MAP_ALLOCATOR_H
