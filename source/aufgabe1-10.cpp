#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <catch.hpp>

int sum_multiples(int range)
{
	int sum = 0;
	if ((range < 1) || (range > 95934)) range = 1000;
	//if the range value is less than one or would cause an overflow, we set it to 1000
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

void upperbound()
//very basic way to calculate the overflow barrier
{
	int max = 1000;
	int val = sum_multiples(max);
	while (val > 0) {
		max++;
		val = sum_multiples(max);
	}
	std::cout << (max - 1) << "\n";
}

void betterUB()
//better way to go about calculating the upper bound
{
	int max = 1000;
	int val = sum_multiples(max);
	int n = 2;
	while (val > 0) {
		max = max * 2;
		val = sum_multiples(max);
	}
	while (((sum_multiples(max) > 0) && (sum_multiples(max+1) < 0)) == false) {
		val = sum_multiples(max);
		n = n + 2;
		if (val > 0) max = max + max / n; else max = max - max / n;
	}
	std::cout << (max) << "\n";
}

TEST_CASE("testing sum_multiples", "[sum_multiples]")
{
	REQUIRE(sum_multiples(1) == 0);
	REQUIRE(sum_multiples(3) == 3);
	REQUIRE(sum_multiples(4) == 3);
	REQUIRE(sum_multiples(5) == 8);
	REQUIRE(sum_multiples(15) == 60);
	REQUIRE(sum_multiples(0) == 234168);
	REQUIRE(sum_multiples(1000) == 234168);
	REQUIRE(sum_multiples(95934) == 2147472998);
	REQUIRE(sum_multiples(95935) == 234168);
}
int main(int argc, char* argv[])
{
	//betterUB();
	//upperbound();
	return Catch::Session().run( argc, argv );
}
