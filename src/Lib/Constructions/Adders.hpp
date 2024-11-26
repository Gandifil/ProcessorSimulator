#pragma once
#include "Elementary.hpp"

class HalfAdder
{
private:
	Xor _xor;
	And _and;

public:
	bool result;
	bool overflow_bit;

	inline void Calculate(bool x1, bool x2) noexcept {
		result = _xor.Calculate(x1, x2);
		overflow_bit = _and.Calculate(x1, x2);
	}
};