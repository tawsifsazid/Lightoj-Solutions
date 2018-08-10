#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007
using namespace std;

ll ct=0,cases;
ll P[664600];
char vis[10000006];
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
void sieve(){
    ll i,j,k=0,c = 0;
    P[0] = 2;
    k++;

    memset(vis,0,sizeof vis);
    for(i=4;i<=10000000;i=i+2){
        vis[i] = 1;
    }
    for(i=3;i<=10000000;i=i+2){
        if(vis[i] == 0){
            P[k] = i;
            k++;
            //cout<<i<<endl;
        }
        if(vis[i] == 0){
            for(j = i*i;j<=10000000;j=j+i){

                vis[j] = 1;
            }
        }
    }
    //cout<<k<<endl;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n,i,j,k;
        sieve();
        scanf("%lld",&cases);
        while(cases--){
            ct++;
          ll res =0;
            scanf("%lld",&n);
            ll check = 0;
            for(i=0;i<664579 && P[i] <= n/2;i++){
                if(vis[n - P[i]] == 0){
                    //cout<<n-P[i]<<" "<<P[i]<<endl;
                    check++;
                }
            }
            printf("Case %lld: %lld\n",ct,check);

        }



}
