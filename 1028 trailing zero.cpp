#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define pare pair<int,int>
using namespace std;

ll ct=0,cases,n,k,h;
///dir array for Queen int dxq[10] = {-1,-1,-1,1,1,1,0,0};
///dir array for Queen int dyq[10] = {-1,0,1,-1,0,1,-1,1};
///dir array for knight int dxk[10] = {-2,-2,-1,-1,1,1,2,2};
///dir array for knight int dyk[10] = {1,-1,-2,2,-2,2,-1,1};
/*int leap(int year){
   	if( year%4 == 0 && year%100 == !0 )
            return 1;
	else if (year%100 == 0 && year%400 == 0)
            return 1;
	else
        return 0;
}*/
ll flag[2000006];
vector<ll>P;
void sieve(){
    ll i,j,k;
    memset(flag,-1,sizeof flag);
    P.push_back(2);
    for(i=3;i<=1000007;i=i+2){
        if(flag[i] == -1){
            P.push_back(i);
            //cout<<i<<endl;
        }
        if(flag[i] == -1){
            for(j=i*i;j<=1000007;j = i + j){
                flag[j] = 0;
            }
        }
    }

}
ll nod(ll num){
    ll p = 0,sq = sqrt(num),ans = 1;
    for(int i=0;i<P.size() && P[i]<=sq ;i++){
        p = 0;
        if(num % P[i] == 0){
            while(num % P[i] == 0){
                num = num / P[i];
                p++;
            }
            sq = sqrt(num);
            p++;
            ans = ans * p;
        }
    }
    if(num != 1){

        ans = ans * 2;

    }
    return ans;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    sieve();
    scanf("%lld",&cases);
    while(cases--){
        ct++;

        scanf("%lld",&n);
        ll ans = nod(n);
        printf("Case %lld: %lld\n",ct,ans-1);
    }

}
