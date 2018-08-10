#include<bits/stdc++.h>

using namespace std;

long long sqrtn,g,i,j,k,res[50000],ct=0,cases,p,l,D,frst;
void finddiv(long long n){
    sqrtn=sqrt(n);
    g=0;
    memset(res, 0 , sizeof res);
    //printf("%d %d asdas\n",res[0],res[1]);
    for(i=1; i<sqrtn ; i++){
        if(n % i == 0){
                res[g]=i;
                //printf("%d\n",res[g]);
                g++;
                res[g]=(n/i);
                //printf("%d\n",res[g]);
                g++;
        }
    }
    if(n % sqrtn == 0){
        if(sqrtn*sqrtn == n){
            res[g] = sqrtn;
            g++;
        }
        else{
            res[g] = sqrtn;
            g++;
            res[g]=n/sqrtn;
            g++;
        }
    }
     sort(res,res+g);
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%lld",&cases);
    while(cases--){
        ct++;
        scanf("%lld %lld",&p,&l);
       if(p==1) printf("Case %lld: 1\n",ct);
       else if(p-l<=l)printf("Case %lld: impossible\n",ct);
       else{
        finddiv(p-l);
        //for(i=0;i<g;i++)printf("asdas%d\n",res[i]);
        printf("Case %lld: ",ct);
        frst=0;
        D=0;
        for(i=0;i<g;i++){
            if(res[i]>l){
                D=1;
                if(frst == 0){
                    printf("%lld",res[i]);
                    frst=1;
                }
                else{
                    printf(" %lld",res[i]);
                }
            }
        }
                printf("\n");
       }
    }
}
