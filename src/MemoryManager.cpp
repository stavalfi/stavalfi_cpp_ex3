#include "MemoryManager.h"
#include <cassert>
#include <iostream>


MemoryManager &MemoryManager::getInstance() {
    static MemoryManager memoryManager;
    return memoryManager;
}

AllocatorStrategy *MemoryManager::getAllocatorStrategy() const {
    return allocatorStrategy;
}

void MemoryManager::setAllocatorStrategy(AllocatorStrategy *allocatorStrategy) {
    MemoryManager::allocatorStrategy = allocatorStrategy;
}

void MemoryManager::extendHeap(std::size_t size) {
    assert(this->allocatorStrategy != nullptr);
    this->allocatorStrategy->extendHeap(size);
}
