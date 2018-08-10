#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<stack>
using namespace std;

int cases,ct=0,i,j,x,m,n,k,A[200];
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        scanf("%d %d",&n,&k);
        m=0;
        x=0;
        ct++;
        n=65+n-1;
        for(i=65;i<=n;i++){
            A[m]=i;
            m++;
        }
        sort(A,A+m);
        //for(i=0;i<m;i++)printf("%c\n",A[i]);
         printf("Case %d:\n",ct);
        do{
            if(x==k)break;
            else{
                for(i=0;i<m;i++){
                    printf("%c",A[i]);
                }
                printf("\n");
            }
             x++;
        }while(next_permutation(A,A+m));
    }
}
