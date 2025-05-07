#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* For an integer n, returns the modular multiplicative inverse of n mod m.
Formally, MMI(n,m) = a <=> an = 1 mod m.
When m prime, all integers will have an MMI. 

Exact time complexity of this code is not known but it's fast enough.*/

ll invert_mod(ll n, ll MOD) {
    return n <= 1 ? n : MOD - (ll)(MOD/n) * invert_mod(MOD % n, MOD) % MOD;
}
