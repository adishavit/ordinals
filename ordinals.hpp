#pragma once

namespace ordinals
{
   using Nat = unsigned long long;

   struct ordinal
   {
      ordinal& operator += (Nat i)
      {
         rhs_nat_ += i;
         return *this;
      }

      // right hand increment: o += 1
      ordinal& operator ++() { return *this += 1; }
      ordinal operator ++(int) 
      { 
         ordinal tmp{ *this };
         *this += 1;
         return  tmp; 
      }

      bool operator==(ordinal const& rhs) const { return rhs_nat_ == rhs.rhs_nat_;  }
      bool operator!=(ordinal const& rhs) const { return !(*this == rhs);           }
      bool operator< (ordinal const& rhs) const { return rhs_nat_ < rhs.rhs_nat_; }
      bool operator<=(ordinal const& rhs) const { return (*this < rhs) || (*this == rhs); }

      // range for support
      auto begin() 
      { 
         struct NatIter
         {
            operator Nat()     { return nat;          }     // implicit Nat conversion
            auto operator*()   { return nat;          }     // deref returns value
            auto& operator++() { ++nat; return *this; }     // incr. increments
            bool operator!=(NatIter const&) { return true; }// comparison is always false
            Nat nat = 0;
         };
         return NatIter{};
      }
      auto end() { return begin(); }

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
   bool operator==(Nat, ordinal const&) { return false; }
   bool operator==(ordinal const&, Nat) { return false; }
   bool operator!=(Nat, ordinal const&) { return true; }
   bool operator!=(ordinal const&, Nat) { return true; }
}