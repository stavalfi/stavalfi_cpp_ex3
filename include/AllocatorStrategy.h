#ifndef STAVALFI_CPP_EX3_ALLOCATOR_STRATEGY_H
#define STAVALFI_CPP_EX3_ALLOCATOR_STRATEGY_H


#include <cstddef>
#include <new>

class AllocatorStrategy {
public:
    virtual void *allocate(std::size_t blockSize) throw(std::bad_alloc) = 0;

    virtual void deallocate(void *block) = 0;

    virtual ~AllocatorStrategy() = 0;
};


#endif //STAVALFI_CPP_EX3_ALLOCATOR_STRATEGY_H
