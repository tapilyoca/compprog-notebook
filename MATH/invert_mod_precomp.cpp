#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* Precomps the MMIs for integers from [1,n).
This runs in O(n) */

vll precomp_MMI(ll n, ll MOD) {
    vll inv(n+1,0);
    inv[1] = 1;
    for(int a = 2; a < n; a++) {
        inv[a] = MOD - (ll)(MOD/a) * inv[MOD%a] % MOD;
    }
    return inv;
}
