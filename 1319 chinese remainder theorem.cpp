#include<bits/stdc++.h>
#define N 1005
#define  ll long long
using namespace std;

ll ct=0,cases,n;
ll A[100],R[100],X[100];
ll mult;
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
/*ll findx1(ll d,ll r){
    ll i=1;
    //printf("mult = %lld\n",mult/d);
    for(i=1; ;i++){
        if(i % d == r && (i %(mult / d)== 0))break;
        //printf("i = %lld\n",i);
    }
    return i;
}
ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b , a%b);
    }

}
ll LCM(ll a, ll b){
    return (a/gcd(a,b))*b;
}*/
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%lld",&cases);
    while(cases--){
        ct++;
        scanf("%lld",&n);
        ll i,j;
        mult = 1;
        for(i=1;i<=n;i++){
            scanf("%lld %lld",&A[i],&R[i]);
            mult = mult * A[i];
            //printf("%lld\n",mult);
        }
        ll res=0,k=1;
        for(i=1;i<=n;i++){
            //X[i] = findx1(A[i],R[i]);
            //printf("X = %d\n",X[i]);
            for(j=mult/A[i];    ; j= j + (mult/A[i])){
                 if(j % A[i] == R[i] && (j %(mult/ A[i])== 0)){
                        X[k] = j;
                        k++;
                        break;
                 }
            }
            //printf("X = %d\n",X[i]);
        }
        //printf("lcm = %lld\n",lcm);
        for(i=1;i<=n;i++){
            res = res + X[i];
           //printf("res = %lld and X[i] = %lld\n",res,X[i]);
        }
        while(res-mult >= 0){
            res =  res - mult;
        }
        //printf("%lld\n",res);
        //res = res + lcm;
        //if(res==0)printf("Case %lld: Impossible\n",ct);
         printf("Case %lld: %lld\n",ct,res);
    }
}
