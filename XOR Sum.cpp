
///  XOR Of F(l, r) = (F(1, l-1) xor F(1, r))
///  Insert -> calculate prefix xor and stor every prefix xor into leaf node
///  MaxXOR -> try to go opposite bit

#include <bits/stdc++.h>

using namespace std;

struct Trie{
        int val;
        Trie* next[2];
        Trie(){
            val = 0;
            next[0] = next[1] = NULL;
        }
};

void Insert(Trie* cur, int x)
{
    for(int i=31 ; i>=0 ; i--){
        int bit = (bool) (x&(1LL<<i));
        if(cur->next[bit] == NULL) cur->next[bit] = new Trie();
        cur = cur->next[bit];
    }
    cur->val = x;
}

long long Find_MaxXOR(Trie* cur, int x)
{
    for(int i=31 ; i>=0 ; i--){
        int bit = (bool) (x&(1LL<<i));
        if(cur->next[bit^1]) cur = cur->next[bit^1];
        else cur = cur->next[bit];
    }
    return (x^cur->val);
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
        int n;
        scanf("%d",&n);
        Trie* root = new Trie();
        Insert(root, 0);
        int prefixXOR = 0;
        long long Ans = 0;
        for(int i=0 ; i<n ; i++){
            int x;
            scanf("%d",&x);
            prefixXOR ^= x;
            Insert(root, prefixXOR);
            long long tmp = Find_MaxXOR(root, prefixXOR);
            Ans = max(Ans, tmp);
        }
        printf("%lld\n",Ans);
        del(root);
    }
    return 0;
}
