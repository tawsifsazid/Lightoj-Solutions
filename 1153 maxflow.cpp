#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007

int ct=0,cases,pre[105],s,d,cost[105][105],color[105],n,m;

using namespace std;

///dir array for Queen int dxq[10] = {-1,-1,-1,1,1,1,0,0};
///dir array for Queen int dyq[10] = {-1,0,1,-1,0,1,-1,1};
///dir array for knight int dxk[10] = {-2,-2,-1,-1,1,1,2,2};
///dir array for knight int dyk[10] = {1,-1,-2,2,-2,2,-1,1};
/*int leap(int year){
   	if( year%4 == 0 && year%100 == !0 )
            return 1;
	else if (year%100 == 0 && year%400 == 0)
            return 1;
	else
        return 0;
}*/
int bfs(){
   int i,j,k,v;

   memset(color,0,sizeof color);

   queue<int>Q;

   pre[s] = s;
   color[s] = 1;

   Q.push(s);

   while(!Q.empty()){
       int u = Q.front();
       Q.pop();
       for(i=1;i<=n;i++){
         if(color[i] == 0 && cost[u][i] > 0){
            color[i] = 1;
            pre[i] = u;
            Q.push(i);
         }
       }
   }

   if(color[d] == 1)return 1;
   else return 0;

}

int maxflow(){
    int i,j,k,u,v,add;
    int res = 0;

    while(bfs()){
            add = 4000000;
       u = pre[d];
       v = d;

       while(v != s){
           add = min(add,cost[u][v]);
           v = u;
           u = pre[v];
       }

       u = pre[d];
       v = d;
       while(v != s){
          cost[u][v] = cost[u][v] - add;
          cost[v][u] = cost[v][u] + add;

          v = u;
          u = pre[v];
       }

        res = res + add;
        //cout<<res<<endl;
    }
    return res;

}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int yy = 0;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&n);
        ct++;
        //if(yy > 0)printf("\n");
        //yy = 1;
        memset(cost,0,sizeof cost);
        memset(pre,0,sizeof pre);

        scanf("%d %d %d",&s,&d,&m);
        int i,j,k,a,b,c;
        for(i=1;i<=m;i++){
            scanf("%d %d %d",&a,&b,&c);
            cost[a][b] =cost[a][b] + c;
            cost[b][a] =cost[b][a] + c;
        }

        int res = maxflow();
        printf("Case %d: %d\n",ct,res);

    }

}
