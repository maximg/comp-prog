
#include "catch2/catch.hpp"

unsigned int right_propagate(unsigned int x) {
    return x | (x-1);
}

unsigned int mod_power_2(unsigned int x, unsigned int pwr2) {
    int m = 1 << pwr2;
    return x & (m-1);
}

bool is_power_2(unsigned int x) {
    return x && ((x & (x - 1)) == 0);
}

TEST_CASE( "right_propagate") {

    SECTION( "valid" ) {
        REQUIRE(right_propagate(1) == 1);
        REQUIRE(right_propagate(2) == 3);
        REQUIRE(right_propagate(8) == 0xF);
        REQUIRE(right_propagate(0x40000000) == 0x7FFFFFFF);
        REQUIRE(right_propagate(0x80000000) == 0xFFFFFFFF);
    }

    SECTION( "special cases") {
        // right propagate not defined on 0
        REQUIRE(right_propagate(0) == 0xFFFFFFFF);
    }
}

TEST_CASE( "mod_power_2") {

    SECTION( "valid" ) {
        REQUIRE(mod_power_2(0, 0) == 0);
        REQUIRE(mod_power_2(0, 1) == 0);
        REQUIRE(mod_power_2(1, 0) == 0);
        REQUIRE(mod_power_2(1, 1) == 1);
        REQUIRE(mod_power_2(1, 2) == 1);
        REQUIRE(mod_power_2(3, 0) == 0);
        REQUIRE(mod_power_2(3, 1) == 1);
        REQUIRE(mod_power_2(2047, 8) == 255);
        REQUIRE(mod_power_2(2047, 9) == 511);
        REQUIRE(mod_power_2(2047, 10) == 1023);
        REQUIRE(mod_power_2(0xFFFFFFFF, 10) == 1023);
    }
}

TEST_CASE( "is_power_2") {

    SECTION( "is true" ) {
        REQUIRE(is_power_2(1) == true);
        REQUIRE(is_power_2(2) == true);
        REQUIRE(is_power_2(4) == true);
        REQUIRE(is_power_2(0x80000000) == true);
    }
    SECTION( "is false" ) {
        REQUIRE(is_power_2(0) == false);
        REQUIRE(is_power_2(3) == false);
        REQUIRE(is_power_2(514) == false);
        REQUIRE(is_power_2(0x81000000) == false);
    }
}
