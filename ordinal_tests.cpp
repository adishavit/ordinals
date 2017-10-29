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

TEST_CASE("simple for loop")
{
   ordinal o;
   for (int i = 0; i<o && i <10; ++i)
      CHECK(i < o);

   for (unsigned int i = 0; i < o && i < 10; ++i)
      CHECK(i < o);

   for (long i = 0; i < o && i < 10; ++i)
      CHECK(i < o);

   for (unsigned long i = 0; i < o && i < 10; ++i)
      CHECK(i < o);

   for (long long i = 0; i < o && i < 10; ++i)
      CHECK(i < o);

   for (unsigned long long i = 0; i < o && i < 10; ++i)
      CHECK(i < o);

   for (unsigned long long i = 0; i != o && i < 10; ++i)
      CHECK(i < o);
}

TEST_CASE("Increment operators")
{
   ordinal o1, o2;
   CHECK(o1 + 1 == ++o2);
   CHECK(o1++ != o2);
   CHECK(o1 == o2);
}

TEST_CASE("Comparison operators")
{
   ordinal o;
   CHECK(0 != o);
   CHECK(o != 0);
   CHECK_FALSE(0 == o);
   CHECK_FALSE(o == 0);
}

TEST_CASE("Range for loop")
{
   ordinal o;
   for (auto i : o)
   {
      if (10 < i) break;
      CHECK(i < o);
   }

   for (auto beg = o.begin(); beg != o.end() ; ++beg)
   {
      if (10 < beg) break;
      CHECK((beg < o));
      CHECK((*beg) < o);
      CHECK(*beg < o);
      CHECK(ordinals::Nat(beg) < o);
      CHECK(ordinals::Nat(*beg) < o);
   }
}