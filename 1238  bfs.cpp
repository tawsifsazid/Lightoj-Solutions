#include<bits/stdc++.h>
#define pare pair<int,int>
using namespace std;

int k,res,ct=0,cases,n,visited[25][25],fl,next,path[25][25],ase,m;
int dx[10] = {0,0,1,-1};
int dy[10] = {1,-1,0,0};
char A[25][25];
queue<pare>Q;
int isvalid(int x, int y){
    if(x<n && x>=0 && y<m && y>=0 && visited[x][y]!=1 && A[x][y]!='#' && A[x][y]!='m' && ( A[x][y]=='h' || (A[x][y]>=97 && A[x][y]<=99) || A[x][y]=='.' )){
        return 1;
    }
    else{
        return 0;
    }
}
void bfs(int row,int col){
    int i,j,x,y;
    visited[row][col]=1;
    path[row][col]=0;
    //printf("ekhon sada ase %d %d tey = %c\n",row,col,A[row][col]);
    Q.push(pare(row,col));
    while(!Q.empty()){
        pare top = Q.front();
        Q.pop();
        for(i=0;i<4;i++){
            x = top.first + dx[i];
            y = top.second + dy[i];
            //printf("for %d %d checking %d %d\n",top.first,top.second,x,y);
            if(isvalid(x,y) && visited[x][y]==0){
                visited[x][y]=1;
                path[x][y] = path[top.first][top.second] + 1;
                if(A[x][y]=='h'){
                    res = max(res,path[x][y]);
                }
                Q.push(pare(x,y));
            }
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>cases;
    int i,j;
    while(cases--){
        cin>>n>>m;
        ct++;
        res=0;
        memset(visited,0,sizeof visited);
        memset(path,0,sizeof path);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>A[i][j];
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(A[i][j]>=97 && A[i][j]<=99){
                    memset(visited,0,sizeof visited);
                    memset(path,0,sizeof path);
                    if(A[i][j]=='a'){
                        bfs(i,j);
                    }
                    else if(A[i][j]=='b'){
                        bfs(i,j);
                    }
                    else if(A[i][j]=='c'){
                        bfs(i,j);
                    }
                }
            }
        }
        printf("Case %d: %d\n",ct,res);
    }

}
