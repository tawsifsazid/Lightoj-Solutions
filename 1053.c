#include<stdio.h>
int main(){
    int a,b,c,cases,i;
    scanf("%d",&cases);

        for(i=1;i<=cases;i++){
            scanf("%d %d %d",&a,&b,&c);
            if(a>b&&a>c){
                if((a*a)==(b*b)+(c*c)){
                printf("Case %d: yes\n",i);
                }
                else{
                printf("Case %d: no\n",i);
                }
            }
             else if(b>a&&b>c){
                if((b*b)==(a*a)+(c*c)){
                printf("Case %d: yes\n",i);
                }
                else{
                printf("Case %d: no\n",i);
                }
            }
             else if(c>a&&c>b){
                if((c*c)==(a*a)+(b*b)){
                printf("Case %d: yes\n",i);
                }
                else{
                printf("Case %d: no\n",i);
                }
            }

        }


}
