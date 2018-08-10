#include<bits/stdc++.h>
#define N 100005
#define  ll long long
#define pare pair<int,int>
using namespace std;

int ct=0,cases;
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
int bit[N];
int maxlen;
void update(int x,int value){
    while(x<=maxlen){
           //cout<<"previously "<<bit[x]<<endl;
           bit[x] =bit[x] + value;
           //printf("updating x=%d and %d\n",x,bit[x]);
            //cout<<"now "<<bit[x]<<endl;
            x += x & (-x);
           // cout<<x<<endl;
    }
}
int query(int x){
    int res = 0;
    while(x>0){
        res  = res + bit[x];
        x = x - (x & (-x));
    }
    //printf("res %d\n",res);
    return res;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        memset(bit,0,sizeof bit);
        char A[100005];
        scanf("%s",A);
        int len = strlen(A);
        maxlen = len;
        //printf("max len= %d\n",maxlen);
        int j=1;
        for(int i = 0 ;i <len ; i++){
            bit[j] = 0;
            j++;
        }
        //cout<<endl;
        int ask;
        scanf("%d",&ask);
        printf("Case %d:\n",ct);
        while(ask--){
            char a;
           getchar();
           scanf("%c",&a);
            int c,d;
            if(a=='I'){
                scanf("%d %d",&c,&d);
                //printf("c==%d,&d==%d\n",c,d);
                update(c,1);
                //printf("hehe\n");
                update(d+1,-1);
            }
            else{
                int z;
                scanf("%d",&z);
                int u = query(z);
                //printf("u  = %d\n",u);
                if(u%2 == 1){
                    if(A[z-1] == '1'){
                        printf("0\n");
                    }
                    else printf("1\n");
                }
                else{
                    printf("%c\n",A[z-1]);
                }
                //printf("dhukse\n");
            }
        }
    }
}
