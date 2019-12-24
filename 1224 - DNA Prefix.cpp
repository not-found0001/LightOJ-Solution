#include <bits/stdc++.h>

using namespace std;

int Ans = 0;

struct Trie{
    Trie* next[4];
    int cnt;
    Trie(){
        for(int i=0 ; i<4 ; i++) next[i] = NULL;
        cnt = 0;
    }
};

int get(char ch)
{
    if(ch == 'A') return 0;
    if(ch == 'C') return 1;
    if(ch == 'G') return 2;
    if(ch == 'T') return 3;
}

void Insert(string str, Trie* cur)
{
    int sz = str.size();
    for(int i=0 ; i<sz ; i++){
        int ele = get(str[i]);
        if(cur->next[ele] == NULL) cur->next[ele] = new Trie();
        cur = cur->next[ele];
        cur->cnt++;
    }
}

void DFS(Trie* cur, int level)
{
    int calc = cur->cnt * level;
    if(calc > Ans) Ans = calc;
    for(int i=0 ; i<4 ; i++){
        if(cur->next[i]) DFS(cur->next[i], level+1);
    }
}

void del(Trie* cur)
{
    for(int i=0 ; i<4 ; i++) if(cur->next[i]) del(cur->next[i]);
    delete(cur);
}

int main()
{
    int tc, cs = 1;
    scanf("%d",&tc);
    while(tc--){
        Trie* Head = new Trie();
        int n;
        scanf("%d",&n);
        while(n--){
            string str;
            cin>>str;
            Insert(str, Head);
        }
        DFS(Head, 0);
        printf("Case %d: %d\n",cs++, Ans);
        Ans = 0;
    }

    return 0;
}
