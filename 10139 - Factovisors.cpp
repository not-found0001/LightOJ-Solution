#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5+10;
vector<long long>prime;
bool mark[mxn];

void sieve()
{
    for(int i=2 ; i<mxn ; i++){
        if(mark[i] == 0){
            prime.push_back(i);
            for(int j=i+i ; j<mxn ; j+=i) mark[j] = 1;
        }
    }
}

int main()
{
    sieve();
    int n, k, sz = prime.size();
    while(scanf("%d%d",&n, &k) != EOF){
            bool nd = 0;
            int kk = k;
            for(int i=0 ; i<sz and prime[i]*1LL*prime[i]<=k ; i++){
                if(k%prime[i] == 0){
                    int ct = 0;
                    while(k%prime[i] == 0){
                        ct++;
                        k/=prime[i];
                    }
                    int tmp = n, sum = 0;
                    while(tmp){
                        sum+=(tmp/prime[i]);
                        tmp/=prime[i];
                    }
                    if(sum < ct){
                        nd = 1;
                        break;
                    }
                }
            }
            if(k > 1){
                int tmp = n, sum = 0;
                while(tmp){
                    sum+=(tmp/k);
                    tmp/=k;
                    if(sum >= 1) break;
                }
                if(sum < 1) nd = 1;
            }
            if(nd) printf("%d does not divide %d!\n",kk, n);
            else printf("%d divides %d!\n",kk ,n);
    }
    return 0;
}
