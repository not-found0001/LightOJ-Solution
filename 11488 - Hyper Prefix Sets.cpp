#include <bits/stdc++.h>

using namespace std;

int mx = 0;

struct Trie{
    int cnt;
    Trie* next[2];
    Trie(){
        cnt = 0;
        next[0] = next[1] = NULL;
    }
};

void Insert(Trie* cur, string str)
{
    int sz = str.size();
    for(int i=0 ; i<sz ; i++) {
        if(cur->next[str[i]-'0'] == NULL) cur->next[str[i]-'0'] = new Trie();
        cur = cur->next[str[i]-'0'];
        cur->cnt++;
    }
}

void Find_Max(Trie* cur, int level)
{
    mx = max(mx, cur->cnt*level);
    for(int i=0 ; i<2 ; i++) if(cur->next[i]) Find_Max(cur->next[i], level+1);
}

void del(Trie* cur)
{
    for(int i=0 ; i<2 ; i++) if(cur->next[i]) del(cur->next[i]);
    delete(cur);
}

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        mx = 0;
        int n;
        scanf("%d",&n);
        Trie* head = new Trie();
        while(n--){
            string str;
            cin>>str;
            Insert(head, str);
        }
        Find_Max(head, 0);
        printf("%d\n", mx);
        del(head);
    }
    return 0;
}
