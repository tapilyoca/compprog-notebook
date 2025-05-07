#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* Calculates x^y mod m. 
Ancient chinese proverb... */

ll modpow(ll x, ll y, ll m){
    ll ans = 1; x %= m; 
    if(x == 0) return 0;
    while(y > 0){
        if(y & 1) ans = (ans * x) % m;
        y = y >> 1;
        x = (x * x) % m;
    }
    return ans;
}
