#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

struct DSU {
    vll sizes, parent;

    DSU(ll n) {
        sizes.resize(n,1);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    ll find(ll i) {
        ll root = parent[i];
        if(parent[root] != root) {
            return parent[i] = find(root);
        }
        return root;
    }

    void unite(ll i, ll j) {
        ll irep = find(i);
        ll jrep = find(j);
        if(irep == jrep) return;

        if(sizes[irep] < sizes[jrep]) {
            parent[irep] = jrep;
            sizes[jrep] += sizes[irep];
        } else {
            parent[jrep] = irep;
            sizes[irep] += sizes[jrep];
        }
    }

    ll countComponents() {
        set<ll> ans;
        for(int i = 0; i < parent.size(); i++) {
            ans.insert(find(i));
        }
        return ans.size();
    }

    ll getLargest() { return *max_element(sizes.begin(),sizes.end()); }
    ll getSmallest() { return *min_element(sizes.begin(),sizes.end()); }
};