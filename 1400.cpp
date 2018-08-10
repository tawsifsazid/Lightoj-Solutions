#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define llu unsigned long long int
#define pare pair<int,int>
#define mod 1000000007
using namespace std;

int ct=0,cases,n;
int man_prefer[505][505],woman_prefer[505][505],woman_wants[505][505],matched_man[505];
int matched_woman[505];


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

void stable(){
    queue<int>Q;
    int i,j,k;
    for(i=1;i<=n;i++){
        Q.push(i);
    }
    memset(matched_man,-1,sizeof matched_man);
    memset(matched_woman,-1,sizeof matched_woman);
    for(i=n+1;i<=2*n;i++){
        for(j=1;j<=n;j++){
            int want = woman_prefer[i][j];
            woman_wants[i][want] = j;
        }
    }
    while(!Q.empty()){
        int man = Q.front();
        //cout<<"MAN just popped = "<<man<<endl;
        Q.pop();
        for(i=1;i<=n && matched_man[man] == -1; i++){
            int woman = man_prefer[man][i];
            //cout<<"current man = "<<man<<endl;
            //cout<<"current preference = "<<woman<<endl;
            if(matched_woman[woman] == -1){
                //cout<<"Woman was available"<<endl;
                matched_man[man] = woman;
                matched_woman[woman] = man;
            }
            else{
                int now = matched_woman[woman];
				//cout<<"Women already engaged to "<<now<<endl;
				//cout<<"Rank of our man = "<< woman_wants[woman][man]<<" other man = "<<woman_wants[woman][now]<<endl;

                if(woman_wants[woman][now] > woman_wants[woman][man]){
                    matched_man[man] = woman;
                    matched_woman[woman] = man;
                    Q.push(now);
                    matched_man[now] = -1;
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
        memset(man_prefer,0,sizeof man_prefer);
         memset(woman_prefer,0,sizeof woman_prefer);
          memset(woman_wants,0,sizeof woman_wants);
           //memset(,0,sizeof man_prefer);
        int a,i,j,k;
        for(i=1;i<=n;i++){
            //scanf("%d",&a);
            for(j=1;j<=n;j++){
                scanf("%d",&man_prefer[i][j]);
            }
        }
        for(i=n+1;i<=n*2;i++){
            //scanf("%d",&a);
            for(j=1;j<=n;j++){
                scanf("%d",&woman_prefer[i][j]);
            }
        }
        //for(i=1;i<=n;i++){
            //scanf("%d",&a);
         //   for(j=1;j<=n;j++){
                //scanf("%d",&man_prefer[i][j]);
          //      cout<<" woman  "<<i<<" prefers "<<woman_prefer[i][j]<<endl;
          //  }
        //}
        stable();
        printf("Case %d:",ct);
        for(i=1;i<=n;i++){
               printf(" (%d %d)",i,matched_man[i]);
        }
        printf("\n");
    }

}
