#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* Finding SCCS in digraphs. 
This returns a condesned version where each SCC becomes a node. */

vvll kosaraju(ll n, vvll &adj) {
    vvll components;
    vvll adj_condensed;
    vll order; // reversed toposort of G
    vec<bool> vis(n,0);

    function<void(ll,vvll&,vll&)> dfs = [&] (ll v, vvll &adjj, vll &x) {
        vis[v] = true;
        for(ll &u : adjj[v]) {
            if(!vis[u]) {
                dfs(u,adjj,x);
            }
        }
        x.pb(v);
    };

    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs(i,adj,order); 
    }

    vvll transpose(n);
    for(int v = 0; v < n; v++) {
        for(int u : adj[v]) {
            transpose[u].pb(v);
        }
    }

    vis.assign(n,0);
    reverse(order.begin(),order.end()); // regular toposort
    vll roots(n,0); // roots of SCCs
    for(ll &v : order) {
        if(!vis[v]) {
            vll comp;
            dfs(v,transpose,comp);
            components.pb(comp);
            ll root = *min_element(comp.begin(),comp.end());
            for(ll &u : comp) roots[u] = u;
        }
    }

    adj_condensed.assign(n,{});
    for(int v = 0; v < n; v++) {
        for(ll &u : adj[v]) {
            if(roots[v] != roots[u]) { // if in different SCC
                adj_condensed[roots[v]].push_back(roots[u]); // then add edge
            }
        }
    }

    return adj_condensed;
}