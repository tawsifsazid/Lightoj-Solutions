#include<bits/stdc++.h>

using namespace std;

long long i,j,k,res,ct=0,cases,n,x,y,a,b;
long long gcd(long long a,long long b){
    if(b==0)return a;
    else{
        return gcd(b,a%b);
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        scanf("%lld %lld %lld %lld",&x,&y,&a,&b);
        //printf("%lld\n",u);
        res=gcd(abs(x-a),abs(y-b))+1;
        printf("Case %lld: %lld\n",ct,res);
    }
}
