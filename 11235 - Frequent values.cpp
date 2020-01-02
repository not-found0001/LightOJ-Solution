#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5+100;

int Tree[4*mxn], Left[mxn], Right[mxn], arr[mxn];

void build(int nod, int b, int e)
{
    if(b == e){
        Tree[nod] = Left[b];
        return ;
    }
    int mid = (b+e)>>1;
    int left = 2*nod;
    int right = 2*nod + 1;
    build(left, b, mid);
    build(right, mid+1, e);
    Tree[nod] = max(Tree[left], Tree[right]);
}

int query(int nod, int b, int e, int l, int r)
{
    if (l > e or r < b) return INT_MIN;
    if (b >= l && e <= r) return Tree[nod];
    int mid = (b+e)>>1;
    int left = 2*nod;
    int right = 2*nod + 1;
    int q1 = query(left, b, mid, l , r);
    int q2 = query(right, mid+1, e, l , r);
    return max(q1, q2);
}

int main()
{
    while(1){
         int n;
        scanf("%d",&n);
        if(!n) return 0;
        int q;
        scanf("%d",&q);
        for(int i=1 ; i<=n ; i++) scanf("%d",&arr[i]);
        Left[1] = 1;
        for(int i=2 ; i<=n ; i++){
            if(arr[i-1] == arr[i]) Left[i] = Left[i-1] + 1;
            else Left[i] = 1;
        }
        Right[n] = 1;
        for(int i=n-1 ; i>=1 ; i--){
            if(arr[i+1] == arr[i]) Right[i] = Right[i+1] + 1;
            else Right[i] = 1;
        }
        build(1, 1, n);
        while(q--){
                int l, r;
                scanf("%d%d",&l, &r);
                int Ans;
                if(arr[l] == arr[r]) Ans = r-l+1;
                else Ans = max(Right[l], query(1, 1, n, l+Right[l], r));
                printf("%d\n",Ans);
        }
    }

    return 0;
}
