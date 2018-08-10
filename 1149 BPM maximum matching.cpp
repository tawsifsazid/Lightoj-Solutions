#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define pare pair<int,int>
using namespace std;

int ct,cases,n,m,s,v,A[105],B[105];
///dir array for Queen int dxq[10] = {-1,-1,-1,1,1,1,0,0};
///dir array for Queen int dyq[10] = {-1,0,1,-1,0,1,-1,1};
///dir array for knight int dxk[10] = {-2,-2,-1,-1,1,1,2,2};
///dir array for knight int dyk[10] = {1,-1,-2,2,-2,2,-1,1};

vector<int>graph[105];
int L[105],R[105];
int vis[105];
bool tryk(int s){
    if(vis[s] == 1)return false;

    vis[s] = 1;
    int i,j,k;
    for(i=0;i<graph[s].size();i++){
        int v = graph[s][i];
        if(R[v]==-1 || tryk(R[v])){
            L[s] = v;
            R[v] = s;
            return true;
        }
    }
    return false;
}
int kuhn(){
    int i,j,k,res=0;
    memset(L,-1,sizeof L);
    memset(R,-1,sizeof R);
    for(i=0;i<n;i++){
        memset(vis,0,sizeof vis);
        if(tryk(i)){
            res++;
        }

    }
    return res;
}


int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
            ct++;
        int i,j,k=1;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&A[i]);

        }
        scanf("%d",&m);
        for(j=0;j<m;j++){
            scanf("%d",&B[j]);

        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if((A[i]!=0  && B[j] % A[i] == 0)|| B[j]==0){

                     //printf("%d connecte")
                    graph[i].push_back(j);
                    //graph[B[]
                }
            }
        }

        int maxres=kuhn();
        //printf("max = %d\n and n = %d\n",maxres,n);
        printf("Case %d: %d\n",ct,maxres);
        for(i=0;i<=101;i++){
            graph[i].clear();
        }

    }
}
