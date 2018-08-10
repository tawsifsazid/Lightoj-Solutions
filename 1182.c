#include<stdio.h>

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a,b,c,i,j,odd,even,ct,cases;
    ct=0;
    scanf("%d",&cases);
    while(cases--){
            ct++;
        scanf("%d",&b);
                i=0;
            while(b){
                if(b%2!=0){
                    i++;
                }
                b=b/2;
            }
            if(i%2==0){
                printf("Case %d: even\n",ct);
            }
            else{
                printf("Case %d: odd\n",ct);
            }
    }

}
