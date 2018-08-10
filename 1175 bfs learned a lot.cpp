#include<bits/stdc++.h>
#define pare pair<int,int>

using namespace std;

int k,res,T[205][205],pre[205][205],visited[205][205],n,m,fl,cases,ct=0,flag;
int dx[6] = {0,0,1,-1};
int dy[6] = {1,-1,0,0};
char A[205][205];
queue<pare>Q;
int isvalid(int x, int y){
   if(fl==1){
        if(x<n && x>=0 && y<m && y>=0 && visited[x][y]==-1 && (A[x][y]=='.'||A[x][y]=='J' || A[x][y]=='F')){
            //printf("SOTTO %d %d\n",x,y);
            return 1;
        }
        else{
            //printf("MITHHA %d %d\n",x,y);
            return 0;
        }
   }
   else{
        if(x<n && x>=0 && y<m && y>=0 && visited[x][y]==-1 && A[x][y]=='.'){
            return 1;
        }
        else{
            return 0;
        }
   }
}
int pathisvalid(int x,int y){
    //printf("checking %d %d \n",x,y);
    int i,j;
        if( T[x][y]!=-1 && visited[x][y]!=-1 && T[x][y]<=visited[x][y]){
                //printf("coordinate %d %d : fired %d jane = %d \n",x,y,T[x][y],visited[x][y]);
                return 0;
        }
        else{
            return 1;
        }
}
void bfsjane(int row, int col){
    int i,j,x,y;
    visited[row][col]= 0;
    Q.push(pare(row,col));
    while(!Q.empty()){
         pare top = Q.front();
         Q.pop();
         for(i=0;i<4;i++){
            x = top.first + dx[i];
            y = top.second + dy[i];
            if(isvalid(x,y)){
                    //printf("%d %d valid\n",x,y);
                visited[x][y] = visited[top.first][top.second] + 1;
               if(pathisvalid(x,y)){
                    if((x==0 || x==n-1)||(y==0 || y==m-1)){
                    res = min(res,visited[x][y]);
                    //printf("rakshi %d\n",res);
                    flag=1;
                    }
                    Q.push(pare(x,y));
               }
            }
         }
    }
}
void bfsFire(int row,int col){
    int i,j,x,y;
    visited[row][col]=0;
    //path[row][col]=0;
    T[row][col]=0;
    //printf("ekhon sada ase %d %d tey = %c\n",row,col,A[row][col]);
    Q.push(pare(row,col));
    while(!Q.empty()){
        pare top = Q.front();
        Q.pop();
        for(i=0;i<4;i++){
            x = top.first + dx[i];
            y = top.second + dy[i];
            //printf("for %d %d checking %d %d\n",top.first,top.second,x,y);
            if(isvalid(x,y)){
                    //printf("jawa jabe na %d %d\n",x,y);
                    //printf("jane er pathe time = %d, coordinate %d %d\n",path[x][y],x,y);
                    visited[x][y]=1;
                    T[x][y] = T[top.first][top.second] + 1;
                    //printf("%d %d = %d\n",x,y,T[x][y]);
                    if(T[x][y]<pre[x][y] || pre[x][y]==-1){
                        pre[x][y]=T[x][y];
                       // printf("dddfire no %d  time== %d coordinate %d %d\n",k,T[x][y],x,y);
                        Q.push(pare(x,y));
                    }
                    else{
                        T[x][y] = pre[x][y];
                         //printf("fire no %d  time== %d coordinate %d %d\n",k,T[x][y],x,y);
                    }

            }
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    int i,j;
    while(cases--){
        flag=0;
        Q = queue<pare>();
        scanf("%d %d",&n,&m);
        getchar();
        ct++;
        res=9000000000;
        memset(T,-1,sizeof T);
        memset(pre,-1,sizeof pre);
        memset(visited,-1,sizeof visited);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%c",&A[i][j]);
            }
            getchar();
        }
        k=1;
        fl=1;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
               if(A[i][j]=='F'){
                    memset(visited,-1,sizeof visited);
                   // printf("%d %d\n",i,j);
                    bfsFire(i,j);
               }
            }
        }
        int u,v=0;
        fl=0;
        memset(visited,-1,sizeof visited);
        //memset(path,0,sizeof path);
        //printf("ashlo\n");
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
               if(A[i][j]=='J'){
                    //printf("%d %d\n",i,j);
                    if((i==0 || i==n-1)||(j==0 || j==m-1))v=1;
                    else{
                        bfsjane(i,j);
                    }
                     break;
               }
            }
            if(v==1)break;
        }
        if(flag==1 && v==0)printf("Case %d: %d\n",ct,res+1);
        else if(v==1)printf("Case %d: 1\n",ct);
        else{
            printf("Case %d: IMPOSSIBLE\n",ct);
        }
    }
}
