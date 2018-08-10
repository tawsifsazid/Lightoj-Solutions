#include<bits/stdc++.h>

using namespace std;
unsigned long long int j,k,res,ct=0,cases,n;
int i;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%llu",&cases);
    //printf("%llu\n",cases);
    while(cases--){
        ct++;
        scanf("%llu",&n);
        //printf("%llusad\n",n);
        printf("Case %llu:",ct);
        for(i=9 ; i>=0; i--){
            //printf("%d\n",i);
            if(((n*10)-i)%9==0){
                k=((n*10)-i)/9;
                printf(" %llu",k);
            }
        }
        printf("\n");
    }
}
