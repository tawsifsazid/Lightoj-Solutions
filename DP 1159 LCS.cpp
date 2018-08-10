#include<bits/stdc++.h>
#define N 55
#define ll long long
using namespace std;

int res,ct=0,cases,n,len1,len2,len3;
string a,b,c;
int dp[N][N][N];
int  trydp(int i, int j, int k){
    if(i==len1 || j == len2 || k == len3) return 0;
    if(dp[i][j][k] != -1)return dp[i][j][k];
     int res1=0,res2=0,res3=0,RES = 0;;
     if(a[i]==b[j] && b[j]==c[k]) RES = RES + 1 + trydp(i+1,j+1,k+1);
     else{
        res1 =res1 + trydp(i+1,j,k);
        res2 = res2 + trydp(i,j+1,k);
        res3 = res + trydp(i,j,k+1);
         RES =  max(res1,max(res2,res3));
    }
     dp[i][j][k] = RES;
     //printf("%d %d %d = %d\n",i,j,k,RES);
     return dp[i][j][k];

}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        cin>>a>>b>>c;
        memset(dp , -1, sizeof dp);
        len1 = a.size();
        len2 = b.size();
        len3 = c.size();
        printf("Case %d: %d\n",ct,trydp(0,0,0));
    }
}
