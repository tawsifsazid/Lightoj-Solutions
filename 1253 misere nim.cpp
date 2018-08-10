#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007

int ct=0,cases;

using namespace std;

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


int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        ll a,b,n;
        scanf("%lld",&n);
       if(n == 1){
            scanf("%d",&b);
            printf("Case %d: Bob\n",ct);
       }
       else{
            ll res = 0,check = 0;
            scanf("%lld",&b);
            if(b == 1)check = check + 1;
            res = b;
            for(ll i=0;i<n-1;i++){
                    scanf("%lld",&b);
                    if(b == 1)check = check + 1;
                res = res xor b;
            }
            if(res == 0 && check != n)printf("Case %d: Bob\n",ct);
            else if(check == n){
                  if(check % 2 == 0){
                       printf("Case %d: Alice\n",ct);

                  }
                  else printf("Case %d: Bob\n",ct);
            }
            else if(res !=0 && check != n)printf("Case %d: Alice\n",ct);

       }
    }

}
