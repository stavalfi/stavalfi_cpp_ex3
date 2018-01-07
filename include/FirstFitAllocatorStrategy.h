#ifndef STAVALFI_CPP_EX3_FIRST_FIT_ALLOCATOR_STRATEGY_H
#define STAVALFI_CPP_EX3_FIRST_FIT_ALLOCATOR_STRATEGY_H


#include "AllocatorStrategy.h"
#include "HashMapAllocator.h"

class FirstFitAllocatorStrategy : public AllocatorStrategy {
    HashMapAllocator hashMapAllocator;
public:
    void *allocate(std::size_t blockSize) throw(std::bad_alloc) override;

    void deallocate(void *block) throw() override;

    ~FirstFitAllocatorStrategy() override;
};


#endif //STAVALFI_CPP_EX3_FIRST_FIT_ALLOCATOR_STRATEGY_H
