#include<bits/stdc++.h>
#define N 1005
#define ll long long
using namespace std;

ll res,ct=0,cases,n,n1,n2,n3,n4;
string a,b;
map<string,int>m;
char c;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    m["January"] = 1;
    m["February"] = 2;
    m["March"] = 3;
    m["April"] = 4;
    m["May"] = 5;
    m["June"] = 6;
    m["July"] = 7;
    m["August"] = 8;
    m["September"] = 9;
    m["October"] = 10;
    m["November"] = 11;
    m["December"] = 12;
    scanf("%lld",&cases);
    //cout<<m["February"]<<endl;
    while(cases--){
        ct++;
        cin>>a>>n1>>c>>n2;
        //cout<<a<<" "<<n1<<" "<<c<<" "<<n2<<endl;
        cin>>b>>n3>>c>>n4;
        // printf("n4 == %lld\n",n4);
        //printf("n2 = %lld\n",n2);
        //printf("n3 = %lld\n",n3);
        if(m[a] > 2) n2++;
        if(m[b]<2 || (m[b]==2 && n3<29)){
            n4--;
        }
        //cout<<a<<" "<<n3<<" "<<c<<" "<<n4<<endl;
        ll leap;
        //printf("n4 == %lld\n",n4);
        //printf("n2 = %lld\n",n2);
        ll leap4 = (n4/4-((n2-1)/4));
        //cout<<leap4<<endl;
        ll leap100 =  (n4/100-((n2-1)/100));
        //cout<<leap100<<endl;
        ll leap400 =  (n4/400-((n2-1)/400)) ;
        //printf("%lld\n",leap1);
        //cout<<leap400<<endl;
        leap = leap4 + leap400 - leap100;
       printf("Case %lld: %lld\n",ct,leap);
    }
}
