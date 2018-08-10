#include<bits/stdc++.h>

using namespace std;

unsigned long long int sqrtn,k=1,res[5000005],ct=0,cases,n,a,b;
void sieve(){
    int i,j;
    //memset(flag, 0, sizeof flag);
    for(i=1;i<=5000000;i++)res[i]=0;
    for(i=2;i<=5000000;i++){
        if(res[i]==0){
            res[i]=i-1;
            //printf("%d %d\n",k,A[k]);
          for(j=i*2;j<=5000000;j=j+i){
                if(res[j]==0){
                    res[j]=j;
                //if(j==8)printf("%d==%d\n",j,res[j]);
                }
                res[j]=(res[j]/i)*(i-1);
            }
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i,j;
    sieve();
    for(i=2;i<=5000000;i++){
        res[i]=(res[i]*res[i])+res[i-1];
    }
    scanf("%lld",&cases);
    while(cases--){
        ct++;
        scanf("%llu %llu",&a,&b);
        printf("Case %llu: %llu\n",ct,res[b]-res[a-1]);
    }
}
