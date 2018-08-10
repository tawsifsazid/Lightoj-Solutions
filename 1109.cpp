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

int i,j,k,res,ct,cases,n;
struct d{
    int val,id,k;
}A[5000];
bool compare(d a,d b){
    //printf("%d %d\n",a,b);
    if(a.val==b.val){
         //printf("%d %d and m[a]==%d and m[b]=%d\n",a,b,m[a],m[b]);
        return (a.id>b.id);
    }
    else{
        return a.val<b.val;
    }

}
void f(){
    for(i=1;i<=1000;i++){
        res=0;
        for(j=1;j<=i;j++){
            if(i%j==0){
                res++;
            }
        }
        A[i].val=res;
        A[i].id=i;
        //printf("%d %d\n",i,A[i]);
    }
    sort(A+1,A+1001,compare);
    for(i=1;i<=10;i++){
    //    printf("%d\n",A[i]);
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    f();
    while(cases--){
        ct++;
        scanf("%d",&n);
        printf("Case %d: %d\n",ct,A[n].id);
    }
}
