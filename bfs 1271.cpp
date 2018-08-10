#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007
using namespace std;

int ct=0,cases,vis[50005],n,high,path[50005];
int A[50005];
vector<int>graph[50005];
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
void bfs(int node,int en){
    vis[node] = 1;
    queue<int>Q;
    Q.push(node);
    int i,j,k;
    while(!Q.empty()){
        int u = Q.front();
        if(u == en)break;
        Q.pop();
        for(i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            if(vis[v] == 0){
                vis[v] =  1;
                path[v] = u;
                //if(u == 1)cout<<v<<endl;
                //cout<<a<<" push "<<v<<endl;
                Q.push(v);
            }
        }
    }
}
void print(int u,int v){
    if(v == u){
        printf("%d",v);
        return;
    }
    else{
        print(u,path[v]);
        printf(" %d",v);
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        int i,j,k,n;
        ct++;
        scanf("%d",&n);
        high = -1;
        memset(path,-1,sizeof path);
        memset(vis,0,sizeof vis);
        for(i=0;i<=50000;i++){
            graph[i].clear();
        }

        for(i=0;i<n;i++){
            scanf("%d",&A[i]);
        }
        for(i=1;i<n;i++){
            graph[A[i-1]].push_back(A[i]);
            //cout<<A[i-1]<<" "<<A[i]<<endl;
            graph[A[i]].push_back(A[i-1]);
        }
        for(i=0;i<n;i++){
            sort(graph[A[i]].begin(),graph[A[i]].end());
        }
    //for(i=0;i<n;i++){
    //    for(j=0;j<graph[A[i]].size();j++){
       //     cout<<graph[A[i]][j];
    //    }
     //   cout<<endl;
    //}
        bfs(A[0],A[n-1]);
        printf("Case %d:\n",ct);
        print(A[0],A[n-1]);
        printf("\n");

    }


}
