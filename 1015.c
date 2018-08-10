# include<stdio.h>
int main(){
    int a,b,c,d,j,sum;
    j=1;
    sum=0;
    scanf("%d",&a);
    while(a--){
        sum=0;
        scanf("%d",&b);
        while(b--){
            scanf("%d",&c);
            if(c<0){
                c=0;
            }
            else{
            sum=sum+c;
            }
        }
        printf("Case %d: %d\n",j,sum);
        j++;
    }
}
