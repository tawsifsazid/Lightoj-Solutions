#include<bits/stdc++.h>
#define white 0
#define grey 1
#define black 2
bool cycle;
using namespace std;

int ct=0,cases,n,M;
vector<int>graph[20000];
int vis[20000];
map<string,int>m;
void init(){
    memset(vis,white,sizeof vis);
    int i;
    for(i=0;i<=10005;i++){
        graph[i].clear();
    }
    m.clear();
    cycle = true;
    //topo.clear();
    //while(!topo.empty()){
    //    topo.pop();
    //}
}
void top(int node){
    int i,j;
    vis[node] = grey ;
    for(i=0;i<graph[node].size();i++){
        int u = graph[node][i];
        if(vis[u] == white ){
            vis[u] = grey;
            top(u);
        }
        else if (vis[u]==grey){
            //printf("%d\n",u);
            cycle = false ;
        }
    }
    vis[node] = black;
    //topo.push(node);
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    int i,j,k;
    string a,b;
    while(cases--){
        ct++;
        k=0;
        scanf("%d",&M);
        init();
        for(i=1;i<=M;i++){
            cin>>a>>b;
            if(m[a]==0){
                k++;
                m[a]=k;
            }
            if(m[b]==0){
                k++;
                m[b]=k;
            }
            graph[m[a]].push_back(m[b]);
        }
        for(i=1;i<=k;i++){
            if(vis[i]==white){
                top(i);
            }
        }
        if(cycle == false)printf("Case %d: No\n",ct);
        else{
            printf("Case %d: Yes\n",ct);
        }
    }
}
