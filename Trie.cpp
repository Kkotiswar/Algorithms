#include <bits/stdc++.h>

using namespace std;

class Trie {
    struct Node{
        struct Node *children[26];
        bool isWord = false;
    }
public:
    Node *root;
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *curr = root; 
        for(auto x:word) {
            if(curr->children[x-'a'] == nullptr)curr->children[x-'a'] = new Node();
            curr = curr->children[x-'a'];
        }
        return curr->isWord = true;
    }

    bool search(string word) {
        Node *curr = root; 
        for(auto x: word ) {
            if(curr->children[x-'a'] == nullptr)return false;
            curr = curr->children[x-'a'];
        }
        return curr->isWord;
    }

    bool startsWith(string word) {
        Node curr = root;
        for(auto x:word) {
            if(curr->children[x-'a'] == nullptr)return false;
            curr = curr -> children[x-'a'];
        }
        return true;
    }
};