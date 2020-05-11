#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <catch.hpp>

int checksum(int num_)
{
	int res_ = 0;
	while (num_ > 0) {
		if (num_ < 10) {
			res_ = res_ + num_;
			return res_;
		}
		res_ = res_ + (num_ % 10);
		num_ = num_ / 10;
	}
	return res_;
}

TEST_CASE("testing checksum", "[checksum]")
{
	REQUIRE(checksum(10) == 1);
	REQUIRE(checksum(233) == 8);
	REQUIRE(checksum(120996) == 27);
	REQUIRE(checksum(6753247) == 34); 
	REQUIRE(checksum(329462223) == 33);
	REQUIRE(checksum(1) == 1);
	REQUIRE(checksum(-1) == 0);
	REQUIRE(checksum(0) == 0);
	REQUIRE(checksum(-763294) == 0);
}

int main(int argc, char* argv[])
{
	return Catch::Session().run( argc, argv );
}
