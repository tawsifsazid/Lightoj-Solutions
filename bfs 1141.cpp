#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007
using namespace std;

int ct=0,cases,s,t;
vector<int>P;
int flag[1005],vis[1005],level[1005];
void sieve(){
    P.push_back(2);
    int i,j,k;
    memset(flag,-1,sizeof flag);
    for(i=3;i<=1000;i=i+2){
        if(flag[i] == -1){
            P.push_back(i);
            //cout<<i<<endl;
        }
        if(flag[i] == -1){
            for(j=i*i;j<=1000;j=j+i){
                flag[j] = 1;
            }
        }
    }
}
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
void bfs(int node){
    vis[node] = 1;
    int i,j,k;
    queue<int>Q;
    Q.push(node);
    vis[node] = 1;
    level[node] = 0;
    while(!Q.empty()){
            int u = Q.front();
            //cout<<"now node "<<u<<endl;
            Q.pop();
            //if(vis[u] == t)break;
        for(i=0;i<P.size() && P[i]<u;i++){
            int v = u;
            //cout<<v<<" "<<P[i]<<endl;
            if(v % P[i] == 0 && v<1001){
                v = v + P[i];
                if(vis[v] == 0){
                    //cout<<v<<endl;
                    vis[v] = 1;
                    level[v] = level[u] + 1;
                    //if(vis[v] == t)break;
                    if(v <= 1000)Q.push(v);
                }
            }
           //if(i == 2)break;
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    sieve();
    scanf("%d",&cases);
    while(cases--){
        ct++;
        scanf("%d %d",&s,&t);
        memset(vis,0,sizeof vis);
        memset(level,0,sizeof level);
        bfs(s);
        if(vis[t] == 0){
            printf("Case %d: %d\n",ct,-1);
        }
        else printf("Case %d: %d\n",ct,level[t]);

    }
}
