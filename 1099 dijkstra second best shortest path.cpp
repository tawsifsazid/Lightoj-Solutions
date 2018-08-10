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

struct edge{
    int weight,connected;
};

struct node{
    int index,cost,num;

   bool operator <(const node &a)const{
        return a.cost < cost;
   }
};
vector<edge>graph[100005];
priority_queue< node >Q;
int dist[3][5005];
void dijkstra(int a,int b){
    dist[1][a] = 0;
    node aa;
    aa.index = a;
    aa.cost = 0;
    aa.num = 1;
    Q.push(aa);
    while(!Q.empty()){
        int numb = Q.top().num;
        int ind = Q.top().index;
        int cst = Q.top().cost;
        Q.pop();
        for(int i=0;i<graph[ind].size();i++){
            int v  = graph[ind][i].connected;
            int c  = graph[ind][i].weight;
            //cout<<ind << " checking " <<v<< " "<<endl;
            node vv;
            int check = dist[numb][ind] + c;
            if(dist[1][v] > check){
                dist[2][v] = dist[1][v];
                vv.index = v;
                vv.cost = dist[2][v];
                vv.num = 2;
                Q.push(vv);

                dist[1][v] = check;
                vv.index = v;
                vv.cost = dist[1][v];
                vv.num = 1;
                Q.push(vv);
                //cout<<" if "<<vv.index<<"  "<<dist[1][vv.index] <<" "<<dist[2][vv.index]<<endl;
            }
            else if(dist[1][v] < check && dist[2][v] > check){
                dist[2][v] = check;
                vv.index = v;
                vv.cost = dist[2][v];
                vv.num = 2;
                Q.push(vv);
                //cout<<"else if "<<vv.index<<"  "<<dist[1][vv.index] <<" "<<dist[2][vv.index]<<endl;
            }
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        int i,j,k,n,m,a,b,cst;
        scanf("%d %d",&n,&m);
        //memset(dist,0,sizeof dist);
        for(i=1;i<=n;i++){
          dist[1][i] = 999999999;
          dist[2][i] = 999999999;
        }
        for(i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&cst);
           edge cc;
           cc.connected = b;
           cc.weight = cst;
           graph[a].push_back(cc);
           cc.connected = a;
           cc.weight = cst;
           graph[b].push_back(cc);
        }
        dijkstra(1,n);
       printf("Case %d: %d\n",ct,dist[2][n]);

        for(i=0;i<=n;i++){
            graph[i].clear();
        }
        Q = priority_queue<node>();

    }



}



