#include<bits/stdc++.h>
#define N 1005
#define  ll long long
using namespace std;

ll ct=0,cases,n,w;
ll A[60000];
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
    scanf("%lld",&cases);
    while(cases--){
        ct++;
        scanf("%lld %lld",&n,&w);
        ll i,j,k,x,y;
        for(i=0;i<n;i++){
            scanf("%lld %lld",&x,&A[i]);
        }
        sort(A ,A  + n);
         //for(i=1;i<=n;i++){
          //  printf("%lld\n",A[i]);
        //}
        ll ans = 0;
        ll a = A[0];
        for(i=1;i<n;i++){
            if(A[i] - a > w){
                ans++;
                a = A[i];
            }
        }
        printf("Case %lld: %lld\n",ct,ans + 1);
    }
}
