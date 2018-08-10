#include<stdio.h>
#include<math.h>
#include<STRING.H>
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,b,j,a,sum,cases;
        scanf("%d",&a);
        cases=0;
        while(a--){
            cases++;
            scanf("%d",&i);
            b=i;
            sum=0;
            while(i){
            j=i%10;
            sum=sum*10+j;
            i=i/10;
            }
            if(b==sum){
                printf("Case %d: Yes\n",cases);
            }
            else{
                printf("Case %d: No\n",cases);
            }
        }
    }

