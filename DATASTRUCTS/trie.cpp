#ifndef SNIPPETS_HPP
#include "../snippets.hpp"
#endif

/* A trie. */

struct Trie {
    Trie *child[26];
    bool isLeaf;

    Trie() {
        isLeaf = 0;
        for(auto &x : child) x = nullptr;
    }

    void insert(const str &key, ll at = 0) {
        if(at >= key.length()) {
            isLeaf = 1;
            return;
        } 

        char c = key[at];
        if(not child[c-'a']) {
            child[c-'a'] = new Trie();
        }
        child[c-'a']->insert(key,at+1);
    }

    bool search(const str &key, ll at = 0) {
        if(at == key.length()) return isLeaf;

        char c = key[at];
        if(not child[c-'a']) return false;
        return child[c-'a']->search(key,at+1);
    }

    bool searchPrefix(const str &key, ll at = 0) {
        if(at == key.length()) return true;

        char c = key[at];
        if(not child[c-'a']) return false;
        return child[c-'a']->searchPrefix(key,at+1);
    }

    ~Trie() {
        for(int i = 0; i < 26; i++) {
            if(child[i]) {
                delete child[i];
                child[i] = nullptr;
            }
        }
    }
};