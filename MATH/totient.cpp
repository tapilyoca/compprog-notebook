#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* Euler's Totient Function.
By definition, tot(n) = number of integers less than n that are relatively prime to n.
Equal to prod(1-1/p) for all prime p dividing n, times n.
*/

ll totient(ll n) {
    ll out = n;
    for(int p = 2; p * p <= n; p++){
        if(!(n%p)){
            while(n%p == 0) n /= p;
            out -= out/p;
        }
    } if(n>1) out -= out/n;
    return out;
}