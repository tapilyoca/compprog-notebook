#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* This is just here for reference (i.e., "do i set lp = m, or lp=m+1? what do i return?")
Realistically it's almost always faster to just... type it out. 
Please type it out. */ 

bool check(ll m);

ll binSearch(vll &a) {
    ll lp = 0, rp = a.size() - 1;
    
    while(lp <= rp) {
        ll m = (lp+rp)>>1;
        if(check(m)) {
            lp = m+1;
        } else {
            rp = m-1;
       }
    }

    if(check(lp)) {
        return lp;
    }
    
    return -1;
}