#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007

int ct=0,cases;
int n;
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

    scanf("%lld",&cases);
    while(cases--){
        ct++;
        double res = 1.00;
        scanf("%d",&n);
        int i,j,k,people=0;
        double probability = 0.00;
        //cout<<probability<<endl;
        for(i=n;probability < .5 ; i--){
            res = res*((double)i/n);
            probability = 1 - res;
            //cout<<probability<<endl;
            if(probability < .5)people++;
            //break;
        }
        printf("Case %d: %d\n",ct,people);
    }

}
