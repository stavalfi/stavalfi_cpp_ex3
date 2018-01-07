#include <MemoryManager.h>
#include <AllocatorStrategyFactory.h>
#include <iostream>

using namespace std;

struct A {
    int x;

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
    cout << "1current heap size: " << MemoryPool::getInstance().currentHeapSize() << endl;
    AllocatorStrategy *allocatorStrategy = AllocatorStrategyFactory::create(AllocatorStrategyType::FIRST_FIT);
    cout << "2current heap size: " << MemoryPool::getInstance().currentHeapSize() << endl;
    MemoryManager::getInstance().setAllocatorStrategy(allocatorStrategy);
    cout << "3current heap size: " << MemoryPool::getInstance().currentHeapSize() << endl;
    MemoryManager::getInstance().extendHeap(initialHeapSize);
    /**
     ...............................................
     */
    cout << "4current heap size: " << MemoryPool::getInstance().currentHeapSize() << endl;
    A *a = new A[2];
    cout << "5current heap size: " << MemoryPool::getInstance().currentHeapSize() << endl;
    delete[] a;
    cout << "6current heap size: " << MemoryPool::getInstance().currentHeapSize() << endl;
    return 0;
}