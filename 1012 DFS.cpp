#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<set>

using namespace std;

int i,j,k,res,ct=0,cases,n,m,A[700][700],t,visited[700][700],h,stx,sty,w;
void dfs(int x,int y){
    //printf("ekhon x==%d and y==%d\n",x,y);
   int  dx[4]={0,0,1,-1};
    int dy[4]={-1,1,0,0};
        if(visited[x][y]==0 && x<=h && x>=1 && y<=w && y>=1 && A[x][y]!='#'){
            //printf("dhukse %d %d\n",x,y);
            visited[x][y]=1;
            res++;
            for(int i=0;i<4;i++){
                dfs(x+dx[i],y+dy[i]);
            }
        }
        else{
            return;
        }

}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        res=0;
        scanf("%d %d\n",&w,&h);
        for(i=1;i<=h;i++){
            for(j=1;j<=w;j++){
                scanf("%c",&A[i][j]);
                //getchar();
                if(A[i][j]=='@'){
                    stx=i;
                    sty=j;
                    //printf("%d %d\n",stx,sty);
                }
            }
            getchar();
        }
        for(i=1;i<=h;i++){
            for(j=1;j<=w;j++){
                visited[i][j]=0;
            }
        }
        dfs(stx,sty);
        printf("Case %d: %d\n",ct,res);
    }
}
