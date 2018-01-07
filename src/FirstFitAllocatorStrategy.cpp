#include "FirstFitAllocatorStrategy.h"

void *FirstFitAllocatorStrategy::allocate(std::size_t blockSize) throw(std::bad_alloc) {
    return nullptr;
}

void FirstFitAllocatorStrategy::deallocate(void *block) throw() {

}

FirstFitAllocatorStrategy::~FirstFitAllocatorStrategy() {

}
