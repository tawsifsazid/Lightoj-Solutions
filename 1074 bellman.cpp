#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define pare pair<int,int>
using namespace std;

int ct=0,cases,n,m,inf = 987654321;
struct state{
    int u,v,cost;
}A[100005];
int B[205],D[205],F[205];

int relax(int u,int v,int cost){
    if(D[v]>D[u]+cost && D[u]!=inf){
        D[v] = D[u] + cost;
        return 1;
    }
    return 0;
}

void bellman(){
    int i,j,k;
    D[1] = 0;
    for(k=0;k<n;k++){
        for(i=0;i<m;i++){
            //state  a = A[j];
            //printf("%d %d %d\n",a.u,a.v,a.cost);
            relax(A[i].u,A[i].v,A[i].cost);


        }
    }
    for(i=0;i<m;i++){
        //state a = A[i];
         if(relax(A[i].u,A[i].v,A[i].cost)){
            F[A[i].v]  = 1;
         }
    }
}
void init(){
    int i;
    for(i=0;i<=n;i++){
        F[i] = 0;
        D[i] = inf;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&n);
        init();
        ct++;
        int i,j,k,b,c;
        for(i=1;i<=n;i++){
            scanf("%d",&B[i]);
        }
        scanf("%d",&m);
       // printf("sheshe\n");
        for(i=0;i<m;i++){
            scanf("%d %d",&b,&c);
            A[i].u = b;
            A[i].v = c;
            A[i].cost = (B[c] - B[b])*(B[c] - B[b])*(B[c] - B[b]);
        }
        //printf("sheshe\n");
        bellman();
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",ct);
        while(q--){
            scanf("%d",&b);
            if( D[b] < 3 || F[b] == 1 || D[b] >= inf ){
                printf("?\n");
            }
            else{
                printf("%d\n",D[b]);
            }
        }

    }
    return 0;
}
