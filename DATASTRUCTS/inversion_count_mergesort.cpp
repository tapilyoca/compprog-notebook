#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* Usually faster/better memory than the segtree method. */


ll countAndMerge(vll &a, ll l, ll r) {
    ll m = (l+r)>>1;
    
    ll n1 = m-l+1;
    ll n2 = r-n1;
    vll left(n1), right(n2);
    
    for(int i = 0; i < n1; i++) {
        left[i] = a[i+l];
    }
    for(int i = 0; i < n2; i++) {
        right[i] = a[m+1+i];
    }

    ll out = 0;
    int lp = 0, rp = 0, ap = l;
    while(lp < n1 and rp < n2) {
        if(left[lp] <= right[rp]) {
            // everything is fine
            a[ap++] = left[lp++];
        } else {
            a[ap++] = right[rp++];
            out += n1-lp; // extra bits
        }
    }

    while(lp < n1) a[ap++] = left[lp++];
    while(rp < n2) a[ap++] = right[rp++];
    return out;
}

ll countInversions(vll &a, ll l, ll r) {
    ll out = 0;
    
    if(l < r) {
        ll mid = (l+r)>>1;
        out += countInversions(a,l,mid);
        out += countInversions(a,mid+1,r);
        out += countAndMerge(a,l,r);
    }
    
    return out;
}