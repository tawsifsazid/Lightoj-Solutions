#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define pare pair<int,int>
using namespace std;

int ct,cases,n,m;
int dp[1005][3];
///dir array for Queen int dxq[10] = {-1,-1,-1,1,1,1,0,0};
///dir array for Queen int dyq[10] = {-1,0,1,-1,0,1,-1,1};
///dir array for knight int dxk[10] = {-2,-2,-1,-1,1,1,2,2};
///dir array for knight int dyk[10] = {1,-1,-2,2,-2,2,-1,1};
/*int leap(int a){
    if(a%4==0){
        if(a%100==0){
            if(a%400==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}*/
vector<int>graph[1005];
int L[1005],R[1005],vis[1005];
bool tryk(int s){
    //printf("s = %d and %d\n",s,vis[s]);
    if(vis[s] == 1)return false;
    vis[s] = 1;
    //cout<<graph[s].size()<<"eaeses"<<endl;

    for(int i = 0; i<graph[s].size(); i++){

        int v = graph[s][i];
        //printf("dhuklo %d\n",v);
        if(R[v] == -1 || tryk(R[v])){
            L[s] = v;
            R[v] = s;
            return true;
        }
    }
    return false;

}
int kuhn(){
    int res = 0;
    memset(L,-1,sizeof L);
    memset(R,-1,sizeof R);
    //int res = 0;
    for(int i=1;i<=n;i++){
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
        scanf("%d %d",&n,&m);
        int i,j,k,a,b;
        for(i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
        }
        int maxres = kuhn();
        printf("Case %d: %d\n",ct,n-maxres);
        for(i=0;i<=1000;i++){
            graph[i].clear();
        }
    }
}
