#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define pare pair<int,int>
using namespace std;

ll ct=0,cases,n,k,h,c;

 double eps = 1e-12;

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
ll leading(ll num,ll kk){
   int i,j,k;
    double fact =kk * log10(num);
    //cout<<fact<<endl;
    double q = fact - floor(fact + eps);
    //cout<<q<<endl;
    double B = pow(10,q);
    for(i=1;i<=2;i++){
        B = B*10;
    }
    //cout<<floor(B+eps)<<endl;
    return floor(B+eps);
}
ll bigmod(ll b,ll p,ll m){
   if(p == 0)return 1;
   else if(p % 2 == 0){
        ll ans = bigmod(b,p/2,m);
        return ((ans%m)*(ans%m))%m;
   }
   else{
        return ((b%m)*(bigmod(b,p-1,m)%m))%m;
   }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%lld",&cases);
    while(cases--){
        scanf("%lld %lld",&n,&k);
        ct++;
        ll ans1 = bigmod(n,k,1000);
        ll ans2 = leading(n,k);
        if(ans1<10){
            printf("Case %lld: %lld 00%lld\n",ct,ans2,ans1);
        }
        else if(ans1<100 && ans1>=10){
            printf("Case %lld: %lld 0%lld\n",ct,ans2,ans1);
        }
        else{
            printf("Case %lld: %lld %lld\n",ct,ans2,ans1);
        }

    }

}
