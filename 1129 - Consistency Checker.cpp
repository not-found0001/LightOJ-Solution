#include <bits/stdc++.h>

using namespace std;

struct Trie{
    Trie* next[10];
    int endMark;

    Trie(){
        endMark = 0;
        for(int i=0 ; i<10 ; i++) next[i] = NULL;
    }
};

bool Insert(string str, Trie* cur)
{
    int sz = str.size();
    for(int i=0 ; i<sz ; i++){
        int n = str[i] - '0';
        if(cur->next[n] == NULL) cur->next[n] = new Trie();
        if(cur->endMark) return 1;
        cur = cur->next[n];
    }
    cur->endMark = 1;
    return 0;
}

void del(Trie* tmp)
{
    for(int i=0 ; i<10 ; i++){
        if(tmp->next[i]) del(tmp->next[i]);
    }
    delete(tmp);
}

int main()
{
    int tc, cs = 1;
    scanf("%d",&tc);
    while(tc--){
        Trie* Head = new Trie();
        int n;
        scanf("%d",&n);
        vector<string>v;
        while(n--){
            string str;
            cin>>str;
            v.push_back(str);
        }
        sort(v.begin(), v.end());
        bool ok = 0;
        for(auto X : v){
            ok |= Insert(X, Head);
            if(ok) break;
        }
        printf("Case %d: ",cs++);
        (ok) ? puts("NO") : puts("YES") ;
        del(Head);
    }

    return 0;
}
