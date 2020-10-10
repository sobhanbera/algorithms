#include <bits/stdc++.h>
using namespace std;
struct Trie
{
    Trie *nghbr[26];
    bool end;
    Trie()
    {
        for (int i = 0; i < 26; ++i)
            nghbr[i] = NULL;

        end = false;
    };
    void insert(string s)
    {
        Trie *cur = this;
        int idx;
        for (char X : s)
        {
            idx = X - 'a';
            if (cur->nghbr[idx] == NULL)
            {
                cur->nghbr[idx] = new Trie();
            }
            cur = cur->nghbr[idx];
        };
        cur->end = true;
    }
    bool search(string k)
    {
        Trie *cur = this;
        int idx;

        for (char X : k)
        {
            idx = X - 'a';
            if (cur->nghbr[idx] == NULL)
                return false;
            cur = cur->nghbr[idx];
        }

        return cur->end;
    };
};
int main()
{
    vector<string> A, toSearch;
    A = {"apple", "water", "bat", "app", "ball"};
    toSearch = {"ball", "watch", "water", "watep", "apz", "app"};
    Trie *trie = new Trie();
    for (string s : A)
        trie->insert(s);
    vector<string> ans;

    for (string s : toSearch)
    {

        cout << "\n\t" << s << '\t';
        if (trie->search(s))
            cout << "FOUND";
        else
        {
            cout << "NOT FOUND";
        }
    }
    cout<<"\n\n";
    return 0;
}
