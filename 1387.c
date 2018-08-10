#include<stdio.h>
#include<string.h>
#include<math.h>
int i,j,k,a,b,c,d,cases,res,ct=0;
char ch[10];
int main(){

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
     scanf("%d",&cases);
     while(cases--){
          res=0;
          ct++;
        scanf("%d",&a);
        getchar();
         printf("Case %d:\n",ct);
        while(a--){
            scanf("%s",ch);
            if(ch[0]=='d'){
                scanf("%d",&b);
                res=res+b;
                //printf("%d\n",res);
            }
            if(ch[0]=='r'){
                //printf("Case %d:\n",ct);
                printf("%d\n",res);
            }
        }
     }
}
