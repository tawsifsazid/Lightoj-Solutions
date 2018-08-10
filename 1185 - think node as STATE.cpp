#include<bits/stdc++.h>
#define pare pair<int,int>
using namespace std;

int res,ct=0,cases,s,d,r,a,b,state[400][2],fl,n,m;
vector<int>graph[1000];
queue<pare>Q;
void bfs(int node){
    int i,j,x,y;
    //printf("ekhon sada ase %d %d tey = %c\n",row,col,A[row][col]);
    Q.push(pare(node,0));
    state[node][0]=0;
    //printf("%d = Carry\n",node);
    res++;
    while(!Q.empty()){
        pare now = Q.front();
        int x = now.first,u;
        int y = now.second;
        Q.pop();
        for(i=0;i<graph[x].size();i++){
              fl = 1;
              u = graph[x][i];
              if(now.second == 0 && state[u][1]==-1){
                  state[u][1] = 1;
                  //printf("%d = Running\n",u);
                  Q.push(pare(u,1));
              }
              else if(now.second == 1 && state[u][0]==-1){
                  state[u][0]= 0;
                  //printf("%d = Carry\n",u);
                  Q.push(pare(u,0));
                  res++;
              }
        }
    }
}

int main(){
    int i,j;
    scanf("%d",&cases);
    while(cases--){
        ct++;
        res=0;
        fl=0;
        memset(state,-1,sizeof state);
        for(i=1;i<=100;i++)graph[i].clear();
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bfs(1);
        if(fl==1)printf("Case %d: %d\n",ct,res);
        else{
            printf("Case %d: 0\n",ct);
        }
    }
}
