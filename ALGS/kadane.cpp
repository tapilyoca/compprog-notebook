#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* Max subarray sum. */

ll kadane(ll n, vll &a) {
    ll out = a[0];
    ll curr = a[0];
    for(int i = 1; i < n; i++) {
        curr = max(curr+a[i], a[i]);
        out = max(curr,out);
    } return out;
}