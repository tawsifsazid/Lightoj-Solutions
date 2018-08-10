#include<bits/stdc++.h>
#define N 100005
#define  ll long long
#define pare pair<int,int>
using namespace std;

int ct=0,cases,n;
int queryres;
///dir array for Queen int dxq[10] = {-1,-1,-1,1,1,1,0,0};
///dir array for Queen int dyq[10] = {-1,0,1,-1,0,1,-1,1};
///dir array for knight int dxk[10] = {-2,-2,-1,-1,1,1,2,2};
///dir array for knight int dyk[10] = {1,-1,-2,2,-2,2,-1,1};

struct {
    int lazy,sum,prop;
    void clear(){
        prop = 0;
        lazy = 0;
    }
    void calculate(int len){
        sum = (len*lazy);
    }


}stree[N*4];

void propagate(int t,int l,int r){
     int u = (t*2);
     int v = u + 1;
     int m = (l + r)/2;
     //printf ("propagate too  u = %d and v = %d amount = %d\n",u,v,stree[t].lazy);
     if(l == r){
        stree[t].clear();
        return ;
     }
    stree[u].lazy = stree[t].lazy;
    stree[v].lazy = stree[t].lazy;
    int u_pabe = m - l + 1;
    int v_pabe = r - m;
    stree[u].sum = (u_pabe*stree[t].lazy);
    stree[v].sum = (v_pabe*stree[t].lazy);
    stree[t].clear();
    stree[u].prop = 1;
    stree[v].prop = 1;

}

void update(int t,int l,int r,int x,int y,int  val){
    int m = (l + r)/2;
    int u = t*2;
    int v = u + 1;
    //printf("%d %d %d\n",l,m,r);
    if(l>y || r<x){
        return;
    }
    if(stree[t].prop){
        propagate(t,l,r);
    }
    if(l>=x && r<=y){
        stree[t].lazy = val;
        stree[t].calculate(r - l + 1);
        stree[t].prop = 1;
        return;
    }

    update(u,l,m,x,y,val);
    update(v,m+1,r,x,y,val);
    stree[t].sum = stree[u].sum + stree[v].sum;
}
void query(int t,int l,int r,int x,int y){
     int m = (l + r)/2;
    int u = t*2;
    int v = u + 1;

    if(l>y || r<x){
        return;
    }
    if(stree[t].prop){
        propagate(t,l,r);
    }
    if(l>=x && r<=y){
        queryres = queryres + stree[t].sum;
        return;
    }

    query(u,l,m,x,y);
    query(v,m+1,r,x,y);
    stree[t].sum = stree[u].sum + stree[v].sum;
}


int findgcd(ll a,ll b){
    if(b==0)return a;
    else return findgcd(b,a%b);
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        memset(stree,0,sizeof stree);
        int q,i,j,ch,a,b,v;
        scanf("%d %d",&n,&q);
        printf("Case %d:\n",ct);
        for(i=1;i<=q;i++){
            queryres = 0;
            scanf("%d",&ch);
            if(ch == 1){
                scanf("%d %d %d",&a,&b,&v);
                update(1,1,n,a+1,b+1,v);
            }
            else{
                 scanf("%d %d",&a,&b);
                 //queryres = 0;
               query(1,1,n,a+1,b+1);
               int bb = b-a+1;
                //printf("kire %d\n",queryres);
                if(queryres % bb != 0){
                    int gcd = findgcd(queryres,bb);

                    printf("%d/%d\n",queryres/gcd,bb/gcd);

                }
                else printf("%d\n",queryres/bb);
            }
        }
    }
}
