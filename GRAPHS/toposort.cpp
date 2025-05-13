#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* Topological sort of a DAG.
Assumes no cycles. */

vll toposort(ll n, vvll &adj, vec<bool> &vis) {
    vll ans;

    function<void(ll)> dfs = [&] (ll v) {
        vis[v] = 1;
        for(ll u : adj[v]) {
            if(!vis[u]) {
                dfs(u);
            }
        }
        ans.pb(v);
    };

    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}