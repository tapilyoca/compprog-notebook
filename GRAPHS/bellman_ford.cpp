#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

#ifndef STRUCTS_HPP
#include ".structs.hpp"
#endif


vll bellman_ford(ll n, ll start, vec<Edge>&edges) { // returns {-1} in case of negative cycle
    vll dists(n+1,1e18);
    dists[start] = 0;

    for(int i = 0; i < n; i++) {
        for(Edge &e : edges) {
            if(dists[e.u] != 1e18 and dists[e.u] + e.weight < dists[e.v]) {
                if(i == n-1) return {-1};
                dists[e.v] = dists[e.u] + e.weight;
            }
        }
    }

    return dists;
}