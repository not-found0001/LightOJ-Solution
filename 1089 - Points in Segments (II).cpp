#include <bits/stdc++.h>

using namespace std;

const int mxn = 2e5;

using pi = pair<int, int>;

int Tree[mxn];

void update(int pos, int val)
{
    while(pos < mxn){
        Tree[pos]+=val;
        pos+=(pos & -pos);
    }
}

int query(int pos)
{
    int sum = 0;
    while(pos){
        sum+=Tree[pos];
        pos-=(pos & -pos);
    }
    return sum;
}

int main()
{
    int tc, cs = 1;
    scanf("%d",&tc);
    while(tc--){
        memset(Tree, 0, sizeof  Tree);
        set<int>s;
        vector<pi>v;
        int p, q;
        scanf("%d%d",&p, &q);
        for(int i=1 ; i<=p ; i++){
            int x, y;
            scanf("%d%d",&x, &y);
            s.insert(x);
            s.insert(y);
            v.push_back({x, y});
        }

        vector<int>qr;
        for(int i=0 ; i<q ; i++){
            int x;
            scanf("%d",&x);
            s.insert(x);
            qr.push_back(x);
        }

        int idx = 1;
        map<int, int>id;
        for(auto X : s) id[X] = idx++;

        for(int i=0 ; i<p ; i++){
            int x = v[i].first;
            int y = v[i].second;
            x = id[x];
            y = id[y];
            update(x, 1);
            update(y+1, -1);
        }
        printf("Case %d:\n",cs++);
        for(int i=0 ; i<q ; i++){
            int x = qr[i];
            x = id[x];
            printf("%d\n",query(x));
        }
    }

    return 0;
}
