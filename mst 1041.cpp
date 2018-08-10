#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define pare pair<int,int>
using namespace std;

int ct=0,cases,n,m,P[105],res,baki,fl=0;
map<string,int>M;
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
struct edge{
    int u,v,cost,nisi=0;
}A[55];
int fnd(int r){
    if(P[r] == r)return r;
    else{
        r = fnd(P[r]);
        return r;
    }
}
bool compare(edge a,edge b){
   //printf("%lf %lf\n",a.cost,b.cost);
    return a.cost < b.cost;
}
void mst(){
    int tot=0,in=0;

    while(tot != baki && in  != m){
        int u = fnd(A[in].u);
        int v = fnd(A[in].v);
        if(u != v){
            P[v] = u;

            res += A[in].cost;
            tot++;
        }
        in++;
    }
    if(tot != baki)fl = -1;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
         ct++;
         memset(A,0,sizeof A);

        scanf("%d",&m);
        string a,b;
        int i,j,k=0,cst,nie_nisi=0;
        n = 0,res =0,fl = 0;
        for(i=0;i<=100;i++)P[i]=i;
        for(i=0;i<m;i++){
            cin>>a>>b>>cst;
            if(M[a] == 0){
                k++;
                M[a] = k;
                n++;
            }
            if(M[b] == 0){
                k++;
                M[b]= k;
                n++;
            }
            A[i].u = M[a];
            A[i].v = M[b];
            if(cst == 0){
                int u = fnd(A[i].u);
                int v = fnd(A[i].v);
                if(u!=v){
                    P[v] = u;
                    nie_nisi++;
                }
            }
            else{
                A[i].cost = cst;
            }
        }
        baki = n - 1 - nie_nisi;
        sort(A,A+m,compare);
        mst();
        if(fl == 0){
            printf("Case %d: %d\n",ct,res);
        }
        else{
            printf("Case %d: Impossible\n",ct);
        }
        M.clear();
    }
}
