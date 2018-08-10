#include<bits/stdc++.h>

using namespace std;

int k,res,ct=0,cases,n;
vector<int>graph[20005];
int color[20005];
queue<int>Q;
void bfs(){
    int i,j,now,vamp,lyken;
    for(i=0;i<=20000;i++){
          vamp = 0;
          lyken = 0;
        if(!graph[i].empty() && color[i]==0){
            color[i]=1;
            //printf("%d == vamp\n",i);
            vamp++;
             //printf("vamp = %d\n",vamp);
            Q.push(i);
            while(!Q.empty()){
                 now = Q.front();
                 //printf("now for %d\n",now);
                Q.pop();
                    for(i=0;i<graph[now].size();i++){
                        if(color[graph[now][i]]==0){
                            if(color[now]==1){
                                color[graph[now][i]]=2;
                                lyken++;
                                //printf("%d = lyken\n",graph[now][i]);
                            }
                            else{
                                color[graph[now][i]]=1;
                                vamp++;
                               //printf("%d == vamp\n",graph[now][i]);
                            }
                            Q.push(graph[now][i]);
                        }
                    }
            }
            res = res + max(vamp,lyken);
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i,j;
    scanf("%d",&cases);
    while(cases--){
        ct++;
        res=0;
        memset(color,0,sizeof color);
        Q=queue<int>();
        for(i=0;i<=20000;i++)graph[i].clear();
        scanf("%d",&n);
        int u,v;
        for(i=1;i<=n;i++){
            scanf("%d %d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bfs();
        printf("Case %d: %d\n",ct,res);
    }
}
