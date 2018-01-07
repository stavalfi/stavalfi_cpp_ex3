#include "FirstFitAllocatorStrategy.h"
#include <iostream>

void *FirstFitAllocatorStrategy::allocate(std::size_t blockSize) throw(std::bad_alloc) {
    char *block = this->hashMapAllocator.get(blockSize + sizeof(std::size_t));
    // write how many bytes we allocated
    std::size_t *writeBlockSize = reinterpret_cast<std::size_t *>(block);
    *writeBlockSize = blockSize;
    std::cout << "allocated: " << (blockSize + sizeof(std::size_t)) << " bytes" << std::endl;
    // return the pointer to the "data" without the header.
    return block + sizeof(std::size_t);
}

void FirstFitAllocatorStrategy::deallocate(void *block) throw() {
    std::size_t *readBlockSize = static_cast<std::size_t *>(block);
    readBlockSize--;
    this->hashMapAllocator.insert(reinterpret_cast<char *>(readBlockSize), *readBlockSize + sizeof(std::size_t));
    std::cout << "deallocated: " << (*readBlockSize + sizeof(std::size_t)) << " bytes" << std::endl;
}

FirstFitAllocatorStrategy::~FirstFitAllocatorStrategy() {

}

void FirstFitAllocatorStrategy::extendHeap(std::size_t size) {
    char *pool = MemoryPool::getInstance().addPool(size);
    assert(pool);
    this->hashMapAllocator.insert(pool, size);
}
