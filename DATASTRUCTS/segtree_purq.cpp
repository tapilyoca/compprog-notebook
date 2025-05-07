#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

struct Segtree {
    ll l, r;
    Segtree *lt, *rt;
    ll val;

    void combine() {
        val = lt->val + rt->val;
    }

    Segtree(ll left, ll right, vll &a) {
        l = left;
        r = right;
        lt = rt = nullptr;
        if(l == r) {
            val = a[l];
            return;
        }
        ll mid = (l+r)>>1;
        lt = new Segtree(l,mid,a);
        rt = new Segtree(mid+1,r,a);
        combine();
    }

    ll query(ll ql, ll qr) {
        if(qr < l or r < ql) return 0;
        if(ql <= l and r <= qr) return val;
        return lt->query(ql,qr) + rt->query(ql,qr);
    }

    void update(ll dex, ll upd) {
        if(dex < l or r < dex) return;
        if(l == r and l == dex) {
            val = upd;
        }
        lt->update(dex,upd);
        rt->update(dex,upd);
        combine();
    }
};