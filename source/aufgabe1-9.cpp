#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <catch.hpp>

int qsum(int num)
{
	int res = 0;
	while (num > 0) {
		if (num < 10) {
			res = res + num;
			return res;
		}
		res = res + (num % 10);
		num = num / 10;
	}
	return res;
}

TEST_CASE("testing qsum", "[qsum]")
{
	REQUIRE(qsum(10) == 1);
	REQUIRE(qsum(233) == 8);
	REQUIRE(qsum(6753247) == 34); 
	REQUIRE(qsum(329462223) == 33);
	REQUIRE(qsum(-1) == 0 );
	REQUIRE(qsum(0) == 0);
	REQUIRE(qsum(-763294) == 0);
}

int main(int argc, char* argv[])
{
	return Catch::Session().run( argc, argv );
}
