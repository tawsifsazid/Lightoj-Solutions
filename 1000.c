# include<stdio.h>
int main(){
    int t,a,b,ct=1;

        scanf("%d",&t);
        while(t--){
            scanf("%d %d",&a,&b);
            printf("Case %d: %d\n",ct++,a+b);
        }

}
