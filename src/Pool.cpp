#include "Pool.h"
#include <cstdlib>
#include <new>

Pool::Pool(char *block, const size_t blockSize)
        : block(block), blockSize(blockSize) {}

char *Pool::getBlock() const {
    return block;
}

const size_t Pool::getBlockSize() const {
    return blockSize;
}

bool Pool::operator<=(const Pool &pool) const {
    return this->block <= pool.block;
}
