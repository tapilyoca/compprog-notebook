#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* 2-SAT */

struct TwoSat {
    ll n, m;
    vvll adj, adj_trans;
    vec<bool> used, assignment;
    vll order,comp;

    TwoSat(ll N) : n(N), m(2*N), adj(2*N), adj_trans(2*N), used(2*N), order(), comp(2*N,-1),assignment(N) {
        order.reserve(2*N);
    }

    void dfs_topo(ll v) {
        used[v] = 1;
        for(ll &u : adj[v]) {
            if(!used[u]) {
                dfs_topo(u);
            }
        }
        order.pb(v);
    }

    void dfs_assign(ll v, ll cid) {
        comp[v] = cid;
        for(ll &u : adj_trans[v]) {
            if(comp[u] == -1) {
                dfs_assign(u,cid);
            }
        }
    }

    bool solve() {
        order.clear();
        used.assign(m,0);
        for(int i = 0; i < m; i++) {
            if(!used[i]) dfs_topo(i);    
        }
        
        comp.assign(m,-1);
        for(int i = 0, cid = 0; i < m; i++) {
            ll v = order[m-i-1];
            if(comp[v] == -1) {
                dfs_assign(v,cid++);
            }
        }

        assignment.assign(n,0);
        for(int i = 0; i < m; i += 2) {
            if(comp[i] == comp[i+1]) {
                // x <=> not x
                return false;
            }
            assignment[i>>1] = comp[i] > comp[i+1];
        }
        return true;
    }

    vec<bool> getAssignment() {
        // assumes solve has already been called
        return assignment;
    }

    void add_disjunction(ll a, ll b, bool na, bool nb) {
        a = 2 * a ^ na;
        b = 2 * b ^ nb;
        ll neg_a = a^1;
        ll neg_b = b^1;
        adj[neg_a].pb(b);
        adj[neg_b].pb(a);
        adj_trans[b].pb(neg_a);
        adj_trans[a].pb(neg_b);
    }
};