#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define pare pair<int,int>
using namespace std;

int ct=0,cases,n,m;
int L[55],R[55],vis[55];
vector<int>graph[2505];
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
struct marriage{
    int age,divorce,height;

}man[55],girl[55];
bool tryk(int s){
    if(vis[s] == 1)return false;
    vis[s] = 1;
    for(int i= 0;i<graph[s].size();i++){
        int v = graph[s][i];
        if(R[v] == -1 || tryk(R[v])){
            R[v] = s;
            L[s] = v;
            return true;
        }
    }
    return false;
}
int kuhn(){
    int i,j,k,res =  0;
    memset(L,-1,sizeof L);
    memset(R,-1,sizeof R);
    for(i=1;i<=m;i++){
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
        int i,j,k;
        scanf("%d %d",&m,&n);
        for(i=1;i<=m;i++){
            scanf("%d %d %d",&man[i].height,&man[i].age,&man[i].divorce);
        }
        for(i=1;i<=n;i++){
            scanf("%d %d %d",&girl[i].height,&girl[i].age,&girl[i].divorce);
        }

        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                    int h = abs(man[i].height-girl[j].height);
                    int ad = abs(man[i].age-girl[j].age);
                if(h<=12 && ad<=5 && man[i].divorce ==   girl[j].divorce){
                    graph[i].push_back(j);
                }
            }
        }
        int ans = kuhn();
        printf("Case %d: %d\n",ct,ans);
        for(i=0;i<=m;i++){
            graph[i].clear();
        }
    }
}
