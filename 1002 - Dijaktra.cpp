#include<bits/stdc++.h>

using namespace std;
struct edge{
    int connected,cost;
};
struct state{
    int nodecost,nodevalue;
      bool operator < (const state &a)const{
        //printf("ekhon state %d and a.nodecost = %d\n",nodecost,a.nodecost);
        return nodecost > a.nodecost;
    };
};
priority_queue<state>Q;
vector<edge>graph[20000];
int dist[600];
void dj(int s){
    state source;
    dist[s] = 0;
    source.nodecost = 0;
    source.nodevalue = s;
    Q.push(source);

    int i;
    while(!Q.empty()){
       state now = Q.top();
        int y = now.nodevalue;
        int x = now.nodecost;
        Q.pop();
        for(i=0;i < graph[y].size();i++){
            //printf("graph size = %d\n",graph[y].size());
            int nownode = graph[y][i].connected;
            int nownodecost = graph[y][i].cost;
            if(dist[nownode] > max(x,nownodecost)){
                dist[nownode] = max(x,nownodecost);
                //printf("%d er distance = %d FROM %d\n",nownode,dist[nownode],y);
                state B ;
                B.nodecost = max(x,nownodecost);
                B.nodevalue = nownode;
                Q.push(B);
                //printf("pushong %d\n",nownode);
            }
        }
        //printf("dhukse");
    }
}
int n,m,t,cases,ct=0,u,v,cst;
int main(){
    scanf("%d",&cases);
    int i,j;
    while(cases--){
        ct++;
        for(i=0;i<=500;i++)dist[i]=30000000;
        for(i=0;i<=19000;i++)graph[i].clear();
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++){
          edge A;
          scanf("%d %d %d",&u,&v,&cst);
            A.connected = v;
            A.cost = cst;
            graph[u].push_back(A);
             A.connected = u;
             A.cost = cst;
            graph[v].push_back(A);
        }
        int t;
        scanf("%d",&t);
        dj(t);
        printf("Case %d:\n",ct);
        for(i=0;i<n;i++){
            if(dist[i]!=30000000){
                printf("%d\n",dist[i]);
            }
            else{
                printf("Impossible\n");
            }
        }
    }
}


