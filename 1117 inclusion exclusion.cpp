#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007
using namespace std;

ll ct=0,cases,n,m,ans;
ll A[50];
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
ll gcd(ll a,ll b){
    if(b == 0)return a;
    else{
        return gcd(b,a%b);
    }
}
ll lcm(ll a,ll b){
    ll l = (a/gcd(a,b))*b;
    return l;
}
void tryinclusion(ll counter,ll now_lcm,ll check){
    //cout<<counter<<" "<<now_lcm<<" "<<check<<endl;
    if(now_lcm > n) return;

    if(counter == m){
        if(check == 0)return;
        if(check % 2 == 0){
            ans = ans + (n/now_lcm);

        }
        else{

            ans = ans - (n/now_lcm);

        }
        return;
    }
    tryinclusion(counter+1,now_lcm,check);
    tryinclusion(counter+1,lcm(now_lcm,A[counter]),check + 1);


}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%lld",&cases);
    while(cases--){
        ct++;
        int i,j,k;
        ans = 0;
        scanf("%lld %lld",&n,&m);
        for(i=0;i<m;i++){
            scanf("%lld",&A[i]);
        }

         tryinclusion(0,1,0);
            printf("Case %lld: %lld\n",ct,n-abs(ans));
    }



}
