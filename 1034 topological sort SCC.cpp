#include<bits/stdc++.h>
#define white 0
#define grey 1
#define black 2
using namespace std;

int res,ct=0,cases,n,m,flag;
vector<int>graph[200000];
stack<int>Q;
bool cycle ;
int visited[200000];
int dfs(int node){
    visited[node] = grey;
    int i,j;
    for(i=0;i<graph[node].size();i++){
        int u = graph[node][i];
       if(flag==0){
            if(visited[u] == white){
                visited[u]  = grey;
                dfs(u);
            }
            else if(visited[u] == grey){
                cycle = false;
            }
       }
       else if (flag==1){
            if(visited[u] == white){
                visited [u] = grey;
                dfs(u);
            }
       }
    }
    if(flag==0){
        //printf("rakhlo %d k \n",node);
        visited[node] = black;
        Q.push(node);
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    int i,j,a,b;
    while(cases--){
        ct++;
        scanf("%d %d",&n,&m);
        memset(visited , white ,sizeof visited);
        for(i=0;i<=100000;i++)graph[i].clear();
        cycle = true;
        flag = 0;
        res=0;
        for(i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
        }
        for(i=1;i<=n;i++){
            if(visited[i] == white){
                dfs(i);
            }
        }
        memset(visited,white,sizeof visited);
        flag = 1;
        while(!Q.empty()){
            int now = Q.top();
            Q.pop();
            if(visited[now]== white ){
                dfs(now);
                res++;
            }
        }
        printf("Case %d: %d\n",ct,res);
    }
}
