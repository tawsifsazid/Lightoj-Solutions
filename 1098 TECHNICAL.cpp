#include<bits/stdc++.h>

using namespace std;

long long i,j,k,res,ct=0,cases,n;
long long csod(long long a){
    long long sqrtn = sqrt(a);
    long long sum=0,u;
    for(i=2;i<=sqrtn;i++){
        u = a/i;
        sum = sum + ((u*(u + 1))/2)-(((i-1)*(i))/2);
        sum = sum +  ((u-i)*i);
    }
    return sum;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%lld",&cases);
    while(cases--){
        ct++;
        scanf("%lld",&n);
        res = csod(n);
        printf("Case %lld: %lld\n",ct,res);
    }
}
