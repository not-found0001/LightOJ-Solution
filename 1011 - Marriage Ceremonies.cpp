#include <bits/stdc++.h>

using namespace std;

int n;
int arr[20][20];
int dp[17][1<<17];

int rec(int pos, int mask)
{
    if(mask == ((1<<n)-1)) return 0;
    int &ret = dp[pos][mask];
    if(ret != -1) return ret;
    ret = 0;
    for(int i=0 ; i<n ; i++){
        if((mask&(1<<i)) == 0){
            ret = max(ret, rec(pos+1, (mask|(1<<i)))+arr[pos][i]);
        }
    }
    return ret;
}

int main()
{
    int tc, cs = 1;
    scanf("%d",&tc);
    while(tc--){
        memset(dp, -1, sizeof dp);
        scanf("%d",&n);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                scanf("%d",&arr[i][j]);
            }
        }
        int Ans = rec(0, 0);
        printf("Case %d: %d\n",cs++, Ans);
    }

    return 0;
}
