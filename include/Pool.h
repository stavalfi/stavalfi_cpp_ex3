#ifndef STAVALFI_CPP_EX3_BLOCK_H
#define STAVALFI_CPP_EX3_BLOCK_H


#include <cstddef>

struct Pool {
private:
    char *block;
    const std::size_t blockSize;
public:
    Pool(char *block, const std::size_t blockSize);

    Pool(const Pool &pool) = default;

    Pool(Pool &&pool) : block(pool.block), blockSize(pool.blockSize) {
        pool.block = nullptr;
    }

    char *getBlock() const;

    const size_t getBlockSize() const;

    bool operator<=(const Pool &pool) const;


};


#endif //STAVALFI_CPP_EX3_BLOCK_H
