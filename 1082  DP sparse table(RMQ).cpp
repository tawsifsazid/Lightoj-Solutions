#include<bits/stdc++.h>
#define N 1005
#define  ll long long
#define pare pair<int,int>
using namespace std;

int ct=0,cases,n,A[100005],height;
int sparse[25][100005];
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
void buildTable(){
    int i,j,k,two=2,pre=1;
    for(i=0;i<n;i++){
        sparse[0][i] = A[i];
        //printf("aaaaa\n");
    }
    //printf("building table\n");
    for(i=1;i<18;i++){
           // printf("dhukse\n");
         if(two>n){
            height = i;
           // printf("height = %d\n",height);
            break;
         }
        // printf("i = %d\n",i);
        for(j=0;j<n;j++){
            k = pre + j;
            if(k>=n)k = n-1;
            sparse[i][j] = min(sparse[i-1][j],sparse[i-1][k]);
           // printf("%d ",sparse[i][j]);
        }
        //printf("\n");
        pre = pre * 2;
        two = two*2;
        //printf("two %d\n",two);
    }
    //printf("height = %d\n",height);
}
int rmq(int i,int j){
    int len = j - i + 1;
    //printf("len = %d\n",len);
    int row = height;
    //printf("firstly row = %d\n",row);
    int two = pow(2,height);
    //printf("firstly two = %d\n",two);
    while(len < two){
        two = two/2;
        row--;
    }
    //printf("lastly row %d and j-two + 1 = %d and lastly two=%d\n",row,j-two+1,two);
    int res = min(sparse[row][i],sparse[row][j-two+ 1]);
    return res;

}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        int i,j,k,q;
        ct++;
        height = 0;
        scanf("%d %d",&n,&q);
        memset(A,0,sizeof A);
        memset(sparse,0,sizeof sparse);
        for(i=0;i<n;i++){
            scanf("%d",&A[i]);
        }
        buildTable();
        printf("Case %d:\n",ct);
        int a,b;
        for(k=0;k<q;k++){
            scanf("%d %d",&a,&b);
            int ans =  rmq(a-1,b-1);
            printf("%d\n",ans);
        }
    }
}
