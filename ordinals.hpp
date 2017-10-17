#pragma once

namespace ordinals
{
   using Nat = unsigned int;

   struct ordinal
   {
      ordinal& operator += (Nat i)
      {
         rhs_nat_ += i;
         return *this;
      }

      bool operator==(ordinal const& rhs) const { return rhs_nat_ == rhs.rhs_nat_;  }
      bool operator!=(ordinal const& rhs) const { return !(*this == rhs);           }
      bool operator< (ordinal const& rhs) const { return rhs_nat_ < rhs.rhs_nat_; }
      bool operator<=(ordinal const& rhs) const { return (*this < rhs) || (*this == rhs); }

   private:
      Nat rhs_nat_ = 0;
   };

   // See https://en.wikipedia.org/wiki/Ordinal_arithmetic#Addition

   // Ordinal addition is non-commutative
   auto operator+(ordinal const& ord, Nat i) { return ordinal(ord) += i;   }

   // Ordinal addition is left-cancellative:
   auto operator+(Nat, ordinal const& ord)   { return ord;                 }

   // all finite numbers are smaller than any ordinal
   bool operator<(Nat, ordinal const&)       { return true;                }
}