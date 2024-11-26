#pragma once
#include "../Elements/Transistor.hpp"

class And
{
public:
	PTransistor e1, e2;

	inline bool Calculate(bool x1, bool x2) const noexcept
	{
		return e2.Calculate(e1.Calculate(true, x1), x2);
	}
};

class Nand
{
public:
	NTransistor e1, e2;

	inline bool Calculate(bool x1, bool x2) const noexcept
	{
		return e1.Calculate(1, x1) || e2.Calculate(1, x2);
	}

};

class Or
{
public:
	PTransistor e1, e2;

	inline bool Calculate(bool x1, bool x2) const noexcept
	{
		return e1.Calculate(1, x1) || e2.Calculate(1, x2);
	}
};

class Not
{
public:
	NTransistor e;

	inline bool Calculate(bool x) const noexcept
	{
		return e.CalculatePowerOn(x);
	}
};

class Xor
{
public:
	Or e1;
	Nand e2;
	And finishElement;

	inline bool Calculate(bool x1, bool x2) const noexcept
	{
		return finishElement.Calculate(e1.Calculate(x1, x2), e2.Calculate(x1, x2));
	}
};