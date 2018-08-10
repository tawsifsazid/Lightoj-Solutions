#include<bits/stdc++.h>
#define N 100005
#define  ll long long
#define pare pair<int,int>
using namespace std;

int ct=0,cases,maxindex=0,bit[N];
///dir array for Queen int dxq[10] = {-1,-1,-1,1,1,1,0,0};
///dir array for Queen int dyq[10] = {-1,0,1,-1,0,1,-1,1};
///dir array for knight int dxk[10] = {-2,-2,-1,-1,1,1,2,2};
///dir array for knight int dyk[10] = {1,-1,-2,2,-2,2,-1,1};
/*int leap(int a){
    if(a%4==0){
        if(a%100==0){
            if(a%400==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}*/
void update(int index,int value){
    while(index <= maxindex){
        bit[index] = bit[index] + value;
        //printf("index = %d and res = %d and value = %d\n",index,bit[index],value);
        index = index + (index & (-index));
    }
    //printf("hehe\n");
}
int query(int index){
    int res = 0;
    while(index>0){
         res =  res +  bit[index];
        index = index - (index & (-index));
    }

    return res;

}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        memset(bit,0,sizeof bit);
        int n,i,j,k,m,b;
        scanf("%d %d",&n,&m);
        maxindex = n;
        for(i=1;i<=n;i++){
            scanf("%d",&j);
            update(i,j);
        }
        printf("Case %d:\n",ct);
        while(m--){
            scanf("%d",&b);
            if(b == 1){
                scanf("%d",&j);

               int y =  query(j+1)-query(j);
                printf("%d\n",y);
                update(j+1,(-y));
            }
            else if(b == 2){
                 scanf("%d %d",&j,&k);
                update(j+1,k);
            }
            else{
                scanf("%d %d",&j,&k);
                if(j!=k)printf("%d\n",query(k+1)-query(j));
                else printf("%d\n",query(k+1)-query(k));
            }
        }
    }
}
