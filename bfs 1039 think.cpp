#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007
using namespace std;

int ct=0,cases,n,res = 0;
string a,b;
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
map<string,int>vis;
map<string,int>level;
map<string,int>no;
void bfs(string node){
    if(no[node] == 1)return ;
    queue<string>Q;
    vis[node] = 1;
    level[node] = 0;
    Q.push(node);
    int i,j,k;
    while(!Q.empty()){
        string u = Q.front();
        if(u == b)break;
        Q.pop();
        for(i=0;i<3;i++){
            string v  = u;
            if(u[i] == 'a'){
                v[i] = u[i] + 1;
                 if(no[v] != 1 && vis[v] != 1){
                    level[v] = level[u] + 1;
                    vis[v] = 1;
                    Q.push(v);
                 }
                  v[i] = 'z';
                 if(no[v] != 1 && vis[v] != 1){
                    level[v] = level[u] + 1;
                    vis[v] = 1;
                    Q.push(v);
                 }
            }
            else if(u[i] == 'z'){
                v[i] = 'a';
                if(no[v] != 1 && vis[v] != 1){
                    level[v] = level[u] + 1;
                    vis[v] = 1;
                    Q.push(v);
                 }
                 v[i] = u[i] - 1;
                 if(no[v] != 1 && vis[v] != 1){
                    level[v] = level[u] + 1;
                    vis[v] = 1;
                    Q.push(v);
                 }
            }
            else{
                v[i] = u[i] + 1;
                 if(no[v] != 1 && vis[v] != 1){
                    level[v] = level[u] + 1;
                    vis[v] = 1;
                    Q.push(v);
                 }
                v[i] = u[i] - 1;
                 if(no[v] != 1 && vis[v] != 1){
                    level[v] = level[u] + 1;
                    vis[v] = 1;
                    Q.push(v);
                 }
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
        scanf("%d",&n);
        vis.clear();
        level.clear();
        no.clear();
        string c,d,e;
        int i,j,k,u,v;
        cin>>a>>b;
        scanf("%d",&v);
        for(int m=0;m<v;m++){
            cin>>c>>d>>e;
            string tmp="";
            for(i=0;i<c.size();i++){
                for(j=0;j<d.size();j++){
                    for(k=0;k<e.size();k++){
                       tmp = tmp + c[i]+d[j]+e[k];
                       //cout<<tmp<<endl;
                       no[tmp] = 1;
                       tmp.clear();
                    }
                }
            }
        }
        cout<<"Case "<<ct<<": ";
        bfs(a);
        if(no[a] == 1 || no[b] == 1){
              cout<<"-1"<<endl;
        }
        else if(level[b] == 0 && b==a){
            cout<<level[b]<<endl;
        }
        else if(level[b] == 0 && b!=a){
            cout<<"-1"<<endl;
        }
        else{
            cout<<level[b]<<endl;
        }
    }
}
