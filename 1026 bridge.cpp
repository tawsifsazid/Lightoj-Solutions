#include<bits/stdc++.h>
#define N 1005
#define  ll long long
#define pare pair<int,int>
using namespace std;

int ct=0,cases,counter=-1,res;
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
vector<int>graph[100005];
vector<pare>ans;
int parent[10006],visited[10006],disc[10006],low[10006];
void bridge(int node){
    //printf("dhukse\n");
    visited[node] = 1;
    int children = 0,i,j;
    disc[node] = low[node] = ++counter;
    //printf("disc[%d] = %d and low[%d] = %d\n",node,disc[node],node,low[node]);
    for(i=0;i<graph[node].size();i++){
        int v = graph[node][i];
        if(visited[v] == 0){
            //printf("%d connected %d\n",node,v);
            children++;
            parent[v] = node;
            bridge(v);
            low[node] = min(low[node],low[v]);
            //printf("u=%d and disc[u] = %d\nv=%d and low[v] = %d\n",node,disc[node],v,low[v]);
            if(low[v] > disc[node]){
                res++;
                if(node<v)ans.push_back(pare(node,v));
                else ans.push_back(pare(v,node));
            }
        }
        else if(v!= parent[node]){
             //printf("node = %d and v === %d\n",node,v);
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
        res = 0;
        int u,v,n,i,j,k;
        char ch,ch1;
        scanf("%d",&n);
        memset(visited, 0,sizeof visited);
        memset(parent , -1,sizeof parent);
        //memset(disc, 0 ,sizeof disc);
        //for(i=0;i<=n;i++)low[i] = 99999999;
        for(i=0;i<n;i++){
            scanf("%d %c %d %c",&u,&ch,&k,&ch1);
            for(j=1;j<=k;j++){
                scanf("%d",&v);
                graph[u].push_back(v);
            }
        }
        for(i=0;i<n;i++){
            if(visited[i] == 0){
                bridge(i);
            }
        }
        printf("Case %d:\n",ct);
        printf("%d critical links\n",res);
        sort(ans.begin(),ans.end());
        for(i=0;i<ans.size();i++){
            printf("%d - %d\n",ans[i].first,ans[i].second);
        }
        for(i=0;i<=n;i++){
            graph[i].clear();

        }
        ans.clear();
    }
}
