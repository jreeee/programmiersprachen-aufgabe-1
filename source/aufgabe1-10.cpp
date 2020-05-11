#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <catch.hpp>

int sum_multiples(int range_)
{
	int sum_ = 0;
	if ((range_ < 1) || (range_ > 95934)) range_ = 1000;
	//if the range value is less than one or would cause an overflow, we set it to 1000
    //to use upperbound() or betterUB() the if statement above needs to be commented out
	for (range_; range_ > 0; range_--) {
		if ((range_ % 3) == 0) {
			sum_ = sum_ + range_;
		}
		else if ((range_ % 5) == 0) {
			sum_ = sum_ + range_;
		}
	}
	return sum_;
}

void upperbound()
//very basic way to calculate the overflow barrier
{
	int max_ = 1000;
	int val_ = sum_multiples(max_);
	while (val_ > 0) {
		max_++;
		val_ = sum_multiples(max_);
	}
	std::cout << (max_ - 1) << "\n";
}

void betterUB()
//better way to go about calculating the upper bound
{
	int max_ = 1000;
	int val_ = sum_multiples(max_);
	int mul_ = 2;
	while (val_ > 0) {
		max_ = max_ * 2;
		val_ = sum_multiples(max_);
	}
	while (((sum_multiples(max_) > 0) && (sum_multiples(max_+1) < 0)) == false) {
		val_ = sum_multiples(max_);
		mul_ = mul_ + 2;
		if (val_ > 0) max_ = max_ + max_ / mul_; else max_ = max_ - max_ / mul_;
	}
	std::cout << (max_) << "\n";
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
