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

class Adder
{
private:
	HalfAdder _first;
	HalfAdder _second;
	Or _or;
public:
	bool result;
	bool overflow_bit;

	inline void Calculate(bool x1, bool x2, bool last_overflow_bit) noexcept {
		_first.Calculate(x1, x2);
		_second.Calculate(last_overflow_bit, _first.result);

		result = _second.result;
		overflow_bit = _or.Calculate(_first.overflow_bit, _second.overflow_bit);
	}
};