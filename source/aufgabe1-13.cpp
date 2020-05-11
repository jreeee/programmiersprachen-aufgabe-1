#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <catch.hpp>

long factorial(long num_)
{
	if ((num_ < 0) || (num_ > 20)) return -1;
	if (num_ == 0) return 1;
	long res_ = 1;
	for (num_; num_ > 0; num_--) {
		res_ = res_ * num_;
	}
}

void detUB()
{
	long num_ = 10;
	long res_ = factorial(num_);
	while (factorial(num_) > 0) {
		num_++;
		res_ = factorial(num_);
	}
	std::cout << (num_ -1) << " is the upper bound\n";
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
