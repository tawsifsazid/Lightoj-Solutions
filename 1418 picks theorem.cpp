#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007

ll ct,cases,n;
double x[10005],y[10005];
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

ll gcd (ll a,ll b){
    if(b == 0)return a;
    else return gcd(b,a%b);
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%lld",&cases);
    while(cases--){
        ct++;
        scanf("%lld",&n);
        ll i,j,k;
        for(i=0;i<n;i++){
            scanf("%lf %lf",&x[i],&y[i]);
        }
        x[n] = x[0];
        y[n] = y[0];
        double area = 0.0;
        ll boundary = 0;
        for(i=0;i<n;i++){
            area = area + (x[i]*y[i+1]);
        }
        for(i=n;i>0;i--){
            area = area - (x[i]*y[i-1]);
        }
        for(i=1;i<=n;i++){
            boundary = boundary + gcd(fabs(x[i]-x[i-1]),fabs(y[i]-y[i-1])) ;
            //cout<<gcd(fabs(x[i]-x[i-1]),fabs(y[i]-y[i-1]))<<endl;
        }
        area = fabs(area/2.0);

        //cout<<area<<" "<<boundary<<endl;
        boundary = (boundary )/2 ;
        ll ans = area - (boundary) + 1;
        printf("Case %lld: %lld\n",ct,abs(ans));
    }

}
