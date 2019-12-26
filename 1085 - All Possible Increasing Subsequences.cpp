#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
const int Mod = 1e9+7;
int Tree[4*100005];

vector<pi>v;

bool cmp(pi a, pi b)
{
    if(a.first < b.first) return true;
    else if(a.first == b.first and a.second > b.second) return true;
    else return false;
}

int query(int pos)
{
    long long Ans = 0;
    while(pos > 0){
        Ans+=Tree[pos];
        Ans%=Mod;
        pos-=(pos & -pos);
    }
    return (int)Ans;
}

void update(int pos, int val)
{
    while(pos <= 1e5){
        Tree[pos] = ((Tree[pos]%Mod) + (val%Mod)) % Mod;
        pos+=(pos & -pos);
    }
}

int main()
{
    int tc, cs = 1;
    scanf("%d",&tc);
    while(tc--){
        memset(Tree, 0, sizeof Tree);
        int n;
        scanf("%d",&n);
        for(int i=1 ; i<=n ; i++){
            int x;
            scanf("%d",&x);
            v.push_back({x, i});
        }
        sort(v.begin(), v.end(), cmp);
        for(int i=0 ; i<n ; i++){
            int sum = 1 + query(v[i].second-1);
            update(v[i].second, sum);
        }
        printf("Case %d: %d\n",cs++, query(n));
        v.clear();
    }
    return 0;
}
