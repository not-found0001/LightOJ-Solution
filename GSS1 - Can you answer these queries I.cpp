#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5+100;
int arr[mxn];

struct Node{
    long long sum, pref, suff, ans;
}Tree[4*mxn];

Node make_data(int val)
{
    Node res;
    res.sum = val;
    res.pref = res.suff = res.ans = val;
    return res;
}

Node combine(Node l, Node r)
{
    Node res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum+r.pref);
    res.suff = max(r.suff, r.sum+l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff+r.pref);
    return res;
}

void build(int nod, int b, int e)
{
    if(b == e){
        Tree[nod] = make_data(arr[b]);
        return ;
    }
    int mid = (b+e)>>1;
    int left = 2*nod;
    int right = 2*nod + 1;
    build(left, b, mid);
    build(right, mid+1, e);
    Tree[nod] = combine(Tree[left], Tree[right]);
}

Node query(int nod, int b, int e, int l, int r)
{
    if(e < l or r < b) return make_data(-1e14);
    if(e <= r and l <= b) return Tree[nod];
    int mid = (b+e)>>1;
    int left = 2*nod;
    int right = 2*nod + 1;
    Node q1 = query(left, b, mid, l, r);
    Node q2 = query(right, mid+1, e, l, r);
    return combine(q1, q2);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1 ; i<=n ; i++) scanf("%d",&arr[i]);
    build(1, 1, n);
    int q;
    scanf("%d",&q);
    while(q--){
        int l, r;
        scanf("%d%d",&l, &r);
        Node Ans = query(1, 1, n, l, r);
        printf("%lld\n",Ans.ans);
    }

    return 0;
}
