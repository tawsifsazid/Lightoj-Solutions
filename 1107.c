#include<stdio.h>

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int x1,x2,y1,y2,i,j,cases,cow,a,b;
    scanf("%d",&cases);
        for(i=1;i<=cases;i++){
                printf("Case %d:\n",i);
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            scanf("%d",&cow);
            for(j=1;j<=cow;j++){
                scanf("%d %d",&a,&b);
                if(x1<a && a<x2 && y1<b && b<y2){
                    printf("Yes\n");
                }
                else{
                    printf("No\n");
                }
            }
        }
}
