#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define pare pair<int,int>
using namespace std;

int ct=0,cases,n,len1,len2,dp[105][105];
string ans[105][105],a,b;
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
void trydp(){
    int i,j,k;
    for(i=1;i<=len1;i++){
        for(j=1;j<=len2;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                ans[i][j] = ans[i-1][j-1] + a[i-1];
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                    ans[i][j] = ans[i-1][j];
                }
                else if(dp[i-1][j] < dp[i][j-1]){
                    dp[i][j] = dp[i][j-1];
                    ans[i][j] = ans[i][j-1];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                    ans[i][j] = min(ans[i-1][j],ans[i][j-1]);
                }
            }
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>cases;
    while(cases--){
        ct++;
        int i,j,k;
        memset(dp,0,sizeof dp);
        for(i=0;i<=100;i++){
            for(j=0;j<=100;j++){
                ans[i][j] = "";
            }
        }

        cin>>a;
        cin>>b;
        len1 = a.size();
        len2 = b.size();
        trydp();
        printf("Case %d: ",ct);
        if(dp[len1][len2] == 0){
            printf(":(\n");
        }
        else{
           cout<<ans[len1][len2]<<endl;
        }

    }
}
