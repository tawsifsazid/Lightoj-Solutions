#include<bits/stdc++.h>
#define N 1005
#define  ll long long
using namespace std;

int ct=0,cases,counter = 0,res[10010];
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
int visited[10010],parent[10010],disc[10010],low[10010];
vector<int>graph[10010];
void AP(int node){
    visited[node] = 1;
    disc[node] = low[node] = ++counter;
    int i,j,v,u,children = 0;
    for(i=0;i<graph[node].size();i++){
        v = graph[node][i];
        if( visited[v] == 0){
            children++;
            parent[v] = node;
            AP(v);
            low[node] = min(low[node],low[v]);
            if(parent[node] == -1 && children > 1){
                res [node] = 1;
                //printf("hehe %d %d\n",node,v);
            }
            else if(parent[node] != -1 && low[v] >= disc[node]){
                //printf("hehe %d %d\n",node,v);
                res[node] = 1;
            }
        }
        else if(v != parent[node]){
            low[node] = min(low[node],disc[v]);
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        memset(visited,0,sizeof visited);
        memset(parent,-1,sizeof parent);
        memset(res,0,sizeof res);
        int a,b,n,m,i,j,k;
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(i=1;i<=n;i++){
            if(visited[i] == 0){
                AP(i);
            }
        }
        int ans = 0;
        for(i=1;i<=n;i++){
            if(res[i] == 1){
                ans++;
            }
        }
        printf("Case %d: %d\n",ct,ans);
        for(i=1;i<=n;i++){
            graph[i].clear();
        }
    }
}
