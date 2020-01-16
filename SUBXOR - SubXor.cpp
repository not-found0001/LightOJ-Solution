#include <bits/stdc++.h>

using namespace std;

int n, k;

struct Trie{
    int cnt;
    Trie* next[2];
    Trie(){
        cnt = 0;
        next[0] = next[1] = NULL;
    }
};

void Insert(Trie* cur, int pre_xor)
{
    for(int i=20 ; i>=0 ; i--){
        int bit = (bool) (pre_xor&(1<<i));
        if(cur->next[bit] == NULL) cur->next[bit] = new Trie();
        cur = cur->next[bit];
        cur->cnt++;
    }
}

int get(Trie* cur)
{
    return (cur) ? cur->cnt : 0;
}

int Find_Max(Trie* cur, int pre_xor)
{
    int res = 0;
    for(int i=20 ; i>=0 ; i--){
        if(cur == NULL) break;
        int pre_bit = (bool) (pre_xor&(1<<i));
        int bit = (bool) (k&(1<<i));
        if(bit == pre_bit){
            if(pre_bit) res+=get(cur->next[1]);
            cur = cur->next[0];
        }
        else{
            if(!pre_bit) res+=get(cur->next[0]);
            cur = cur->next[1];
        }
    }
    return res;
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
        Trie* root = new Trie();
        scanf("%d%d",&n, &k);
        int pre_xor = 0;
        Insert(root, pre_xor);
        long long Ans = 0;
        for(int i=0 ; i<n ; i++){
            int x;
            scanf("%d",&x);
            pre_xor^=x;
            int res = Find_Max(root, pre_xor);
            Ans += res;
            Insert(root, pre_xor);
        }
        printf("%lld\n",Ans);
        del(root);
    }

    return 0;
}
