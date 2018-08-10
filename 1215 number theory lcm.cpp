#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define pare pair<ll,ll>
using namespace std;

ll ct=0,cases,h;
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
vector<ll>P;
ll flag[1000002];
vector<pare>lcmfact;
vector<pare>divisorfact;
ll factorcounter[1000002],lcmcounter[1000002];
void sieve(){
    P.push_back(2);
    ll i,j,k;
    memset(flag,-1,sizeof flag);
    for(i=3;i<=1000000;i=i+2){
        if(flag[i]== -1){
            P.push_back(i);
            //cout<<i<<endl;
        }
        if(flag[i]==-1){
            for(j=i*i;j<=1000000;j=j+i){
                flag[j]=0;
            }
        }
    }
}
void fact(ll n){
    //cout<<n<<endl;
    ll i,j,k;
    //ll sq = sqrt(n);
    for(i=0;i<P.size() && P[i]<=n;i++){
          ll freq = 0;
        if(n % P[i] == 0){
            while(n % P[i] == 0){
                n = n/P[i];
                freq++;
            }
            //printf("check fact p = %lld\n",P[i]);
            //sq = sqrt(n);
             if(factorcounter[P[i]] == 0){
                factorcounter[P[i]] = freq;
            }
            else{
                if(freq > factorcounter[P[i]]){
                    factorcounter[P[i]] = freq;
                }
            }
            divisorfact.push_back(pare(factorcounter[P[i]],P[i]));
        }
    }
}
void fact1(ll n){
    ll i,j,k;
    //ll sq = sqrt(n);
    for(i=0;i<P.size() && P[i]<=n;i++){
          ll freq = 0;
        if(n % P[i] == 0){
            while(n % P[i] == 0){
                n = n/P[i];
                freq++;
            }
            //printf("check fact1 %lld\n",P[i]);
            //sq = sqrt(n);
            if(lcmcounter[P[i]] == 0){
                lcmcounter[P[i]] = freq;
            }
            else{
                if(freq > lcmcounter[P[i]]){
                    lcmcounter[P[i]] = freq;
                }
            }
            lcmfact.push_back(pare(lcmcounter[P[i]],P[i]));
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    sieve();
    scanf("%lld",&cases);
    while(cases--){
        ct++;
        ll i,j,k,lcm,a,b,h;
        memset(factorcounter,0,sizeof factorcounter);
        memset(lcmcounter,0,sizeof lcmcounter);
        scanf("%lld %lld %lld",&a,&b,&lcm);
        fact(a);
        fact(b);
        fact1(lcm);
        int fl = 0;
        for(i=0;i<divisorfact.size();i++){
            if(divisorfact[i].first > lcmcounter[divisorfact[i].second]){
                fl = 1;
            }
        }
        int fr = 0;
        ll ans = 1;
        if(fl == 1){
            printf("Case %lld: impossible\n",ct);
        }
        else{
            for(i=0;i<lcmfact.size();i++){
                if(lcmfact[i].first > factorcounter[lcmfact[i].second]){
                   ll c = lcmfact[i].first;
                    while(c--){
                        ans = ans*lcmfact[i].second;
                    }
                }
            }
            printf("Case %lld: %lld\n",ct,ans);

        }
        divisorfact.clear();
        lcmfact.clear();
    }
}
