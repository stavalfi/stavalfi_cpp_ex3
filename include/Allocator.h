#ifndef STAVALFI_CPP_EX3_ALLOCATOR_H
#define STAVALFI_CPP_EX3_ALLOCATOR_H

#include <cstddef>
#include "MemoryManager.h"

void *operator new(std::size_t blockSize) throw(std::bad_alloc) {
    return MemoryManager::getInstance().getAllocatorStrategy()->allocate(blockSize);
}


void operator delete(void *block) throw() {
    return MemoryManager::getInstance().getAllocatorStrategy()->deallocate(block);
}

#endif //STAVALFI_CPP_EX3_ALLOCATOR_H
