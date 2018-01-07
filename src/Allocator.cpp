#include "Allocator.h"

#include <iostream>
#include <cstddef>
#include "MemoryManager.h"

void *operator new(std::size_t blockSize) throw(std::bad_alloc) {
    std::cout << "new: " << blockSize << " bytes" << std::endl;
    return MemoryManager::getInstance().getAllocatorStrategy()->allocate(blockSize);
}


void operator delete(void *block) throw() {
    return MemoryManager::getInstance().getAllocatorStrategy()->deallocate(block);
}