#include "ordinals.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace ordinals;

TEST_CASE("Test ctor")
{
   ordinal ord0, ord1;
   CHECK(ord0 == ord1);
}

TEST_CASE("Left Nat addition")
{
   ordinal o;
   CHECK(o == 0 + o);                  // Zero is an additive identity
   CHECK(o == 1 + o);
   CHECK(1 + o == o);
   CHECK(1 + o == 2 + o);
   CHECK(o == (1 + 2) + o);
   CHECK(1 + (2 + o) == (1 + 2) + o);  // Addition is associative
}

TEST_CASE("Right Nat addition")
{
   ordinal o;
   CHECK(o == o + 0);                  // Zero is an additive identity
   CHECK(o != o + 1);
   CHECK(o + 1 != o);
   CHECK(o + 1 != o + 2);
   CHECK(o + (1 + 2) == (o + 1) + 2); // Addition is associative
}

TEST_CASE("Left/Right Ordering")
{
   ordinal o;
   // Addition is strictly increasing and continuous in the right argument
   CHECK(o < o + 1);
   CHECK(o <= o + 1);
   CHECK_FALSE(o + 1 < o);
   CHECK_FALSE(o + 1 <= o);

   // but the analogous relation does not hold for the left argument; 
   CHECK_FALSE(o < 1 + o);
   // instead we only have:
   CHECK(o <= 1 + o);
}





