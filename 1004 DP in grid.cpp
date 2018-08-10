#include<bits/stdc++.h>
#define N 300
#define ll long long
#define inf 1
using namespace std;

ll ct=0,cases,n,m,fl;
ll dp[N][N];
ll A[N][N];
ll trydp(ll i,ll j){
    if(A[i][j]==-1)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    if(i<n && i>=1){
        ll t1=0 , t2= 0;
        t2 = trydp(i+1,j) + A[i][j];
        t1 = trydp(i+1,j+1) + A[i][j];
        dp[i][j] = max(t1,t2);
        //printf("%lld %lld = %lld\n",i,j,dp[i][j]);
        return dp[i][j];
    }
    //if(i<=((2*n)-1) && i > n){
    else{
           // printf("shuru\n");
        ll t1= 0 ,t2= 0;
        t1 =  trydp(i+1,j) + A[i][j];
        t2 =  trydp(i+1,j-1) + A[i][j];
        dp[i][j] = max(t1,t2);
        // printf("%lld %lld = %lld\n",i,j,dp[i][j]);
        return dp[i][j];
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%lld",&cases);
    ll res;
    while(cases--){
          ct++;
          fl = 1;
         ll i,j;
        scanf("%lld",&n);
        memset(A , -1 ,sizeof A);
        memset(dp ,  -1 ,sizeof dp);
        for(i=1;i<=n;i++){
            for(j=1;j<=i;j++){
                scanf("%lld",&A[i][j]);
            }
        }
        ll hoy = n-1;
        for(i=i; i<=(2*n)-1 ;i++){
            for(j=1;j<=hoy && hoy>=1;j++){
                scanf("%lld",&A[i][j]);
                //printf("%lld %lld = %lld\n",i,j,A[i][j]);
            }
            hoy--;
        }
        res = -1;
        res = trydp(1,1);
       // printf("%lld\n",dp[1][1]);
      printf("Case %lld: %lld\n",ct,res);
    }
}
