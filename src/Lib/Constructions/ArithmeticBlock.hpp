#pragma once
#include "Bus.hpp"
#include "Adders.hpp"

template<size_t N>
class ArithmeticBlock 
{
private:
	Adder _adders[N];

public:
	Bus<N> result;
	bool overflow_bit;

	inline void Calculate(const Bus<N>& x1, const Bus<N>& x2)
	{
		bool overflow = false;
		for (size_t i = 0; i < N; i++)
		{
			_adders[i].Calculate(x1[i], x2[i], overflow);
			result.Set(i, _adders[i].result);
			overflow = _adders[i].overflow_bit;
		}
		overflow_bit = overflow;
	}
};