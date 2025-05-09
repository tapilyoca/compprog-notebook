#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* Sieve of Eratosthenes code from cpalgs.
returns an isPrime array up to the integer n */

vec<bool> primeSieve(ll n) {
    vec<bool> isPrime(n+1,1);

    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i*i <= n; i++) {
        if(isPrime[i]) {
            for(int j = i*i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    return isPrime;
}