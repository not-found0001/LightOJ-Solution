#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e3+100;
int Tree[mxn][mxn], visit[mxn][mxn];

void update(int x, int y, int val)
{
    for(int i=x ; i<mxn ; i+=(i & -i)){
        for(int j=y ; j<mxn ; j+=(j & -j)){
            Tree[i][j]+=val;
        }
    }
}

int query(int x, int y)
{
    int Ans = 0;
    for(int i=x ; i>0 ; i-=(i & (-i))){
        for(int j=y ; j>0 ; j-=(j & (-j))){
            Ans+=Tree[i][j];
        }
    }
    return Ans;
}

int main()
{
    int tc, cs = 1;
    scanf("%d",&tc);
    while(tc--){
        memset(Tree, 0, sizeof Tree);
        memset(visit, 0, sizeof visit);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",cs++);
        while(q--){
            int typ;
            scanf("%d",&typ);
            if(typ == 0){
                    int x1, y1;
                    scanf("%d%d",&x1, &y1);
                    x1+=2, y1+=2;
                    if(!visit[x1][y1]){
                        update(x1, y1, 1);
                        visit[x1][y1] = 1;
                    }
            }
            else{
                int x1, y1, x2, y2;
                scanf("%d%d%d%d",&x1,&y1,&x2, &y2);
                x1+=2, y1+=2, x2+=2, y2+=2;
                int Ans = query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1);
                printf("%d\n", Ans);
            }
        }
    }

    return 0;
}

