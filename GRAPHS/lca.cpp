#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* Does what you think it does. 
This has two parts: the up function, then the actual LCA binjumping. */

ll n, l; // l = ceil(log2(n))
vvll adj, up; // up is n * l
ll timer;
vll tin, tout;

void dfs(ll v, ll p) {
    tin[v] = timer++;
    up[v][0] = p;

    for(int i = 1; i <= l; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for(ll &u : adj[v]) {
        dfs(u,v);
    }
    tout[v] = ++timer;
}

bool is_ancestor(ll u, ll v) {
    return tin[u] <= tin[v] and tout[u] >= tout[v];
}

ll lca(ll u, ll v) {
    if(is_ancestor(u,v)) return u;
    if(is_ancestor(v,u)) return v;
    for(int i = l; i >= 0; i--) {
        if(!is_ancestor(up[u][i],v)) u = up[u][i];
    }
    return up[u][0];
}