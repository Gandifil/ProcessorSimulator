#pragma once

#include <bitset>

template<size_t N>
struct Bus
{
	std::bitset<N> bitset;

    inline bool operator [](size_t index) const {
        return bitset[index];
    }

    inline void Set(size_t index, bool value) {
        bitset.set(index, value);
    }
};