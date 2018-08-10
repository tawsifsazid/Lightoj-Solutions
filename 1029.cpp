#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<set>

using namespace std;

int j,k,ct,cases,n,B[500],a,b,c,res1,res2;
struct edge{
    int u,v,cost;

}A[30000];
bool compare1(edge a,edge b){
    return (a.cost<b.cost);
}
bool compare2(edge a,edge b){
    return (a.cost>b.cost);
}
int fnd(int r){
    if(B[r]==r){
        return r;
    }
    else{
        r=fnd(B[r]);
        return r;
    }
}
int mst(int x){
    int in=0,tot=0;
   int res=0;
    for(int i=0;i<=n;i++)B[i]=i;
    while(tot!=x){
        int u=fnd(A[in].u);
        int v=fnd(A[in].v);
        if(u!=v){
            B[v]=u;
            res=res+A[in].cost;
            tot++;
        }
         in++;
    }
    return res;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        int i;
        for(i=0;i<=25000;i++){
            A[i].u=0;
            A[i].v=0;
            A[i].cost=0;
        }
        res1=0;
        res2=0;
        ct++;
        scanf("%d",&n);
        i=0;
        while(scanf("%d %d %d",&a,&b,&c)){
           if(a==0 && b==0 && c==0)break;
            //scanf("%d %d %d",&A[i].u,&A[i].v,&A[i].cost);
            A[i].u=a;
            A[i].v=b;
            A[i].cost=c;
            i++;
        }
            sort(A,A+i,compare1);
             res1= mst(n);
           // printf("%d\n",res1);
            sort(A,A+i,compare2);
             res2=mst(n);
            //printf("%d\n",res2);
        res1=res1+res2;
        if(res1%2==0){
            printf("Case %d: %d\n",ct,res1/2);
        }
        else{
            printf("Case %d: %d/2\n",ct,res1);
        }
    }
}
