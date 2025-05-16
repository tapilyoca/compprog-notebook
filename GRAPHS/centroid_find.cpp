#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* Finds a centroid. */

vll centroid_find(vvll &adj) {
    ll n = adj.size();
    vll out;
    vll subtree_size(n,1);
    
    function<void(ll,ll)> dfs = [&](ll u, ll p = -1) {
        bool is_centroid = 1;
        for(ll &v : adj[u]) {
            if(v == p) continue;
            dfs(v,u);
            subtree_size[u] += subtree_size[v];
            if(subtree_size[u] > n/2) is_centroid = false;
        }
        if(n - subtree_size[u] > n/2) is_centroid = false;
        if(is_centroid) out.pb(u);
    };

    dfs(0,-1);
    return out;
}