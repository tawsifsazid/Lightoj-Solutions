#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007
using namespace std;

int ct=0,cases,n,res = 0;
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
int vis[105],cost[105][105];
vector<int>graph[105];

void dfs(int u){
    vis[u] = 1;
    int i,j,k;
    for(i=0;i<graph[u].size();i++){
        int v = graph[u][i];
        if(vis[v] == 0){
            vis[v] = 1;
            res = res + cost[u][v];
            dfs(v);
        }
    }


    //cout<<"h "<<res<<endl;
    //return res;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        scanf("%d",&n);
        memset(vis,0,sizeof vis);
        memset(cost,0,sizeof cost);
        int i,j,k,u,v,ans=0;
        //res = 0;
        for(i=0;i<n;i++){
            scanf("%d %d %d",&u,&v,&j);
            cost[u][v] = j;
            ans = ans + cost[u][v];
            cost[v][u]=0;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        res = 0;
        dfs(1);
        int bb = graph[1][1];
        res = res + cost[bb][1];
        //cout<<" "<<ans<<endl;
        for(i=1;i<=n;i++){
            graph[i].clear();
        }
        printf("Case %d: %d\n",ct,min(ans-res,res));
    }

}
