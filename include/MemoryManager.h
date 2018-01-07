#ifndef STAVALFI_CPP_EX3_MEMORY_MANAGER_H
#define STAVALFI_CPP_EX3_MEMORY_MANAGER_H

#include "AllocatorStrategy.h"

class MemoryManager {
    AllocatorStrategy *allocatorStrategy;
    MemoryManager()= default;

public:
    static MemoryManager &getInstance();

    AllocatorStrategy *getAllocatorStrategy() const;

    void setAllocatorStrategy(AllocatorStrategy *allocatorStrategy);
};

#endif //STAVALFI_CPP_EX3_MEMORY_MANAGER_H
