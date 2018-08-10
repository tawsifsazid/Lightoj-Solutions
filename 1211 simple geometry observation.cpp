#include<bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;

ll res,ct=0,cases,n,xhigh,xlow,yhigh,ylow,zhigh,zlow;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%lld",&cases);
    while(cases--){
        ct++;
        xhigh = 2000;
        yhigh = 2000;
        zhigh = 2000;
        xlow = -1;
        ylow = -1;
        zlow = -1;
        int i,j;
        scanf("%lld",&n);
        ll x,y,z,x1,y1,z1;
        for(i=1;i<=n;i++){
            scanf("%lld %lld %lld %lld %lld %lld",&x,&y,&z,&x1,&y1,&z1);
            xhigh = min(xhigh,x1);
            xlow = max(xlow,x);
            yhigh = min(yhigh,y1);
            ylow = max(ylow,y);
            zhigh = min(zhigh,z1);
            zlow = max(zlow,z);
        }
        ll vol = 0;
        vol = (xhigh-xlow)*(yhigh-ylow)*(zhigh-zlow);
        if(vol<=0)printf("Case %lld: 0\n",ct);
        else{
            printf("Case %lld: %lld\n",ct,vol);
        }
    }
}
