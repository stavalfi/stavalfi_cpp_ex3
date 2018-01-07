#ifndef STAVALFI_CPP_EX3_MEMORY_POOL_H
#define STAVALFI_CPP_EX3_MEMORY_POOL_H

#include <new>
#include "Set.h"
#include "Pool.h"

class MemoryPool {
    Set<Pool> pools;

    MemoryPool() = default;

public:
    MemoryPool(const MemoryPool &) = delete;

    static MemoryPool &getInstance();

    std::size_t currentHeapSize() const;

    /**
     * try to extend the current memory pool.
     * @param blockSize
     * @return if succeed, return the initial address
     * of the new extended place in our heap,
     * else return nullptr.
     */
    char *addPool(const size_t blockSize) throw(std::bad_alloc);
};

#endif //STAVALFI_CPP_EX3_MEMORY_POOL_H
