#include<bits/stdc++.h>

using namespace std;

int res,ct=0,cases,n,s,d,cst,u,v,m;
vector<int>graph[1000];
int vis[1000];
int result[1000];
queue<int>Q;
void bfs(int node){
    //printf("dhh\n");
    vis[node] = 0;
    Q.push(node);
    int i,j,k=0;
    while(!Q.empty()){
        int uu =Q.front();
        Q.pop();
        for(i=0;i<graph[uu].size();i++){
            int vv = graph[uu][i];
            if(vis[vv]==-1){
                vis[vv] = vis[uu] + 1;
                result[vv] = result[vv] + vis[vv];
                //printf("ekhon node %d  er maan %d\n",vv,result[vv]);
                Q.push(vv);
            }
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    int i,j;
    while(cases--){
        ct++;
        res = 0;
        scanf("%d %d",&n,&m);
        memset(vis , -1 ,sizeof vis);
        memset(result , 0,sizeof result);
        for(i=0;i<=m;i++){
            graph[i].clear();
        }
        for(i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        //printf("shehs\n");
        scanf("%d %d",&s,&d);
        result[s] = 0;
        bfs(s);
        memset(vis , -1 ,sizeof vis);
        bfs(d);
        for(i=0;i<n;i++){
            if(result[i]>res){
                res = result[i];
            }
        }
        printf("Case %d: %d\n",ct,res);
    }
}
