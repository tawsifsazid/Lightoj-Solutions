#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007

using namespace std;

ll ct,cases,n;

vector<ll>V;
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
        int i,j,k;
        ct++;
        scanf("%lld",&n);
        while(n!=0){
            int rem = n%2;
            n = n /2;
            V.push_back(rem);
        }
         V.push_back(0);
        reverse(V.begin(),V.end());
       // for(i=0;i<V.size();i++){
        //    cout<<V[i];
        //}

        //cout<<endl;

        next_permutation(V.begin(),V.end());
        //for(i=0;i<V.size();i++){
        //    cout<<V[i];
        //}
        ll ans=0,two=1;
        for(i=V.size()-1;i>=0;i--){
            ans  = ans + (two*V[i]);
            two = two*2;
        }
        printf("Case %lld: %lld\n",ct,ans);
        V.clear();
    }


}
