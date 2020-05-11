#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <catch.hpp>
#include <cmath>

double fract(double input_)
{
	int intput_ = (int) input_;
	return abs(input_ - intput_);
}

TEST_CASE("testing fract", "[fract]")
{
	REQUIRE(fract(1.123456789) == Approx(0.123456789));
	REQUIRE(fract(0.00000001) == Approx(0.00000001));
	REQUIRE(fract(-23.61343) == Approx(0.61343));
	REQUIRE(fract(3.1415926535) == Approx(0.1415926535));
	REQUIRE(fract(6.66666666) == Approx(0.66666666));
}

int main(int argc, char* argv[])
{
	return Catch::Session().run( argc, argv );
}
