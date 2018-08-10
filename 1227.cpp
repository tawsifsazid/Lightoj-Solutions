#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int i,j,k,n,p,q,cases,ct=0,a,ans,egg,weight;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        ans=0;
        egg=0;
        weight=0;
        scanf("%d %d %d",&n,&p,&q);
        while(n--){
            scanf("%d",&a);
            egg++;
            if(egg<=p){
                weight=weight + a;
                if(weight<=q){
                    ans++;
                }
            }
        }
        printf("Case %d: %d\n",ct,ans);
    }
}
