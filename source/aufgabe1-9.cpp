#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <catch.hpp>

int checksum(int num)
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

TEST_CASE("testing checksum", "[checksum]")
{
	REQUIRE(checksum(10) == 1);
	REQUIRE(checksum(233) == 8);
	REQUIRE(checksum(6753247) == 34); 
	REQUIRE(checksum(329462223) == 33);
	REQUIRE(checksum(-1) == 0 );
	REQUIRE(checksum(0) == 0);
	REQUIRE(checksum(-763294) == 0);
}

int main(int argc, char* argv[])
{
	return Catch::Session().run( argc, argv );
}
