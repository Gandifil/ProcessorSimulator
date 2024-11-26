#pragma once

template<bool P = true>
class Transistor
{
public:
	inline bool Calculate(bool power, bool gate) const noexcept {
		return power && CalculatePowerOn(gate);
	}

	inline bool CalculatePowerOn(bool gate) const noexcept {
		if constexpr (P)
			return gate;
		else
			return !gate;
	}
};

using PTransistor = Transistor<true>;
using NTransistor = Transistor<false>;