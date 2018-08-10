#include<bits/stdc++.h>
#define N 1005
#define  ll long long
using namespace std;

int ct=0,cases,res;
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
char A[1000010],P[1000010];
int lps[1000010];
void computelpsarray(){
    int i,j,len;
    len = 0;
    i = 1;
   int  m = strlen(P);
    lps[0] = 0;
    while(i < m){
        if(P[len] == P[i]){
            len ++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}
void kmpsearch(){
    int i,j,len;
    int n = strlen(A);
    int m = strlen(P);
    i = 0;
    j = 0;
    while(i < n ){
        if(P[j] == A[i]){
            i++;
            j++;
        }
        if(j == m){
            //printf("%d\n",i-j);
            j = lps[j-1];
            res++;
            //printf("j = %d\n",j);
        }
        else if(i < n && P[j]!=A[i]){
            if(j!=0){
                j = lps[j-1];
                //res++;
            }
            else{
                i++;
            }
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        int i,j,k;
        memset(lps,0,sizeof lps);
        ct++;
        res = 0;
        scanf("%s %s",A,P);
        computelpsarray();
        kmpsearch();
        printf("Case %d: %d\n",ct,res);
    }
}
