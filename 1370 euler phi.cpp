#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define pare pair<int,int>
using namespace std;
ll ct=0,cases,n,k,h,flag[2000000];
vector<ll>P;
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
void sieve(){
    ll i,j,k;
    memset(flag,-1,sizeof flag);
    P.push_back(2);
    for(i=3;i<=1000006;i=i+2){
        if(flag[i] == -1){
            P.push_back(i);
        }
        if(flag[i] == -1){
           for(j=i*i;j<=1000006;j=j+i){
                flag[j] = 1;
           }
        }
    }
}
int eulerphi(int num){

    ll i,j,k,ans = num,sq = sqrt(num);
   if(num == 1)return 0;

    for(i=0;i<P.size() && P[i]<=sq;i++){
        if(num % P[i] == 0){
            while(num % P[i] == 0){
                num = num/P[i];
            }
            ans = ans / P [i];
            ans = ans*(P[i] - 1);
            sq = sqrt(sq);
        }
    }
    if(num != 1){
        ans = ans/num;
        ans = ans*(num - 1);
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
        ll i,j,k,res = 0;
        for(i=1;i<=n;i++){
            scanf("%lld",&k);
            for(j=k;j<=k + 1000;j++){
                   int ans = eulerphi(j);

                if(ans>=k){
                  // cout << "euler "<<ans << " of "<<j<<endl;
                   res = res + j;
                   break;
                }
            }
        }
        printf("Case %lld: %lld Xukha\n",ct,res);
    }

}
