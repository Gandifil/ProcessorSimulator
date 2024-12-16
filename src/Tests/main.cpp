#define BOOST_TEST_MODULE "first_test"

#include <boost/test/included/unit_test.hpp>
#include "../Lib/Constructions/Elementary.hpp"
#include "../Lib/Constructions/Adders.hpp"
#include "../Lib/Constructions/ArithmeticBlock.hpp"


BOOST_AUTO_TEST_CASE(or_test)
{
	Or element;

	BOOST_TEST(!element.Calculate(false, false));
	BOOST_TEST(element.Calculate(false, true));
	BOOST_TEST(element.Calculate(true, false));
	BOOST_TEST(element.Calculate(true, true));
}

BOOST_AUTO_TEST_CASE(and_test)
{
	And element;

	BOOST_TEST(!element.Calculate(false, false));
	BOOST_TEST(!element.Calculate(false, true));
	BOOST_TEST(!element.Calculate(true, false));
	BOOST_TEST(element.Calculate(true, true));
}

BOOST_AUTO_TEST_CASE(xor_test)
{
	Xor element;

	BOOST_TEST(!element.Calculate(false, false));
	BOOST_TEST(element.Calculate(false, true));
	BOOST_TEST(element.Calculate(true, false));
	BOOST_TEST(!element.Calculate(true, true));
}

BOOST_AUTO_TEST_CASE(not_test)
{
	Not element;

	BOOST_TEST(!element.Calculate(true));
	BOOST_TEST(element.Calculate(false));
}

BOOST_AUTO_TEST_CASE(half_adder_test)
{
	HalfAdder element;

	element.Calculate(true, true);
	BOOST_TEST(!element.result);
	BOOST_TEST(element.overflow_bit);

	element.Calculate(true, false);
	BOOST_TEST(element.result);
	BOOST_TEST(!element.overflow_bit);

	element.Calculate(false, false);
	BOOST_TEST(!element.result);
	BOOST_TEST(!element.overflow_bit);
}

//constexpr std::bitset<8> c{ 0b00001010 };
BOOST_AUTO_TEST_CASE(add_test)
{
	ArithmeticBlock<8> element;

	element.Calculate({ 0b00001000 }, { 0b00000010 });
	BOOST_TEST(element.result.bitset == std::bitset<8>{ 0b00001010 });
	BOOST_TEST(!element.overflow_bit);

	element.Calculate({ 0b00000010 }, { 0b00000010 });
	BOOST_TEST(element.result.bitset == std::bitset<8>{ 0b00000100 });
	BOOST_TEST(!element.overflow_bit);
}