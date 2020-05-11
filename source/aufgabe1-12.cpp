#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <catch.hpp>
#include <cmath>

double calcCylVol (int radius_, int height_)
{
	if ((radius_ > 0) && (height_ > 0)) {
		return (M_PI * (radius_ * radius_) * height_); 
	}
	return -1;
}
double calcCylArea (int radius_, int height_)
{
	if ((radius_ > 0) && (height_ > 0)) {
		return (2 * M_PI * radius_ * (height_ + radius_));
	}
	return -1;
}

TEST_CASE("testing volume calculation", "[calcCylVol]")
{
        REQUIRE(calcCylVol(-10, -3) == Approx(-1));
        REQUIRE(calcCylVol(5, -7) == Approx(-1));
        REQUIRE(calcCylVol(-21, 6) == Approx(-1));
        REQUIRE(calcCylVol(0, 0) == Approx(-1));
        REQUIRE(calcCylVol(1, 1) == Approx(3.1415926));
        REQUIRE(calcCylVol(3, 8) == Approx(226.194671));
        REQUIRE(calcCylVol(12, 31) == Approx(14024.06961));
        REQUIRE(calcCylVol(723, 3225) == Approx(5296100116));
}

TEST_CASE("testing surface calculation", "[calcCylArea]")
{
        REQUIRE(calcCylArea(-10, -3) == Approx(-1));
        REQUIRE(calcCylArea(5, -7) == Approx(-1));
        REQUIRE(calcCylArea(-21, 6) == Approx(-1));
        REQUIRE(calcCylArea(0, 0) == Approx(-1));
        REQUIRE(calcCylArea(1, 1) == Approx(12.56637));
        REQUIRE(calcCylArea(3, 8) == Approx(207.34511));
        REQUIRE(calcCylArea(12, 31) == Approx(3242.123619));
        REQUIRE(calcCylArea(7236, 3225) == Approx(475610713.2));
}

int main(int argc, char* argv[])
{
	return Catch::Session().run( argc, argv );
}
