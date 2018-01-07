#include "FirstFitAllocatorStrategy.h"
#include <iostream>
#include <cmath>

void *FirstFitAllocatorStrategy::allocate(std::size_t blockSize) throw(std::bad_alloc) {
    std::size_t blockSizeWithHeader = blockSize + sizeof(std::size_t);
    char *block = this->hashMapAllocator.get(blockSizeWithHeader);
    if (block == nullptr) {
        // we need more space in our heap!
        std::size_t extraHeapSize = calculateExtraHeapSizeNeeded(blockSizeWithHeader);
        extendHeap(extraHeapSize);
        return allocate(blockSize);
    }
    // write how many bytes we allocated
    std::size_t *writeBlockSize = reinterpret_cast<std::size_t *>(block);
    *writeBlockSize = blockSize;
    std::cout << "allocated: " << blockSizeWithHeader << " bytes" << std::endl;
    // return the pointer to the "data" without the header.
    return block + sizeof(std::size_t);
}

void FirstFitAllocatorStrategy::deallocate(void *block) throw() {
    std::size_t *readBlockSize = static_cast<std::size_t *>(block);
    assert(readBlockSize != nullptr);
    readBlockSize--;
    std::size_t blockSizeWithHeader = *readBlockSize + sizeof(std::size_t);
    this->hashMapAllocator.insert(reinterpret_cast<char *>(readBlockSize), blockSizeWithHeader);
    std::cout << "deallocated: " << blockSizeWithHeader << " bytes" << std::endl;
}

FirstFitAllocatorStrategy::~FirstFitAllocatorStrategy() {

}

void FirstFitAllocatorStrategy::extendHeap(std::size_t size) {
    char *pool = MemoryPool::getInstance().addPool(size);
    assert(pool);
    this->hashMapAllocator.insert(pool, size);
}

std::size_t FirstFitAllocatorStrategy::calculateExtraHeapSizeNeeded(std::size_t blockSize) const {
    std::size_t powOf2 = static_cast<int>(log2(blockSize));
    if (pow(2, powOf2) < blockSize)
        powOf2++;
    return static_cast<std::size_t>(pow(2, powOf2));
}