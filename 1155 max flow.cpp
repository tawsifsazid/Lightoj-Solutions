#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007
#define INF 987654321
int ct=0,cases,pre[305],s,d,cost[305][305],color[305],n,m;

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
       for(i=1;i<=n + n + 1;i++){
         if(color[i] == 0 && cost[u][i] > 0){
            color[i] = 1;
            pre[i] = u;
            Q.push(i);
            if(color[d] == 1)return 1;
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
       u = pre[d];
       v = d;
       add = INF;
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

        ct++;
        scanf("%d",&n);
        //if(yy > 0)printf("\n");
        //yy = 1;
        memset(cost,0,sizeof cost);
        //memset(pre,0,sizeof pre);

        int i,j,k,a,b,c;

        s = 0;
        d = n + n + 1;

        int node[205];


        for(i=1;i<=n;i++){
            scanf("%d",&node[i]);
        }

        scanf("%d",&m);

        for(i=1;i<=m;i++){
           scanf("%d %d %d",&a,&b,&c);
           cost[a][a + n] = node[a];
           cost[a+n][b] = cost[a+n][b] + c;
           cost[b][n+b] = node[b];
        }

        scanf("%d %d",&a,&b);
        //cout<<"asdasd"<<endl;
        for(i=1;i<=a;i++){
           scanf("%d",&k);
           cost[s][k] = node[k];
        }

        for(i=1;i<=b;i++){
           scanf("%d",&k);
           cost[n+k][d] = INF;
        }

        int res = maxflow();
        printf("Case %d: %d\n",ct,res);

    }

}
