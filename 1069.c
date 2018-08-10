# include<stdio.h>
int main(){
    int i,a,b,res,d,lift,cases,j;
    d=19;
    scanf("%d",&cases);
            for(i=1;i<=cases;i++){
                scanf("%d %d",&a,&b);
               if(a<=b){
                for(j=1;j<=b;j++){
                    lift=j*4;
                }
                res=lift+d;
                printf("Case %d: %d\n",i,res);
                }
                else{
                    res=((a-b)*4)+(a*4)+d;
                    printf("Case %d: %d\n",i,res);
                }
            }




}

