#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5 + 100;
using pi = pair<int, int>;

int arr[mxn];
int n;
pi Tree[4*mxn];

pi maxmin(pi a, pi b)
{
    return {(max(a.first, b.first)), (min(a.second, b.second))};
}

void build(int nod, int b, int e)
{
    if(b == e){
        Tree[nod] = {arr[b], arr[b]};
        return;
    }
    int mid = (b+e)>>1;
    int Left = 2*nod;
    int Right = 2*nod + 1;
    build(Left, b, mid);
    build(Right, mid+1, e);
    Tree[nod] = maxmin(Tree[Left], Tree[Right]);
}

pi query(int nod, int b, int e, int l, int r)
{
    if(b > r or e < l) return {INT_MIN, INT_MAX};
    if(b >= l and e<=r) return Tree[nod];
    int mid = (b+e)>>1;
    int Left = 2*nod;
    int Right = 2*nod + 1;
    pi q1 = query(Left, b, mid, l, r);
    pi q2 = query(Right, mid+1, e, l, r);
    return maxmin(q1, q2);
}

int main()
{
    int tc, cs = 1;
    scanf("%d",&tc);
    while(tc--){
        int d;
        scanf("%d%d",&n, &d);
        for(int i=1 ; i<=n ; i++) scanf("%d",&arr[i]);
        build(1, 1, n);
        int mx = 0;
        for(int i=d ; i<=n ; i++){
            pi Ans = query(1, 1, n, i-d+1, i);
            mx = max(mx, Ans.first-Ans.second);
        }
        printf("Case %d: %d\n",cs++, mx);
    }

    return 0;
}
