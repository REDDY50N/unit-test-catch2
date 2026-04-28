#include <catch2/catch_test_macros.hpp>
#include "../src/weapons/SCAR5.h"

TEST_CASE( "A new SCAR5 weapon is not loaded" ) {

  // --  CTOR creates a weapon that is not loaded
  SCAR5 scar5;
  REQUIRE(scar5.isEmpty() == true);

};

TEST_CASE( "Firing an empty SCAR5 does not work" ) {

  SCAR5 scar5;
  REQUIRE(scar5.fire() == false);

}

TEST_CASE( "An empty weapon can be reloaded") {
  SCAR5 scar5;
  bool success = scar5.reload();
  REQUIRE(success == true);
}

TEST_CASE( "Shooting 30 rounds of a full magazin empties it") {
  SCAR5 scar5;
  scar5.reload();
  REQUIRE(scar5.magazine_state() == 30);

  for (int i=0; i < 30; i++) {
    REQUIRE(scar5.fire() == true);
  }

  REQUIRE(scar5.magazine_state() == 0);
  REQUIRE(scar5.isEmpty() == true);
}
