#include<bits/stdc++.h>
#define pare pair<int,int>
using namespace std;

int k=0,res,ct=0,cases,n,visited[600][600],thisone[600][600],res1[600][600],fl,q,m,a,b,vis;
int dx[10] = {0,0,1,-1};
int dy[10] = {1,-1,0,0};
char A[600][600];
queue<pare>Q;
int isvalid(int x, int y){
    if(x>=0 && x<n && y<m && y>=0 && visited[x][y]==0 && A[x][y]!='#'){
        return 1;
    }
    else{
        return 0;
    }
}
int bfs(int row,int col){
    int i,j,x,y;
    visited[row][col]=1;
    thisone[row][col]=1;
    //printf("%d %d = visited\n",row,col);
    Q.push(pare(row,col));
    while(!Q.empty()){
        pare top = Q.front();
        Q.pop();
        for(i=0;i<4;i++){
            x = top.first + dx[i];
            y = top.second + dy[i];
            if(isvalid(x,y)){
                visited[x][y]=1;
                if(A[x][y]=='C'){
                        res++;
                    //printf("crystal paisi %d ta\n",res);
                }
                else{
                    //printf("%d %d = visited\n",x,y);
                    thisone[x][y]=1;
                }
                Q.push(pare(x,y));
            }
        }
    }
    //memset(visited,0,sizeof visited);
    return res;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    int i,j;
    while(cases--){
        scanf("%d %d %d",&n,&m,&q);
        getchar();
        ct++;
        res=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%c",&A[i][j]);
            }
            getchar();
        }
        memset(visited,0,sizeof visited);
        memset(thisone,-1,sizeof thisone);
        memset(res1,0,sizeof res1);
        printf("Case %d:\n",ct);
        int p,r;
        for(r=1;r<=q;r++){
               scanf("%d %d",&a,&b);
               a--;
               b--;
                if(A[a][b]=='.' && visited[a][b]==0){
                    res=0;
                    memset(thisone,-1,sizeof thisone);
                    bfs(a,b);
                    for(i=0;i<n;i++){
                        for(j=0;j<m;j++){
                            if(thisone[i][j]==1){
                                res1[i][j]=res;
                            }
                        }
                    }
                }
                printf("%d\n",res1[a][b]);
        }

       /* for(i=1;i<=q;i++){
            scanf("%d %d",&a,&b);
            printf("%d\n",res1[a-1][b-1]);
        }*/
    }

}
