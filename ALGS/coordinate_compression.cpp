#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* Zero-indexed. Does what you think. */

void coord_comp(vll &a) {
    ll n = a.size();
    vec<pll> temp(n);
    
    for(int i = 0; i < n; i++) {
        temp[i] = {a[i], i};
    }

    sort(temp.begin(), temp.end());
    int cid = 0;
    for(int i = 0; i < n; i++) {
        if(i > 0 and temp[i-1].first != temp[i].first) cid++; // new element
        a[temp[i].second] = cid;
    }
}