#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007

int ct=0,cases,n;

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
int gcd(int a,int b){
    if(b == 0 )return a;
    else return gcd(b,a%b);
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        int res = 0,i,j,k,x,tot_x,neg = 0;
        scanf("%d",&n);
        tot_x = n;
        for(i=0;i<n;i++){
            scanf("%d",&k);
            if(k < 0){
                neg++;
                tot_x = tot_x - 1;
            }
            res = res + abs(k);
        }
        int g = gcd(tot_x,res);
        tot_x = tot_x / g;
        res = res / g;
        if(neg != n)printf("Case %d: %d/%d\n",ct,res,tot_x);
        else printf("Case %d: inf\n",ct);

    }

}
