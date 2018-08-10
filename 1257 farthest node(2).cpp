#include<bits/stdc++.h>
#define pare pair<int,int>
using namespace std;

int res[30005],res1,ct=0,cases,n,visited[30005],next,tot[30005],a,b,w,large,realres,node1,node2;
vector<int>graph[30005];
vector<int>cost[30005];
queue<int>Q;
void bfs(int node){
    int i,j;
    visited[node]=1;
    Q.push(node);
    tot[node] = 0;
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        for(i=0;i<graph[now].size();i++){
            if(visited[graph[now][i]]==0){
                //printf("%d\n",res);
                tot[graph[now][i]] = tot[now] + cost[now][i];
                   if(tot[graph[now][i]]>res1){
                        res1 = tot[graph[now][i]];
                        large = graph[now][i];
                        //printf("%d\n",large);
                    }
                Q.push(graph[now][i]);
                visited[graph[now][i]] = 1;
            }
        }
    }
    //printf("shesh\n");
    //realres = max(res,realres);
}
void bfsfrom_a_to_b(int node1,int node2){
    int i,j;
    //printf("asdsadssad %d %d\n",node1,node2);
    visited[node1]=1;
    Q.push(node1);
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        for(i=0;i<graph[now].size();i++){
            if(visited[graph[now][i]]==0){
                    tot[graph[now][i]] = tot[now] + cost[now][i];
                    if(tot[graph[now][i]]>res[graph[now][i]]){
                        res[graph[now][i]] = tot[graph[now][i]];
                        //printf("%d = %d\n",graph[now][i],res[graph[now][i]]);
                    }
                //printf("%d\n",res);
                Q.push(graph[now][i]);
                visited[graph[now][i]] = 1;
            }
        }
    }
}
void init(){
    memset(visited,0,sizeof visited);
    memset(tot,0,sizeof tot);
    res1 = 0;
    large = 0;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    int i,j;
    while(cases--){
        scanf("%d",&n);
        ct++;
        memset(visited,0,sizeof visited);
        memset(res,0,sizeof res);
        memset(tot,0,sizeof tot);
        for(i=0;i<=n;i++){
            graph[i].clear();
            cost[i].clear();
        }
        for(i=0;i<n-1;i++){
            scanf("%d %d %d",&a,&b,&w);
            graph[a].push_back(b);
            graph[b].push_back(a);
            cost[a].push_back(w);
            cost[b].push_back(w);
        }
        init();
        realres=0;
        bfs(0);
        node1 = large;
        //printf("n1 = %d\n",node1);
        init();
        bfs(node1);
        node2 = large;
        init();
        bfsfrom_a_to_b(node1,node2);
        init();
        bfsfrom_a_to_b(node2,node1);
        printf("Case %d:\n",ct);
        //printf("node1 = %d && node2 = %d farthest node %d\n",node1,node2,large);
        for(i=0;i<n;i++){
            printf("%d\n",res[i]);
        }
    }

}
