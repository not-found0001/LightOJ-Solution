#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5+100;

int arr[mxn];

struct Info{
    int sum, prop;
} Tree[4*mxn] ;

void build(int nod, int b, int e)
{
    if(b == e){
        Tree[nod].sum = arr[b];
        return ;
    }
    int mid = (b+e)>>1;
    int Left = 2*nod;
    int Right = 2*nod + 1;
    build(Left, b, mid);
    build(Right, mid+1, e);
    Tree[nod].sum = Tree[Left].sum + Tree[Right].sum;
}

void update(int nod, int b, int e, int i, int j, int val)
{
    if(i > e or j < b) return;
    if(b >= i and e <=j){
        Tree[nod].sum += ((e-b+1)*val);
        Tree[nod].prop += val;
        return ;
    }
    int mid = (b+e)>>1;
    int Left = 2*nod;
    int Right = 2*nod + 1;
    update(Left, b, mid, i, j, val);
    update(Right, mid+1, e, i, j, val);
    Tree[nod].sum = Tree[Left].sum + Tree[Right].sum + (Tree[nod].prop * (e-b+1));
}

int query(int nod, int b, int e, int i, int j, int carry = 0)
{
    if(i > e or j < b) return 0;
    if(b >= i and e <=j){
        return Tree[nod].sum + ((e-b+1) * carry);
    }
    int mid = (b+e)>>1;
    int Left = 2*nod;
    int Right = 2*nod + 1;
    int q1 = query(Left, b, mid, i, j, carry+Tree[nod].prop);
    int q2 = query(Right, mid+1, e, i, j, carry+Tree[nod].prop);
    return q1+q2;
}

int main()
{
    int tc, cs = 1;
    scanf("%d",&tc);
    while(tc--){
        for(int i=1 ; i<=4*mxn ; i++) Tree[i].sum = Tree[i].prop = 0;
        string str;
        cin>>str;
        int n = str.size();
        for(int i=1 ; i<=n ; i++) arr[i] = str[i-1] - '0';
        build(1, 1, n);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cs++);
        while(q--){
            char typ;
            cin>>typ;
            if(typ == 'I'){
                int l, r, x;
                scanf("%d%d",&l, &r);
                update(1, 1, n, l, r, 1);
            }
            else{
                int pos;
                scanf("%d",&pos);
                int Ans = query(1, 1, n, pos,pos);
                printf("%d\n",(Ans&1));
            }
        }
    }

    return 0;
}
