#include <catch2/catch_test_macros.hpp>
#include "../src/weapons/G36.h"

TEST_CASE("G36 - Initial State", "[G36]") {
  G36 g36;

  // CHECK vs REQUIRE
  CHECK(g36.current_ammo() == 30);    // does not stop the test on error
  REQUIRE(g36.current_ammo() == 30);  // stops on error

  REQUIRE(g36.can_fire() == true);
  REQUIRE(g36.is_jammed() == false);
}

TEST_CASE("G36 - Fire reduces ammunition", "[G36]") {
  G36 g36;

  uint8_t shot = g36.fire(12);
  REQUIRE(shot == 12);
  REQUIRE(g36.current_ammo() == 18);
  REQUIRE(g36.can_fire() == true);
}

TEST_CASE("G36 - Cannot fire more than available", "[G36]") {
  G36 g36;
  g36.fire(25);                    // nur 25 statt 30

  REQUIRE(g36.current_ammo() == 5);
}

TEST_CASE("G36 - Becomes jammed when empty", "[G36]") {
  G36 g36;
  g36.fire(30);

  REQUIRE(g36.current_ammo() == 0);
  REQUIRE(g36.can_fire() == false);
  REQUIRE(g36.is_jammed() == true);
}

TEST_CASE("G36 - Reload resets state", "[G36]") {
  G36 g36;
  g36.fire(30);
  g36.reload();

  REQUIRE(g36.current_ammo() == 30);
  REQUIRE(g36.can_fire() == true);
  REQUIRE(g36.is_jammed() == false);
}