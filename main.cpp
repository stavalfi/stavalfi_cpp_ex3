/**
 204031397

 My design:

 As I understood from the instructions and it was approved by Miri during the class, each time I have
 no more space to allocare, then I ask for more by using malloc.
 Also I do not need to replace new[] and delete[] also because if I do not replace them then new and delete are called instead with the same arguments.

 Pool class represent a part of my heap and I will add more pools as long as I'm out of memory.
 MemoryPool class represent a collection of Pool objects. It have one importent method: addPool - which add
 a new pool to the pools. MemoryPool is singleton,

 I may have multiple allocation algorithms so I created AllocatorStrategy interface to represent a algorithm.
 I implemented one algorithm: FirstFitAllocatorStrategy.
 To create a new algorithm, I use a Factory design pattern by using AllocatorStrategyFactory class.

 The replacement of the new and delete operators is located at Allocator.cpp file.

 My FirstFit Strategy:
 As discussed with Miri during the class, there is no connection between the instructions and first fit.
 But I used this name as the instructions demand.

 I implemented hashmap using array and if I'm creating new pool, I will resize the array if nessesry.
 Each map cell is a set of addresses which represent a free block we can allocate in a specific size = 2^n.

 the hashmap is allocated using a malloc and the nodes of the sets also. this because I can't allocated them on my heap
 because I'm using them to allcoate anything on the heap. This can't be done.

 All in all, I used singleton, factory and I preserved the single responsibility principle.

 */

#include <MemoryManager.h>
#include <AllocatorStrategyFactory.h>

int main(int argc, char *argv[]) {
    assert(argc >= 3);
    std::size_t initialHeapSize = atoi(argv[2]);
    AllocatorStrategy *allocatorStrategy = AllocatorStrategyFactory::create(AllocatorStrategyType::FIRST_FIT);
    MemoryManager::getInstance().setAllocatorStrategy(allocatorStrategy);
    MemoryManager::getInstance().extendHeap(initialHeapSize);
    /**
     ....................Start-Allocating...........................
     */
    int *a = new int[2];
    delete[] a;
    /**
     .......................End-Allocating...........................
     */
    return 0;
    /**
     .........................End-Valgrind...........................
     */
}