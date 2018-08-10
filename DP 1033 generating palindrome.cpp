#include<bits/stdc++.h>
#define N 1005

using namespace std;
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
string a;
int res,ct = 0,cases,n;
int dp[305][305];
int  trydp(int i,int j){
    if(i>j)return 0;
     int t1=0,t2=0,result = 0;
    if(a[i] == a[j])result = result + trydp(i+1,j-1);
    if(dp[i][j] != -1)return dp[i][j];
    if(a[i] != a[j]){
        t1 = t1 + 1 + trydp(i+1,j);
        //printf("t1 = %d\n",t1);
        t2 = t2 + 1 + trydp(i,j-1);
        //printf("t2 = %d\n",t2);
         result = min(t1,t2);
    }
    //printf("%d %d = %d %d\n",i,j,t1,t2);
     dp[i][j] = result;
     return  dp[i][j] ;

}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
     scanf("%d",&cases);
     while(cases--){
        ct++;
        memset(dp , -1, sizeof dp);
        cin>>a;
        int len = a.size();
        printf("Case %d: %d\n",ct,trydp(0,len-1));
     }
}
