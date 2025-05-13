#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* Lazy propagating range sum segtree with range addition updates.
It might be convenient to replace ll val with a struct,
and then overload the + operator */

struct Segtree {
    ll l, r;
    Segtree *lt, *rt;
    ll val;
    ll lazy = 0;

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

    void propagate() {
        if(lazy) {
            val += lazy * (r-l+1);
            if(lt) {
                lt->lazy += lazy;
                rt->lazy += lazy;
            }
            lazy = 0;
        }
    }

    ll query(ll ql, ll qr) {
        propagate();

        if(qr < l or r < ql) return 0;
        if(ql <= l and r <= qr) return val;
        return lt->query(ql,qr) + rt->query(ql,qr);
    }

    void update(ll ul, ll ur, ll upd) {
        propagate();

        if(ur < l or r < ul) return;
        if(ul <= l and r <= ur) {
            lazy = upd;
            propagate();
            return;
        }
        lt->update(ul,ur,upd); 
        rt->update(ul,ur,upd);
        combine();
    }

    ~Segtree() {
        delete lt;
        delete rt;
    }

};