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
struct node{
    int cost,id;
   bool operator <(const node &a)const{
        return a.cost < cost;
   }
};
priority_queue<node>Q;
vector<node>G[1005];
int dist[1005];
void dijkstra(int a,int b){
        int i,j,k;
        node s;
        s.cost = 0;
        s.id = a;
        dist[s.id] = 0;
        Q.push(s);
        while(!Q.empty()){
            node u = Q.top();
           // cout<<u.id<<" "<<u.cost<<endl;
            if(u.id == n)break;
            Q.pop();
            for(i=0;i<G[u.id].size();i++){
                node v = G[u.id][i];
                //cout<<
                if(dist[v.id] > dist[u.id] + v.cost){
                    dist[v.id] = dist[u.id] + v.cost;
                    v.cost = dist[u.id] + v.cost;
                    Q.push(v);
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
            dist[i] = 999999999;
        }
        for(i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&cst);
            node  v;
            v.id = b;
            v.cost = cst;
            G[a].push_back(v);
            v.id = a;
            v.cost = cst;
            G[b].push_back(v);
        }
        dijkstra(1,n);
        if(dist[n] == 999999999){
            printf("Case %d: Impossible\n",ct);
        }
        else{
            printf("Case %d: %d\n",ct,dist[n]);
        }
        for(i=0;i<=n;i++){
            G[i].clear();
        }
        Q = priority_queue<node>();

    }



}
