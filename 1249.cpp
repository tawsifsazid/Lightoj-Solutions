#include<bits/stdc++.h>
#define N 1005
#define  ll long long
using namespace std;

int ct=0,cases,n;
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
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        int i,j,a,b,c;
        string A[105];
        int C[105];
        scanf("%d",&n);
        int large = -1,small = 200000,ans,taken;
        for(i=1;i<=n;i++){
            cin>>A[i]>>a>>b>>c;
            C[i] = a*b*c;
            if(large < C[i]){
                large = C[i];
                 ans = i;
            }
            if(small > C[i]){
                small = C[i];
                taken = i;
            }
        }
        int cnt =0;
        for(i=1;i<=n;i++){
            if(C[i] < large)cnt++;
        }
        if(cnt == n - 1){
            cout<<"Case "<<ct<<": "<<A[ans]<<" "<<"took chocolate from "<<A[taken]<<endl;
        }
        else{
            cout<<"Case "<<ct<<": "<<"no thief"<<endl;
        }
    }
}
