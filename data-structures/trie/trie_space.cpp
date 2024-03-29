// uses map for memory efficient tries
#include<bits/stdc++.h>
using namespace std;

class Trie {
public:
    void insert(string word)
    {
        Trie* node = this;
        for (char ch : word)
        {
            if (!node->next.count(ch)) node->next[ch] = new Trie();
            node = node->next[ch];
        }
        node->isword = true;
    }

    bool search(string word)
    {
        Trie* node = this;
        for (char ch : word)
        {
            if (!node->next.count(ch)) return false;
            node = node->next[ch];
        }
        return node->isword;
    }

    bool startsWith(string prefix)
    {
        Trie* node = this;
        for (char ch : prefix)
        {
            if (!node->next.count(ch)) return false;
            node = node->next[ch];
        }
        return true;
    }

private:
    map<char, Trie*> next = {};  // faster than unordered
    bool isword = false;
};