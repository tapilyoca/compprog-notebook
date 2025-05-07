#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

vll djk(ll n, vec<vec<pll>> &adj, ll start = 0) {
    vll dists(n,1e18);
    dists[start] = 0;

    priority_queue<pll, vec<pll>, greater<pll>> pq; // {dist, node}
    pq.push({0,start});

    while(!pq.empty()) {
        pll tmp = pq.top();
        pq.pop();
        ll node = tmp.second;
        ll curDist = tmp.first;
        
        if(curDist > dists[node]) continue;

        for(pll p : adj[node]) {
            ll neighbor = p.second;
            ll weight = p.first;
            if(curDist + weight < dists[neighbor]) {
                dists[neighbor] = curDist + weight;
                pq.push({dists[neighbor], neighbor});
            }
        }
    }

    return dists;
}

