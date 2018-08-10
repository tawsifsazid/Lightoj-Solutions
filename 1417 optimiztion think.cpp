#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007
#define grey 1
#define white 0
#define black 2
using namespace std;

int ct=0,cases,n;

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
int vis[50005],graph[50005],mem[50005];
int dfs(int s){
    int i,j,k,tot = 0;
    vis[s] = 1;
    if( vis[graph[s]] == 0 ){
        vis[graph[s]] = 1;
        tot = 1+ tot + dfs(graph[s]);
    }
    vis[s] = 0;
    //cout<<s<<" res = "<<res[s]<<" tot = "<<tot<<endl;
    //return res[s] = tot;
    return mem[s] = tot;

}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        scanf("%d",&n);
        memset(graph,0,sizeof graph);
        memset(vis,0,sizeof vis);
        memset(mem,0,sizeof mem);

        int i,j,k,u,v;
        for(i=0;i<n;i++){
            scanf("%d %d",&u,&v);
            graph[u] = v;
        }
        int large=-1,index= 1,ss=0;
        for(i=1;i<=n;i++){
           if(mem[i] == 0){
               ss = dfs(i);
               //printf("sheshe\n");
           }
           if(large < mem[i]){
                large = ss;
                index  = i;
           }
        }
        printf("Case %d: %d\n",ct,index);
    }
}
