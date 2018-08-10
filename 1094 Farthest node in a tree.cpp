#include<bits/stdc++.h>
#define pare pair<int,int>
using namespace std;

int res,ct=0,cases,n,visited[30005],fl,next,tot[30005],a,b,w,large,realres,node1,node2;
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
                   if(tot[graph[now][i]]>res){
                        res = tot[graph[now][i]];
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
    visited[node1]=1;
    Q.push(node1);
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        for(i=0;i<graph[now].size();i++){
            if(visited[graph[now][i]]==0){
               if(graph[now][i]==node2 || fl==0){
                    tot[graph[now][i]] = tot[now] + cost[now][i];
                    if(graph[now][i]==node2)fl=1;
               }
                //printf("%d\n",res);
                Q.push(graph[now][i]);
                visited[graph[now][i]] = 1;
            }
        }
    }
    //printf("\n");
}
void init(){
    memset(visited,0,sizeof visited);
    memset(tot,0,sizeof tot);
    res=0;
    large = 0;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>cases;
    int i,j;
    while(cases--){
        cin>>n;
        ct++;
        memset(visited,0,sizeof visited);
        memset(tot,0,sizeof tot);
        fl=0;
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
        //printf("n2 = %d\n",node2);
        init();
        bfsfrom_a_to_b(node1,node2);
        realres = tot[node2];
        //printf("node1 = %d && node2 = %d\n",node1,node2);
        printf("Case %d: %d\n",ct,realres);
    }

}
