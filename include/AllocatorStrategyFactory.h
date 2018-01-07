#ifndef STAVALFI_CPP_EX3_ALLOCATOR_STRATEGY_FACTORY_H
#define STAVALFI_CPP_EX3_ALLOCATOR_STRATEGY_FACTORY_H


#include "AllocatorStrategy.h"
#include "FirstFitAllocatorStrategy.h"
#include <cstdlib>

enum class AllocatorStrategyType {
    FIRST_FIT
};

class AllocatorStrategyFactory {
public:
    static AllocatorStrategy *create(AllocatorStrategyType allocatorStrategyType) {
        switch (allocatorStrategyType) {
            case AllocatorStrategyType::FIRST_FIT: {
                return new(malloc(sizeof(FirstFitAllocatorStrategy))) FirstFitAllocatorStrategy();
            }
            default:
                return nullptr;
        }
    }
};


#endif //STAVALFI_CPP_EX3_ALLOCATOR_STRATEGY_FACTORY_H
