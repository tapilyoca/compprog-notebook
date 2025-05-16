#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* left set M, right set N */

vec<vec<bool>> listToMatrix(ll m, ll n, vvll &adj) {
    vec<vec<bool>> out(m, vec<bool>(n,0));

    for(int i = 0; i < m; i++) {
        for(ll &v : adj[i]) {
            out[i][v] = 1;
        }
    }

    return out;
}
    
bool bpm(vec<vec<bool>> &adj, ll u, bool vis[], ll matchR[]) {
    ll m = adj.size();
    ll n = adj[0].size();

    for(int v = 0; v < n; v++) {
        if(adj[u][v] and not vis[v]) {
            vis[v] = 1;
            if(matchR[v] < 0 or bpm(adj,matchR[v],vis,matchR)) {
                matchR[v] = u;
                return 1;
            }
        }
    }

    return 0;
}

ll bipartite_matching(vec<vec<bool>> &adj) {
    ll m = adj.size();
    ll n = adj[0].size();

    ll matchR[n];
    memset(matchR,-1,sizeof(matchR));
    ll out = 0;

    for(int u = 0; u < m; u++) {
        bool vis[n];
        memset(vis,0,sizeof(vis));
        if(bpm(adj,u,vis,matchR)) out++;
    }
    return out;
}


