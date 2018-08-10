#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007
using namespace std;

int ct=0,cases,n,m,ase=0,check = 0,ans = 0;
///dir array for Queen int dxq[10] = {-1,-1,-1,1,1,1,0,0};
///dir array for Queen int dyq[10] = {-1,0,1,-1,0,1,-1,1};
int dxk[10] = {-2,-2,-1,-1,1,1,2,2};
int dyk[10] = {1,-1,-2,2,-2,2,-1,1};
/*int leap(int year){
   	if( year%4 == 0 && year%100 == !0 )
            return 1;
	else if (year%100 == 0 && year%400 == 0)
            return 1;
	else
        return 0;
}*/
char A[15][15];
int vis[15][15],T[105][15][15],ashlo[15][15],rider[105];
void bfs(int id,int x,int y){
    int i,j,k,res = 0;
    memset(vis,0,sizeof vis);
    //cout<<"rider = "<<k<<endl;
    T[id][x][y] = 0;
    vis[x][y] = 1;
    ashlo[x][y]++;


   // else{
        queue<pare>Q;
        Q.push(pare(x,y));
        while(!Q.empty()){
            pare u = Q.front();
            if(ashlo[u.first][u.second] == ase){
                   // cout<<"found  "<<u.first<<" "<<u.second<<endl;
                       res = 0;
                    for(i=1;i<=ase;i++){
                        //T[i][u.first][u.second] =  (double)T[i][u.first][u.second]/k;
                       res = res + ceil((double)T[i][u.first][u.second]/rider[i]);

                       //cout<<"yaa "<<T[i][x][y]<<endl;
                    }
                    //cout<<"res "<<res<<endl;
                    ans = min(ans,res);
            }
            Q.pop();
            for(i=0;i<8;i++){
                    int xx = (dxk[i]) + u.first;
                    int yy = (dyk[i]) + u.second;
                    if(xx>=0 && xx<n && yy>=0 && yy <m && vis[xx][yy] == 0){
                        vis[xx][yy] = 1;
                        T[id][xx][yy] = T[id][u.first][u.second] + 1;
                        //cout<<T[id][xx][yy]<<endl;

                        //cout<<"chaal "<<T[id][xx][yy]<<endl;
                        ashlo[xx][yy]++;
                        Q.push(pare(xx,yy));
                    }

            }
        }
   // }

}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //scanf("%d",&cases);
    cin>>cases;
    while(cases--){
        ct++;
        ase = 0;
        cin>>n>>m;
        check = 0;
        ans = 100000000;
        int i,j,k=1;
         memset(rider,0,sizeof rider);
       // memset(A,0,sizeof A);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>A[i][j];
                if(A[i][j] != '.'){
                    rider[k] = A[i][j] - 48;
                    //cout<<rider[k]<<endl;
                    k++;
                    ase++;
                }
            }
        }
        memset(ashlo,0,sizeof ashlo);
        memset(T,0,sizeof T);

        //memset(T,0,sizeof T);
        k = 1;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(A[i][j] != '.'){
                    bfs(k,i,j);
                    k++;
                }
            }
        }
        if(ans != 100000000)printf("Case %d: %d\n",ct,ans);
        else printf("Case %d: -1\n",ct);
    }

}
