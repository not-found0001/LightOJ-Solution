#include <bits/stdc++.h>

using namespace std;

long long dp[35][35];

long long rec(long long n, long long r)
{
    if(n == r) return 1LL;
    else if(r == 1) return n*1LL;
    long long &ret = dp[n][r];
    if(ret != -1) return ret;
    return ret = rec(n-1, r) + rec(n-1, r-1);
}

int main()
{
    int tc, cs = 1;
    scanf("%d",&tc);
    while(tc--){
        int n, k;
        scanf("%d%d",&n, &k);
        printf("Case %d: ",cs++);
        if(n < k) printf("0\n");
        else if(k == 0) printf("1\n");
        else{
            memset(dp, -1, sizeof dp);
            long long s = 1;
            for(long long i=n-k+1 ; i<=n ; i++) s*=i;
            long long Ans = rec(n, k) * s;
            printf("%lld\n", Ans);
        }
    }

    return 0;
}
