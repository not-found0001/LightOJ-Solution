#include <bits/stdc++.h>

using namespace std;

set<string>Ans;

struct Trie{
    int endMark, val;
    Trie* next[28];
    Trie(int _val){
        for(int i=0 ; i<26 ; i++) next[i] = NULL;
        endMark = 0;
        val = _val;
    }
};

void Insert(Trie* cur, string str)
{
    int sz = str.size();
    for(int i=0 ; i<sz ; i++){
        int ch = (int) (str[i]-'a');
        if(cur->next[ch] == NULL) cur->next[ch] = new Trie(ch);
        cur = cur->next[ch];
    }
    cur->endMark = 1;
}

char get(int x)
{
    for(char ch = 'a' ; ch<='z' ; ch++){
        int tmp = (int) (ch-'a');
        if(tmp == x) return ch;
    }
}

void DFS(Trie* cur, string str, int sz)
{
    if(cur->endMark){
            string res = str+get(cur->val);
            if(res.size() > sz) Ans.insert(res);
    }
    for(int i=0 ; i<26 ; i++) if(cur->next[i]) DFS(cur->next[i], (str+get(cur->val)), sz);
}

int main()
{
    Trie* root = new Trie(-1);
    int n, cs = 1;
    scanf("%d",&n);
    while(n--){
        string str;
        cin>>str;
        Insert(root, str);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        string str;
        cin>>str;
        int sz = str.size();
        bool flag = 0;
        Trie* cur = root;
        int ch;
        for(int i=0 ; i<sz ; i++){
            ch = (int) (str[i]-'a');
            if(cur->next[ch]) cur = cur->next[ch];
            else{
                flag = 1;
                break;
            }
        }
        printf("Case #%d:\n",cs++);
        if(flag) puts("No match.");
        else{
            str.pop_back();
            DFS(cur, str, sz);
            for(auto X : Ans) cout<<X<<endl;
            Ans.clear();
        }
    }

    return 0;
}
