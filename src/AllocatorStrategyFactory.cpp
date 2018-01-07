#include "AllocatorStrategyFactory.h"

AllocatorStrategy *AllocatorStrategyFactory::create(AllocatorStrategyType allocatorStrategyType) {
    switch (allocatorStrategyType) {
        case AllocatorStrategyType::FIRST_FIT: {
            return new(malloc(sizeof(FirstFitAllocatorStrategy))) FirstFitAllocatorStrategy();
        }
        default:
            return nullptr;
    }
}
