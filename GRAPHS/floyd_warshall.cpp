#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

vvll floyd_warshall(ll n, vec<vec<pll>>& adj) {
    vvll dists(n+1, vll(n+1,1e18));
    
    for(int i = 0; i <= n; i++) dists[i][i] = 0;

    for(int i = 0; i < n; i++) {
        for(pll &p : adj[i]) {
            ll v = p.first;
            ll w = p.second;
            dists[i][v] = w;
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dists[i][k] != 1e18 and dists[k][j] != 1e18) {
                    dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
                }
            }
        }
    }

    return dists;
}