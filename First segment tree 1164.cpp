#include<bits/stdc++.h>
#define N 100005
#define  ll long long
#define pare pair<int,int>
using namespace std;

int ct=0,cases;
ll queryres=0;
///dir array for Queen int dxq[10] = {-1,-1,-1,1,1,1,0,0};
///dir array for Queen int dyq[10] = {-1,0,1,-1,0,1,-1,1};
///dir array for knight int dxk[10] = {-2,-2,-1,-1,1,1,2,2};
///dir array for knight int dyk[10] = {1,-1,-2,2,-2,2,-1,1};
/*int leap(int a){
    if(a%4==0){
        if(a%100==0){
            if(a%400==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}*/
struct{
    ll lazy,sum;
}stree[N*4];

void update(int t,int l,int r,int x,int y,ll val){
    int u = t*2;
    int v = (t*2) + 1;
    int m = (l + r)/2;

    if(l>y || r<x) return;

    if(l>=x && r<=y){
        stree[t].sum = stree[t].sum + ((r - l + 1)*val);
        stree[t].lazy = stree[t].lazy + val;
        //printf("t node a ase %d and l==%d r==%d\n",stree[t].sum,l,r);
        return;
    }

    update(u,l,m,x,y,val);
    update(v,m+1,r,x,y,val);
    stree[t].sum = stree[u].sum + stree[v].sum + ((r - l + 1)*stree[t].lazy);
    //printf("t==%d u==%d v==%d and sum = %d\n",t,u,v,stree[t].sum);

}
ll  query(int t,int l,int r,int x,int y,ll add){
    int u = t*2;
    int v = (t*2) + 1;
    int m = (l + r)/2;

    if(l>y ||r<x) return 0;

    if(l>=x && r<=y) {
        queryres = queryres + stree[t].sum +   add*(r-l+1);
        //printf("queryres = %d and t=%d l=%d, r=%d\n",queryres,t,l,r);
        return queryres;
    }
    //printf("now calling u=%d and m = %d and add==%d\n",u,v,add);
    query(u,l,m,x,y,add + stree[t].lazy);
    //printf("now calling u=%d and m = %d and add==%d\n",u,v,add);
    query(v,m+1,r,x,y,add + stree[t].lazy);

    //return queryres;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        memset(stree,0,sizeof stree);

        int n,q;
        queryres = 0;
        scanf("%d %d",&n,&q);
        //A[n+1];
        // memset(A,0,sizeof A);
        printf("Case %d:\n",ct);
        while(q--){
            queryres = 0;
            int ch,x,y,value;
            scanf("%d",&ch);
            //./printf(":) %d\n",ch);
            if(ch==0){
                scanf("%d %d %d",&x,&y,&value);
                update(1,1,n,x+1,y+1,value);
            }
            else{
                scanf("%d %d",&x,&y);

                query(1,1,n,x+1,y+1,0);

                printf("%lld\n",queryres);
            }
        }
    }
}
