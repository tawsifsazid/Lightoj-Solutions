#include<bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;

ll ct=0,cases,n,k;
ll dp[50][910];
ll trydp(ll board, ll rooknumber){
    if(rooknumber ==0) return dp[board][rooknumber] = 1;
    if(board < rooknumber) return 0;
    if(dp[board][rooknumber]!=-1)return dp[board][rooknumber];
    dp[board] [rooknumber] = ((board*board)*trydp(board - 1,rooknumber -1))/rooknumber;
    //printf("board*board = %lld k= %lld dp =%lld\n",board*board,rooknumber,dp[board][rooknumber]);
    return dp[board][rooknumber];
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%lld",&cases);
    while(cases--){
        ct++;
        memset(dp , -1,sizeof dp);
        ll i,j;
        scanf("%lld %lld",&n,&k);
        printf("Case %lld: %lld\n",ct,trydp(n,k));
    }
}
