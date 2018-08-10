#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define pare pair<int,int>
using namespace std;

int ct,cases,n,m;
vector<int>graph[1005];
int color[1005],L[1005],R[1005],vis[1005];
queue<int>Q;
bool tryk(int s){
    if(vis[s] == 1)return false;
      vis[s] = 1;
    for(int i=0;i<graph[s].size();i++){
        int v = graph[s][i];
        if(R[v]==-1 || tryk(R[v])){
            R[v] = s;
            L[s] = v;
            return true;
        }
    }
    return false;
}
int kuhn(){
    memset(L,-1,sizeof L);
    memset(R,-1,sizeof R);
    int res = 0;
    for(int i =1;i<=n;i++){
        memset(vis,0,sizeof vis);
        if(color[i]==1 && tryk(i)){
            res++;
        }
    }
    return res;
}
void  bfs(int node){
    int black=0,white=0;
    //vis[node]=1;
    color[node]=1;
    Q.push(node);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            //cout<<"size = "<<graph[u].size();
            //printf("v =%d\n",v);
            if(color[v] == 0){
                //vis[v]=1;
                if(color[u]==1){
                    color[v]=2;

                }
                else{
                    color[v]=1;
                }
                Q.push(v);
            }
        }
    }

}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        scanf("%d %d",&n,&m);
        int i,j,k,a,b;
        //memset(vis,0,sizeof vis);
        memset(color,0,sizeof color);
        for(i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(i=1;i<=n;i++){
            if(color[i]==0){
                bfs(i);
            }
        }
        int ans = kuhn();

        printf("Case %d: %d\n",ct,n-ans);
        for(i=0;i<=1000;i++){
            graph[i].clear();
        }
    }
}
