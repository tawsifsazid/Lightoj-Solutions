#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007
using namespace std;

ll ct=0,cases,n,m,ans;
ll sqfree[10005],A[10005],freq[10005];

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
ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }
    else return gcd(b,a%b);
}
ll ncr(ll n , ll r){
    //cout<<"dhukse "<<n<<" "<<r<<endl;
    if(n < r)return 0;
    ll i,j,k=0,rr,up[10005],down[10005],res =1,p=0;

    if(n - r >= r){
            k = 0;
            rr = n - r;
        for(i=rr+1;i<=n;i++){
            up[k] = i;
            k++;
        }
        p = 0;
        for(i=2;i<=r;i++){
            down[p] = i;
            p++;
        }
        //for(j=0;j<p;j++)cout<<" asdasd "<<down[j]<<endl;
       for(j=0;j<p;j++){

            for(i = 0; i<k ; i++){
                ll vag =  gcd(up[i],down[j]);
                //cout<<vag<<" "<<up[i]<<" "<<down[j]<<endl;

                    up[i] = up[i] / vag;
                        down[j]= down[j] / vag;

            }
             //cout<<"as"<<endl;
       }
       for(i=0;i<k;i++){
            //cout<<"up "<<up[i]<<endl;
            res= res * up[i];
       }
    }
    else{
           // cout<<"ya"<<endl;
        k = 0;
        rr= r;
        for(i=rr+1;i<=n;i++){
            up[k] = i;
            k++;
        }
        p = 0;
        for(i=2;i<=n-r;i++){
            down[p] = i;
            p++;
        }
        for(j=0;j<p;j++){
            for(i = 0; i<k ; i++){
                ll vag =  gcd(up[i],down[j]);
                //cout<<vag<<endl;
                //break;

                    up[i] = up[i] / vag;
                     down[j] =  down[j] / vag;
                    //cout<<"a"<<endl;

            }

       }
       for(i=0;i<k;i++){
            res= res * up[i];
       }
    }
    return res;
}
void sieve(){
    ll i,j,k=0,cnt = 0;
    memset(sqfree,0,sizeof sqfree);


    for(i=2;i<=10000;i++){
        if(sqfree[i] == 0){
            sqfree[i]++;
            for(j=i*2;j<=10000;j=j+i){
                if(j % (i*i) == 0){
                    //cout<<j<<" is sqare"<<endl;
                    sqfree[j] = -2;
                }
                else if(sqfree[j] != -2){
                    sqfree[j]++;
                    //cout<<j<<" has divisor " <<sqfree[j]<<endl;
                }
            }
        }
    }

    //cout<<k<<endl;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    sieve();
    scanf("%lld",&cases);
    while(cases--){
        ct++;
        scanf("%lld",&n);
        ll i,j,k,maxx=0;
        for(i=0;i<n;i++){
            scanf("%lld",&A[i]);
            maxx = max(maxx,A[i]);
        }
        ans = ncr(n,4);
        //cout<<" ans = "<<ans<<endl;
        memset(freq,0,sizeof freq);
        for(i=0;i<n;i++){
            ll tmp = sqrt(A[i]);
            ll fl = 0;
            for(j=1;j<=tmp;j++){
                if(A[i] % j == 0){
                    freq[j]++;
                    freq[A[i]/j]++;
                    fl = 1;
                }
            }
            if((tmp*tmp) == A[i] && A[i] != 1){
              //  cout<<A[i]<<endl;
                freq[tmp]--;
            }
        }
        //for(i=1;i<=n;i++){
            //cout<<"freq "<<i<<" "<<freq[i]<<endl;
        //}
        for(i=2;i<=maxx;i++){
               // cout<<"mobius of "<<i<<" = "<<sqfree[i]<<" and freq "<<freq[i]<<endl;
            if(sqfree[i] % 2 && sqfree[i] != -2){
                    ans = ans - ncr(freq[i],4);

              // cout<<"odd n c r = "<<freq[i] << " c " <<4<<endl;

            }
            else if(sqfree[i] % 2 == 0 && sqfree[i] != -2){
                    ans = ans + ncr(freq[i],4);
              //  cout<<"even n c r = "<<freq[i] << " c " <<4<<endl;
            }
        }
        //cout<<ans<<endl;
        printf("Case %lld: %lld\n",ct,ans);

    }


}
