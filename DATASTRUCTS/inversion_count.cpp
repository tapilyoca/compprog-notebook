#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* Counts inversions in an array using a Segment tree.
Each node [l,r] in the segtree stores the number of array values processed so far
with value >= l and <= r.
Go through the array, query (a[i]+1,max), and update as you go along.

You may need to use coordinate compression or an implicit segtree (or both!)
if max is too large (> 2e5 or so). */

struct Segtree {
    ll l, r;
    Segtree *lt, *rt;
    ll val;

    void combine() {
        val = lt->val + rt->val;
    }

    Segtree(ll left, ll right) {
        l = left;
        r = right;
        val = 0;
        if(l == r) {
            lt = rt = nullptr;
        } else {
            ll mid = (l+r)>>1;
            lt = new Segtree(l,mid);
            rt = new Segtree(mid+1,r);
        }
    }

    ll query(ll ql, ll qr) {
        if(qr < l or r < ql) return 0;
        if(ql <= l and r <= qr) return val;
        return lt->query(ql,qr) + rt->query(ql,qr);
    }

    void update(ll added) {
        if(added < l or r < added) return;
        if(l == r and r == added) {
            val++;
            return;
        }
        lt->update(added);
        rt->update(added);
        combine();
    }
};

ll countInversions(ll n, vll &a) {
    ll mx = *max_element(a.begin(),a.end());
    Segtree st = Segtree(0,mx);
    ll out = 0;
    
    for(int i = 0; i < n; i++) {
        out += st.query(a[i]+1,mx);
        st.update(a[i]);
    }
    return out;
}