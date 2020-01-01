#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e6;
const double gama = 0.57721566490;

double Ans[mxn+5];

int main()
{
    Ans[1] = 1.0;
    for(int i=2 ; i<=mxn ; i++) Ans[i] = Ans[i-1] + (1.0/i);
    int tc, cs = 1;
    scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);
        if(n <= mxn) printf("Case %d: %.6lf\n",cs++, Ans[n]);
        else{
            double res = log(n+.5) + gama;
            printf("Case %d: %.9lf\n",cs++, res);
        }
    }
    return 0;
}
