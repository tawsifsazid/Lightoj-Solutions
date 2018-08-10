#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define pare pair<int,int>
#define mod 1000000007
using namespace std;

ll ct=0,cases,k,h;
ll n,m;
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
vector<ll>P;
ll flag[100007];
void sieve(){
    P.push_back(2);
    ll i,j,k;
    memset(flag,-1,sizeof flag);
    for(i=3;i<=70000;i=i+2){
        if(flag[i]== -1){
            P.push_back(i);
            //cout<<i<<endl;
        }
        if(flag[i]==-1){
            for(j=i*i;j<=70000;j=j+i){
                flag[j]=0;
            }
        }
    }
}
ll bigmod(ll b,ll p,ll g){
    if(p == 0)return 1%g;
    if(p % 2 == 0){
        ll ans = bigmod(b,p/2,g);
        return ((ans%g)*(ans%g))%g;
    }
    else{
        return ((b%g)*(bigmod(b,p-1,g))%g)%g;
    }
}
ll fact(ll a,ll b){
    ll i,j,k,power,sq = a;
    ll res = 1;
    for(i=0;i<P.size() && P[i]<=sq;i++){
        power = 0;
        if(a % P[i] == 0){
            while(a % P[i] == 0){
                a = a/P[i];
                power++;
            }
            power = power*b;
            ll ans = bigmod(P[i],power+1,mod)-1;
            ll ans1 = bigmod(P[i]-1,mod-2,mod);
            res = res*(((ans%mod)*(ans1%mod))%mod);
            res = res % mod;
        }
    }
    if(a > 1){
        power = b;
        ll ans = bigmod(a,power+1,mod)-1;
        //cout<<ans<<endl;
        ll ans1 = bigmod(a-1,mod-2,mod);
        //cout<<ans<<" "<<ans1<<endl;
        res = res*(((ans%mod)*(ans1%mod))%mod);
        res = res % mod;
    }
    if(res<0)res =res + mod;
    return res;

}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    sieve();
    scanf("%lld",&cases);
    while(cases--){
        ct++;
        scanf("%lld %lld",&n,&m);
        ll res = fact(n,m);
        printf("Case %lld: %lld\n",ct,res);
    }

}
