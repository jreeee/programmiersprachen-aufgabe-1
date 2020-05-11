#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>

int gcd(int num1_, int num2_)
{
	int smallerNumber_ = num1_;
	int biggerNumber_ = num2_;

	if (num1_ > num2_) {
		biggerNumber_ = num1_;
        smallerNumber_ = num2_;
	}

	int res_ = smallerNumber_;
	while (((biggerNumber_ % res_) + (smallerNumber_ % res_)) != 0) {
		res_--;
		}
	return res_;
}

TEST_CASE("describe_gcd", "[gcd]")
{
	REQUIRE(gcd(2,4) == 2);
	REQUIRE(gcd(9,6) == 3);
	REQUIRE(gcd(3,7) == 1);
}

int main(int argc, char* argv[])
{
	return Catch::Session().run( argc, argv );
}
