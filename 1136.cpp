#include<bits/stdc++.h>
#define ll long long
#define PI acos(-1)
#define eps 1e-9

using namespace std;

ll cases,ct= 0,a,b;

ll func(ll n){
    if(n % 3 == 2){
        return (2*(n/3)) + 1;
    }
    else if(n % 3 == 1){
        return (2*(n/3));
    }
    else{
        return (2*(n/3));
    }
}

int main(){

    scanf("%lld",&cases);
    while(cases--){
        ct++;
        scanf("%lld %lld",&a,&b);
        ll res1 = func(a-1);
        ll res2 = func(b);
        printf("Case %lld: %lld\n",ct,res2-res1);
    }


}


