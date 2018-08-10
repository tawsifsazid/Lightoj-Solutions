#include<bits/stdc++.h>
#define N 1005
#define  ll long long
using namespace std;

int ct=0,cases;
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
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        int a1,a2,b1,b2,c1,c2;
        scanf("%d %d %d %d %d %d",&a1,&a2,&b1,&b2,&c1,&c2);
        int ans1,x,y;
        x = a1 + c1 - b1;
        y = a2 + c2 - b2;
        ans1 = ((a1*b2)+(b1*c2)+(c1*y)+(x*a2))-((a2*b1)+(b2*c1)+(c2*x)+(y*a1));
        printf("Case %d: %d %d %d\n",ct,x,y,abs(ans1/2));
    }
}
