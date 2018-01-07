#include <MemoryManager.h>
#include <AllocatorStrategyFactory.h>
#include <iostream>
#include <Allocator.h>

using namespace std;

struct A {
    A() {
        cout << "A()" << endl;
    }

    ~A() {
        cout << "~A()" << endl;
    }
};

int main(int argc, char *argv[]) {
    assert(argc == 3);
    std::size_t initialHeapSize = atoi(argv[2]);
    AllocatorStrategy *allocatorStrategy = AllocatorStrategyFactory::create(AllocatorStrategyType::FIRST_FIT);

    MemoryManager::getInstance().setAllocatorStrategy(allocatorStrategy);
    MemoryManager::getInstance().extendHeap(initialHeapSize);
    /**
     ...............................................
     */
    A *a = new A();
    delete (a);
    return 0;
}