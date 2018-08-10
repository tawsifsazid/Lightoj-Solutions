#include<stdio.h>

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long cases,w,a,b,i,j;
    scanf("%d",&cases);
        for(i=1;i<=cases;i++){
            scanf("%lld",&w);
            if(w%2!=0){
                printf("Case %lld: Impossible\n",i);
            }
            else{
                a=1;
                while(w%2==0){
                    a=a*2;
                    w=w/2;
                    if(w%2!=0){
                        printf("Case %lld: %lld %lld\n",i,w,a);
                    }
                }
            }
        }

}
