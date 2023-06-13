#include <bits/stdc++.h> 
using namespace std;
class Node{
public:
    int end,c;
    Node* a[26];
    Node()
    {
        end=c=0;
        for(int i=0;i<26;++i)
        a[i]=nullptr;
    }
};
class Trie{

    public:
    Node* root;
    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node* curr=root;
        for(auto x:word)
        {
            x-='a';
            if(!curr->a[x]) curr->a[x]=new Node();
            curr->c++;
            curr=curr->a[x];
        }
        curr->c++;
        curr->end++;
    }

    int countWordsEqualTo(string &word,bool prefix=0)
    {
        int ans=0;
        Node* curr=root;
        for(auto x:word)
        {
            x-='a';
            if(!curr->a[x]) return 0;
            curr=curr->a[x];
        }
        return prefix?curr->c:curr->end;
    }

    int countWordsStartingWith(string &word)
    {
        return countWordsEqualTo(word,1);
    }

    void erase(string &word)
    {
        Node* curr=root;
        for(auto x:word)
        {
            x-='a';
            curr->c--;
            curr=curr->a[x];
        }
        curr->c--;
        curr->end--;
    }
};
