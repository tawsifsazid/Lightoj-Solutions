#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define pare pair<int,int>
using namespace std;

int ct=0,cases,n;
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
vector<int>graph[505];
int L[505],R[505],vis[505];

struct node{
    int x1,y1,x2,y2,time;
}city[505];
bool tryk(int s){
      if ( vis[s] == 1 ) return false;
        vis[s] = 1;
    //printf("ekhon %d\n",s);
    //cout<<graph[s].size()<<endl;
    for ( int i = 0; i < graph[s].size(); i++ ) {
        int t = graph[s][i];

        if ( R[t] == -1 || tryk(R[t]) ) {
            L[s] = t;
            R[t] = s;
            //printf("dhukk\n");
            return true;
        }
    }

    return false;
}
int kuhn(){
        int res = 0;
    memset(L,-1,sizeof L);
    memset(R,-1,sizeof R);
    for ( int i = 1; i <= n; i++ ) {
        memset(vis,0,sizeof vis);
        if ( tryk ( i ) ) {
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
        scanf("%d",&n);
        int i,j,k,h,m;
        for(i=1;i<=n;i++){
            scanf("%d:%d %d %d %d %d",&h,&m,&city[i].x1,&city[i].y1,&city[i].x2,&city[i].y2);
            //printf("%d %d %d %d %d %d\n",h,m,city[i].x1,city[i].y1,city[i].x2,city[i].y2);

            city[i].time =( h*60 ) + m;
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(i == j) continue;
                //printf("%d\n",city[j].time);
                if(city[j].time > (city[i].time + abs(city[i].x1-city[i].x2)+abs(city[i].y1-city[i].y2)+abs(city[i].x2-city[j].x1)+abs(city[i].y2-city[j].y1))){
                    //printf("dhkkse\n");
                    graph[i].push_back(j);
                }
            }
        }
        int ans = kuhn();
        //printf("ans = %d\n",ans);
        printf("Case %d: %d\n",ct,n-ans);
        for(i=0;i<=n;i++){
            graph[i].clear();
        }
    }
}
