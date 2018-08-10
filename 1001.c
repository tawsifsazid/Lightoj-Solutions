#include<stdio.h>
int main(){
    int a,b,c,i;
    scanf("%d",&i);
    while(i--){
        scanf("%d",&a);
        if(a<=10){
            printf("%d %d\n",a,b=0);
        }
        if(a>10){
            printf("%d %d\n",a-10,10);
        }
    }
}
