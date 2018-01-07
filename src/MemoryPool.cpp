#include "MemoryPool.h"
#include <cassert>


MemoryPool &MemoryPool::getInstance() {
    static MemoryPool memoryPool;
    return memoryPool;
}

char *MemoryPool::addPool(const size_t blockSize) throw(std::bad_alloc) {
    char *extraPool = static_cast<char *>(malloc(blockSize));
    assert(extraPool != nullptr);
    return this->pools.insertSorted(Pool(extraPool, blockSize)).getBlock();
}

std::size_t MemoryPool::currentHeapSize() const {
    return this->pools.sum([](const Pool &pool) {
        return pool.getBlockSize();
    });
}
