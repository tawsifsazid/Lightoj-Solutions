#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007

ll ct=0,cases,n;
ll dp[1005],A[1005][1005];
using namespace std;

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
void nck(){
    ll i,j,k;
    for(i=0;i<=1000;i++){
        for(j=0;j<=i;j++){
            if(j == 0 || i == j){
                A[i][j] = 1;
            }
            else A[i][j] = (A[i-1][j] + A[i-1][j-1])%10056;
        }
    }
}
void trydp(){
    ll i,j,k;
    dp[0] = 1;
    for(i=1;i<=1000;i++){
        for(k=1;k<=i;k++){
            dp[i] =(dp[i] + (dp[i-k]*A[i][k]))%10056;

        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    nck();
    trydp();
    scanf("%lld",&cases);
    while(cases--){
            scanf("%lld",&n);
         //   memset(dp,-1,sizeof dp);
        //printf("%lld\n",trydp(1,1));
        ct++;
        ll k,i;
        printf("Case %lld: %lld\n",ct,dp[n]%10056);


    }

}
