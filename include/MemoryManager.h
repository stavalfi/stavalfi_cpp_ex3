#ifndef STAVALFI_CPP_EX3_MEMORY_MANAGER_H
#define STAVALFI_CPP_EX3_MEMORY_MANAGER_H

#include "AllocatorStrategy.h"
#include "MemoryPool.h"

class MemoryManager {
    bool isValgrindEnabled = false;
    AllocatorStrategy *allocatorStrategy = nullptr;

    MemoryManager() = default;

public:
    static MemoryManager &getInstance();

    AllocatorStrategy *getAllocatorStrategy() const;

    void extendHeap(std::size_t size);

    void setAllocatorStrategy(AllocatorStrategy *allocatorStrategy);
};

#endif //STAVALFI_CPP_EX3_MEMORY_MANAGER_H
