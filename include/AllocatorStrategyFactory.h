#ifndef STAVALFI_CPP_EX3_ALLOCATOR_STRATEGY_FACTORY_H
#define STAVALFI_CPP_EX3_ALLOCATOR_STRATEGY_FACTORY_H


#include "AllocatorStrategy.h"
#include "FirstFitAllocatorStrategy.h"
#include <cstdlib>

enum class AllocatorStrategyType {
    FIRST_FIT
};

class AllocatorStrategyFactory {
    AllocatorStrategyFactory() = delete;

public:
    static AllocatorStrategy *create(AllocatorStrategyType allocatorStrategyType);
};


#endif //STAVALFI_CPP_EX3_ALLOCATOR_STRATEGY_FACTORY_H
