#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* Checks if an undirected graph has any cycles */

bool hasCycle(ll n, vvll &adj) {
    vec<bool> vis(n,0);

    function<bool(ll,ll)> dfs = [&] (ll v, ll parent) {
        vis[v] = 1;
        for(ll u : adj[v]) {
            if(u == parent) continue;
            if(not vis[u]) {
                if(dfs(u,v)) return true;
            } else {
                return true;
            }
        }
        return false;
    };
    
    for(int v = 0; v < n; v++) {
        if(not vis[v] and dfs(v,-1)) return true;
    }
    return false;
}

