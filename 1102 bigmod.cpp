#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007
using namespace std;

ll ct=0,cases,n,k,A[2000009];
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
ll bigmod(ll base,ll power , ll m){
    if(power == 0){
        return 1%m;
    }
    else if(power % 2 == 0){
        ll a = bigmod(base,power/2,m)%m;
        return ((a % m) * (a % m))%m;
    }
    else{
        return (((base)%m)*(bigmod(base,power-1,m)%m))%m;
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
         A[1] = 1;
            A[0] = 1;
            for(ll i=2;i<=2000007;i++){
                A[i] = (A[i-1]*i)%mod;
            }
        scanf("%lld",&cases);
        while(cases--){
            ll i,j,k,ans = 1;
            ct++;
            scanf("%lld %lld",&n,&k);

            //cout<<n<<" "<<k<<endl;

            ans = (ans * A[n+k-1])%mod;
            //cout<<"ans "<<ans<<endl;
            ll now = 1;
            now = (now * A[n])%mod;
            now = (now*A[k-1])%mod;
            //cout<<" now "<<now<<endl;
            //cout<<now<<endl;
            ll a1 = bigmod(now,mod-2,mod);
            //ll a2 = bigmod(k-1,mod -2,mod)%mod;
            //cout<<a1<<endl;
            ans = (ans * a1)%mod;
            printf("Case %lld: %lld\n",ct,ans);
        }



}
