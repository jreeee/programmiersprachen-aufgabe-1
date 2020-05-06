#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <catch.hpp>

int sum_multiples(int range)
{
	int sum = 0;
	if (range < 1) range = 1000;
	for (range; range > 0; range--) {
		if ((range % 3) == 0) {
			sum = sum + range;
		}
		else if ((range % 5) == 0) {
			sum = sum + range;
		}
	}
	return sum;
}

TEST_CASE("testing sum_multiples", "[sum_multiples]")
{
	REQUIRE(sum_multiples(1) == 0);
	REQUIRE(sum_multiples(3) == 3);
	REQUIRE(sum_multiples(5) == 8);
	REQUIRE(sum_multiples(15) == 60);
	REQUIRE(sum_multiples(0) == 234168);
	REQUIRE(sum_multiples(1000) == 234168);

}
int main(int argc, char* argv[])
{
	return Catch::Session().run( argc, argv );
}
