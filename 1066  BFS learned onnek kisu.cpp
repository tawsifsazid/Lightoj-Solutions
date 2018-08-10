#include<bits/stdc++.h>
#define pare pair<int,int>
using namespace std;

int k,res,ct=0,cases,n,visited[15][15],fl,next,path[15][15],ase;
int dx[10] = {0,0,1,-1};
int dy[10] = {1,-1,0,0};
char A[15][15];
queue<pare>Q;
int isvalid(int x, int y){
    if(x<n && x>=0 && y<n && y>=0 && visited[x][y]!=1 && A[x][y]!='#' && (A[x][y]==('A'+next) || A[x][y]=='.' || A[x][y]<('A' + next))){
        return 1;
    }
    else{
        return 0;
    }
}
void bfs(int row,int col){
    int i,j,x,y,yup=0;
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
                //printf("now valid %d %d= %c\n",x,y,A[x][y]);
                if(A[x][y]==('A' + next)){
                        path[x][y] = path[top.first][top.second] + 1;
                        res = res + path[x][y];
                         //printf("paisi %d %d storing path = %d\n",x,y,res);
                         yup=1;
                }
                else{
                    path[x][y]=path[top.first][top.second] + 1;
                    //printf("ekhon vitore ase %d %d tey VISITED= %c path =%d\n",x,y,A[x][y],path[x][y]);
                }
                visited[x][y]=1;
                //printf("pushing %c\n",A[x][y]);
                Q.push(pare(x,y));
            }
        }
    }
    if(yup==0 && next < ase)fl=0;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i,j,cnt;
    cin>>cases;
    while(cases--){
        ct++;
        cin>>n;
        next=0;
        fl=1;
        k=0;
        ase=0;
        res=0;
        memset(visited, 0 , sizeof visited);
        memset(path, 0 , sizeof path);
        Q=queue<pare>();
        int store1,store2;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin>>A[i][j];
                if(A[i][j]>=65 && A[i][j]<=90){
                    ase++;
                    if(A[i][j]=='A'){
                        store1 = i;
                        store2 = j;
                    }
                   // printf("ase = %d\n",ase);
                }
            }
        }
        cnt=0;
       for(int u = cnt ; u<ase ;u++){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                        //printf("%d %d\n",i,j);
                    if(A[i][j]==('A' + u)){
                        memset(visited,0, sizeof visited);
                        memset(path,0, sizeof path);
                        next++;
                        //printf("now going %c next=%d cnt=%d\n",A[i][j],next,cnt);
                        if(fl==1)bfs(i,j);
                        else{
                            break;
                        }
                    }
                }
            }
       }
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                        //printf("%d %d\n",i,j);
                    if(A[i][j]==('A' + ase - 1)){
                       if(visited[i][j]!=1){
                            fl=0;
                            break;
                       }
                    }
                }
            }
        if(fl==0)cout<<"Case "<<ct<<": "<<"Impossible"<<endl;
        else{
            cout<<"Case "<<ct<<": "<<res<<endl;
        }
    }
}
