// custom trie node
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    TrieNode* a[26];
    bool end;
    TrieNode(int size=26)
    {
        end=0;
        for(int i=0;i<size;++i)
        a[i]=nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie()
    {
       root=new TrieNode();
    }
    
    void insert(string word)
    {
        TrieNode* curr=root;
        for(auto x:word)
        {
            x-='a';
            if(!curr->a[x]) curr->a[x] = new TrieNode(); 
            curr=curr->a[x];
        }
        curr->end=1;
    }
    
    bool search(string word,bool prefix=0)
    {
        TrieNode* curr=root;
        for(auto x:word)
        {
            x-='a';
            if(!curr->a[x]) 
            return false; 
            curr=curr->a[x];
        }
        return prefix?true:curr->end;
    }
    
    bool startsWith(string prefix)
    {
        return search(prefix,1);   
    }
};