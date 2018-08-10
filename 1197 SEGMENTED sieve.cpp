#include<bits/stdc++.h>

long long ct=0,res,cases,n,i,j,k=1,A[50000],flag[50000],range[100006],sqrtn;

void sieve(){
    memset(flag , 0 , sizeof flag);
    flag[1]=-1;
    sqrtn=50000;
    A[k]=2;
    for(i=3;i<=sqrtn;i=i+2){
        if(flag[i]==0){
            k++;
            A[k]=i;
            //printf("%lld\n",A[k]);
        }
        if(flag[i]==0){
            for(j=i*i;j<=sqrtn;j=j+i){
                flag[j]=-1;
            }
        }
    }
}
long long segmentedsieve(long long a,long long b){
    long long num=0;
    memset(range, 0 ,sizeof range);
    if(a==1) a++;
    sqrtn=sqrt(b);
    for(i=1; i <= k && A[i]<= sqrtn; i++){
        long long p = A[i];
        j= p*p;
        if(j<a)j = (((a + p -1)/p)*p);
        //printf("j== %lld %lld\n",j,A[i]);
        for( ; j<=b ; j = j + p){
            range[j-a]=-1;
        }
    }
    for(i=a;i<=b;i++){
        if(range[i-a]==0){
            //printf("%lld\n",i);
            num++;
        }
    }
    return num;
}
using namespace std;

int main(){
    sieve();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long a,b;
    scanf("%lld",&cases);
    while(cases--){
        ct++;
        scanf("%lld %lld",&a,&b);
        res = segmentedsieve(a,b);
        printf("Case %lld: %lld\n",ct,res);
    }
}
