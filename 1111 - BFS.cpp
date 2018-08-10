#include<bits/stdc++.h>

using namespace std;

int k,res,ct=0,cases,n,m,a,b,person[105],place[2000];
vector<int>graph[2000];
int visited[2000];
queue<int>Q;
void bfs(int node){
    int i,j;
    Q.push(node);
    visited[node]=1;
    place[node]++;
        while(!Q.empty()){
            int now = Q.front();
            Q.pop();
            for(i=0;i<graph[now].size();i++){
               if(visited[graph[now][i]]==0){
                    //printf("%d jaite pare %d tey\n",now,graph[now][i]);
                    visited[graph[now][i]]=1;
                    //printf("jaygatir %d er mann %d\n",graph[now][i],visited[graph[now][i]]);
                    Q.push(graph[now][i]);
                    place[graph[now][i]]++;
               }
            }
        }
            //printf("%d\n",min(color1,color2));
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i,j;
    scanf("%d",&cases);
    while(cases--){
         ct++;
         scanf("%d %d %d",&k,&n,&m);
         res=0;
         memset(visited ,0,sizeof visited);
         memset(person,0,sizeof person);
         memset(place , 0, sizeof place);
         Q = queue<int>();
         for(i=1;i<=n;i++)graph[i].clear();
         for(i=1;i<=k;i++){
            scanf("%d",&a);
            person[i]=a;
            //printf("%d lives in %d\n",i,a);
         }
         for(i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
         }
         for(i=1;i<=k;i++){
             if(person[i]!=0){
                memset(visited ,0,sizeof visited);
                bfs(person[i]);
             }
            //printf("%d lives in %d\n",i,a);
         }
         for(i=1;i<=n;i++){
             if(place[i]==k){
                res++;
             }
            //printf("%d lives in %d\n",i,a);
         }
         printf("Case %d: %d\n",ct,res);
    }

}
