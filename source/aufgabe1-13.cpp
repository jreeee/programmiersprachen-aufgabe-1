#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <catch.hpp>

long factorial(long num)
{
	if ((num < 0) || (num > 20)) return -1;
	if (num == 0) return 1;
	long res = 1;
	for (num; num > 0; num--) {
		res = res * num;
	}
}

void detUB()
{
	long num = 10;
	long res = factorial(num);
	while (factorial(num) > 0) {
		num++;
		res = factorial(num);
	}
	std::cout << (num -1) << " is the upper bound\n";
}

TEST_CASE("testing factorial", "[factorial]")
{
	REQUIRE(factorial(0) == 1);
	REQUIRE(factorial(1) == 1);
	REQUIRE(factorial(2) == 2);
	REQUIRE(factorial(3) == 6);
	REQUIRE(factorial(-1) == -1);
	REQUIRE(factorial(-10) == -1);
	REQUIRE(factorial(10) == 3628800);
	REQUIRE(factorial(16) == 20922789888000);
	REQUIRE(factorial(20) == 2432902008176640000);
	REQUIRE(factorial(21) < 0);
}

int main(int argc, char* argv[])
{
	//detUB();
	return Catch::Session().run( argc, argv );
}
