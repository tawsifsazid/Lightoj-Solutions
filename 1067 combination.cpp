#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000003
using namespace std;

ll ct=0,cases,n,k;
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
ll A[2000009];
ll bigmod(ll base,ll power,ll m){
    if(power == 0){
        return 1;
    }
    else if(power % 2 == 0){
        ll a = bigmod(base,power/2,m)% m;
        return ((a % m)*(a % m))%m;
    }
    else{
        return ((base % m)*(bigmod(base,power - 1, m)% m) ) % m;
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    A[0] = 1;
    A[1] = 1;
    ll i,j,k;
    for(i=2;i<=2000001;i++){
        A[i] = (A[i-1] * i) % mod;
    }
    scanf("%lld",&cases);
    while(cases--){
        ct++;
        scanf("%lld %lld",&n,&k);
        ll ans = 1;
        ans = (ans * A[n]) % mod;
        ll a1 =1, a2 = 1;
        a1 = (a1 * A[k]) % mod;
        a2 = (a2 * A[n - k]) % mod;
        ll now = ((a1 % mod) * (a2 % mod))%mod;
        now = bigmod(now,mod - 2,mod);
        ans = (ans * now)%mod;
        printf("Case %lld: %lld\n",ct,ans);
    }


}
