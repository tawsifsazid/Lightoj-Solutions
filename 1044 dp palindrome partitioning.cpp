#include<bits/stdc++.h>
#define N 1005
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
int palin[1005][1005], cut[1005],len;
char a[1005];
int trydp(){
    int i,j,k,substring,starting;
    for(i=0;i<len;i++){
        palin[i][i] = 1;
    }
    for(i=0;i<len-1;i++){
        if(a[i] == a[i+1]){
            palin[i][i+1] = 1;
        }
    }
    for(substring=3;substring<=len;substring++){
        for(starting=0; starting<len - substring + 1 ;starting++){
            j = starting + substring - 1;
            if(palin[starting+1][j-1]==1 && a[starting]==a[j]){
                palin[starting][j] = 1;
            }
        }
    }
    for(i=0;i<len;i++){
        if(palin[0][i] == 1){
            cut[i] = 0;
        }
        else{
            cut[i] = 99999999;
            for(j=0;j<i;j++){
                if(palin[j+1][i]==1 && cut[i] > cut[j]+1){
                    cut[i] = cut[j] + 1;
                }
            }
        }
    }
    return cut[len - 1];
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        memset(palin,0,sizeof palin);
        int i,j,k;
        for(i=0;i<len;i++){
            //cut[i] = 99999999;
        }
        scanf("%s",a);
        len =strlen(a);
       int res = trydp();
       printf("Case %d: %d\n",ct,res+1);
    }
}
