#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007
using namespace std;

int ct=0,cases,n,m;
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
vector<int>graph[10005];
int vis[10005],cost[10005],sum;
int bfs(int node){
    queue<int>Q;
    vis[node] = 1;
    Q.push(node);
    int check = 0,ans = 0;
    int i,j,k;
    while(!Q.empty()){
       int u = Q.front();
       check++;
       ans = ans + cost[u];
       Q.pop();
        for(i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            if(vis[v] == 0){
                vis[v] = 1;

                Q.push(v);
            }
        }
    }
    if(ans / check == sum){
          //  cout<<"asdasdasdsa"<<endl;
            return 1;
    }
    else return 0;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        int fl = 0;
        sum = 0;
        memset(vis,0,sizeof vis);
        memset(cost,0,sizeof cost);
        int i,j,k;
        scanf("%d %d",&n,&m);
        for(i=0;i<=n;i++){
            graph[i].clear();
        }

        int a,b,res = 0;
         for(i=1;i<=n;i++){
            scanf("%d",&a);
            cost[i] = a;
            res = res + a;
        }
        for(i=0;i<m;i++){
                scanf("%d %d",&a,&b);
                graph[a].push_back(b);
                graph[b].push_back(a);
        }

      if(res % n != 0)printf("Case %d: No\n",ct);
      else{
            sum = res/n;
            //cout<<"sum "<<sum<<endl;
            for(i=1;i<=n;i++){
                if(vis[i] == 0){
                   int what =  bfs(i);
                   //cout<<"what "<<what<<endl;
                   if(what == 0){
                      //  cout<<"dhukse"<<endl;
                    fl = 1;
                    break;
                   }
                }
            }


            if(fl == 1)printf("Case %d: No\n",ct);
            else printf("Case %d: Yes\n",ct);

      }
    }

}
