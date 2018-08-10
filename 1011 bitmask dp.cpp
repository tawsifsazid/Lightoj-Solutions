#include<bits/stdc++.h>
#define N 70000
# define ll long long
using namespace std;

ll res,ct,cases,n;
ll marriagecost[20][20],dp[20][70000];
///dir array for Queen int dxq[10] = {-1,-1,-1,1,1,1,0,0};
///dir array for Queen int dyq[10] = {-1,0,1,-1,0,1,-1,1};
///dir array for knight int dxk[10] = {-2,-2,-1,-1,1,1,2,2};
///dir array for knight int dyk[10] = {1,-1,-2,2,-2,2,-1,1};
/*int leap(int a){
    if(a%4==0){
        if(a%100==0){
            if(a%400==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}*/
ll trydp(ll man,ll mask){
    if(man == n)return 0;
    if(dp[man][mask] != -1)return dp[man][mask];
    ll res1=0,res2=0,j;
    for(j=0;j<n;j++){
        if(!(mask & (1 << j))){

            res1 =  marriagecost[man][j] + trydp(man+1,mask | (1 << j));
             //printf("if  %d %d = %d\n",man,mask,dp[man][mask]);
        }
         res2 =max(res1,res2);
         dp[man][mask] = res2;
         //printf("%d %d = %d\n",man,mask,dp[man][mask]);
    }
    //printf("baire %d %d = %d\n",man,mask,dp[man][mask]);
    return dp[man][mask]=res2;

}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%lld",&cases);
    while(cases--){
        ct++;
        scanf("%lld",&n);
        ll i,j,k;
        memset(dp , -1, sizeof dp);
        memset(marriagecost , 0 ,sizeof marriagecost);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%lld",&marriagecost[i][j]);
            }
        }
        printf("Case %lld: %lld\n",ct,trydp(0,0));
    }
}
