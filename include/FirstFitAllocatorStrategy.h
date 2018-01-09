#ifndef STAVALFI_CPP_EX3_FIRST_FIT_ALLOCATOR_STRATEGY_H
#define STAVALFI_CPP_EX3_FIRST_FIT_ALLOCATOR_STRATEGY_H


#include "AllocatorStrategy.h"
#include "HashMapAllocator.h"
#include "MemoryPool.h"

class FirstFitAllocatorStrategy : public AllocatorStrategy {
    std::size_t currentAllocationSize=0;
    HashMapAllocator hashMapAllocator;

    /**
     * calculate how much extra space we
     * need to allocate on the real heap
     * for our heap.
     * @param blockSize we need to allocate
     * and we don't have any space for in
     * our heap at the moment.
     * @return 2^x, where x is the smallest number such that blockSize<=2^x.
     */
    std::size_t calculateExtraHeapSizeNeeded(std::size_t blockSize) const;

public:
    void *allocate(std::size_t blockSize) throw(std::bad_alloc) override;

    void deallocate(void *block) throw() override;

    void extendHeap(std::size_t size) override;

    ~FirstFitAllocatorStrategy() override;
};


#endif //STAVALFI_CPP_EX3_FIRST_FIT_ALLOCATOR_STRATEGY_H
