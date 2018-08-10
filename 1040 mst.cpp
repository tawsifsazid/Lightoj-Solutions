#include<bits/stdc++.h>
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007
using namespace std;

int ct=0,cases,fl,n,B[2505],k;
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
  int u,v,cost;
}A[2505];
bool compare (edge a, edge b){
    return a.cost<b.cost;
}
int fnd(int r){
    if(B[r]==r)return r;
    else{
        r =  fnd(B[r]);
        return r;
    }
}
int mst(int node){
    int tot=0,in=0,i,j,res = 0;
    for(i=0;i<=n;i++)B[i]=i;
    for(i=0;i<k;i++){
        int u = fnd(A[i].u);
        int v = fnd(A[i].v);
        if(u!=v){
            B[u] = v;
            res = res + A[i].cost;
            //printf("res = %d\n",res);
            //printf("1st MST = %lld tot = %lld \n",edgenisi[tot],tot);
            tot++;
            //printf("tot = %lld\n",tot);
        }

        if(tot == n-1){
            //printf("dhukse\n");
            break;
        }
        //printf("in = %lld\n",in);
    }
    if(tot != n-1)fl = 1;
    return res;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
       int i,j,res,cst;
        scanf("%d",&cases);
        while(cases--){
            ct++;
            scanf("%d",&n);
            fl = 0;
            k=0;
            res = 0;
            memset(A,0,sizeof A);
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    scanf("%d",&cst);
                    res = res + cst;
                   if(cst == 0){

                   }
                   else{
                        A[k].u = i;
                        A[k].v = j;
                        A[k].cost = cst;
                        k++;
                   }
                }
            }

        //printf("res = %d\n",res);
            //printf("ss\n");
            sort(A,A+k,compare);
            //for(i=0;i<k;i++){
             //   printf("%d %d %d\n",A[i].u,A[i].v,A[i].cost);
            //}
            int ans = res - mst(n);
           if(fl == 0) printf("Case %d: %d\n",ct,ans);
            else printf("Case %d: -1\n",ct);
        }
}
