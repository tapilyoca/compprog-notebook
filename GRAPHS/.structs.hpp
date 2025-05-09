#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* Structs for nodes and edges.
Helpful for Bellman Ford and the like but usually it's easier to just code using indices.
Only use if there really isn't a prettier way to keep everything together.
*/

struct Edge {
    ll u, v;
    ll weight;
    
    Edge() : u(0), v(0), weight(0) {} 
    Edge(ll a, ll b, ll w) {
        u = a;
        v = b;
        weight = w;
    }

    bool operator<(const Edge&two) const {
        return weight < two.weight;
    }

    ll operator+(const Edge&two) const {
        return weight + two.weight; 
    }
};


struct Node {
    ll index;
    ll weight;
    
    Node() : index(0), weight(0) {}
    Node(ll a, ll b) {
        index = a;
        weight = b;
    }

    bool operator<(const Node&two) const {
        return weight < two.weight;
    }
};