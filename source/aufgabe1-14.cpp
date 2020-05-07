#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <catch.hpp>
#include <cmath>

bool is_prime(int num)
{
    if (num == 0) return false;
    if (num < 0) num = abs(num);
    for (int i = (num/2) ; i > 1; i--) {
        if ((num % i) == 0) {
            return false;
        }
    }
    return true;
}

TEST_CASE("testing for primes", "[is_prime]")
{
    REQUIRE(is_prime(0) == false);
	REQUIRE(is_prime(1) == true);
	REQUIRE(is_prime(2) == true);
	REQUIRE(is_prime(-3) == true);
	REQUIRE(is_prime(4) == false);
	REQUIRE(is_prime(-27) == false);
    REQUIRE(is_prime(31) == true);
    REQUIRE(is_prime(-31) == true);
    REQUIRE(is_prime(7919) == true);
    REQUIRE(is_prime(27644437) == true);
    REQUIRE(is_prime(3242987) == false);
    REQUIRE(is_prime(324298) == false);
}

int main(int argc, char* argv[])
{
	return Catch::Session().run( argc, argv );
}
