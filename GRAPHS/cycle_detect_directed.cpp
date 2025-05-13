#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* Checks if a DAG has any cycles */

vll cycle_finder(ll n, vvll &adj) {
    vec<char> color(n,0);
    vll parent(n,-1);

    ll cycle_start = -1, cycle_end = -1;

    function<bool(ll)> dfs = [&] (ll v) {
        color[v] = 1;
        for(ll u : adj[v]) {
            if(color[u] == 0) {
                // new unvisited node
                parent[u] = v;
                if(dfs(u)) return true;
            } else if(color[u] == 1) {
                // same branch <=> must be a cycle
                cycle_end = v;
                cycle_start = u;
                return true;
            }
        }
        color[v] = 2; //exit
        return false;
    };

    for(int v = 0; v < n; v++) {
        if(color[v] == 0 and dfs(v)) break;
    }

    if(cycle_start == -1) return {-1};

    // return the cycle
    vll out;
    out.pb(cycle_start);
    for(int v = cycle_end; v != cycle_start; v = parent[v]) {
        out.pb(v);
    }
    out.pb(cycle_start); // comment out if needed
    reverse(out.begin(),out.end());
    
    return out;
}



/* Alternatively, for a plain yes/no version */

bool hasCycle(ll n, vvll &adj) {
    vec<char> color(n,0);

    function<bool(ll)> dfs = [&] (ll v) {
        color[v] = 1;
        for(ll u : adj[v]) {
            if(color[u] == 0) {
                if(dfs(u)) return true;
            } else if(color[u] == 1) {
                return true;
            }
        }
        color[v] = 2; //exit
        return false;
    };

    for(int v = 0; v < n; v++) {
        if(color[v] == 0 and dfs(v)) return true;
    } return false;
}