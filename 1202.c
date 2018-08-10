#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long x1,y1,x2,y2,cases,ct,a,b,g;
    ct=0;
    scanf("%lld",&cases);
    while(cases--){
         g=0;
        ct++;
        scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
        //printf("%lld %lld %lld %lld\n",x1,y1,x2,y2);
        if(x1<x2){
            a=x1;
            x1=x2;
            x2=a;
        }
        if(y1<y2){
            b=y1;
            y1=y2;
            y2=b;
        }
        //printf("%lld %lld %lld %lld\n",x1,y1,x2,y2);
        if(x1%2!=0){
                //printf("dhuk\n");
           if(y1%2!=0){
            if(x2%2!=0 && y2%2!=0){
                if(x1-x2==y1-y2)printf("Case %lld: 1\n",ct);
                else{
                    printf("Case %lld: 2\n",ct);
                }
                g=1;
            }
            if(x2%2==0 && y2%2==0){
                    //printf("dhuk\n");
                if(x1-x2==y1-y2)printf("Case %lld: 1\n",ct);
                else{
                    printf("Case %lld: 2\n",ct);
                }
                g=1;
            }
            else if(g==0){
                printf("Case %lld: impossible\n",ct);
            }
           }
           if(y1%2==0){
            if(x2%2!=0 && y2%2==0){
                if(x1-x2==y1-y2)printf("Case %lld: 1\n",ct);
                else{
                    printf("Case %lld: 2\n",ct);
                }
                g=1;
            }
            if(x2%2==0 && y2%2!=0){
                if(x1-x2==y1-y2)printf("Case %lld: 1\n",ct);
                else{
                    printf("Case %lld: 2\n",ct);

                }
                g=1;
            }
            else if(g==0){
                printf("Case %lld: impossible\n",ct);
            }

        }
    }
    if(x1%2==0){
           if(y1%2!=0){
            if(x2%2==0 && y2%2!=0){
                if(x1-x2==y1-y2)printf("Case %lld: 1\n",ct);
                else{
                    printf("Case %lld: 2\n",ct);
                }
                g=1;
            }
            if(x2%2!=0 && y2%2==0){
                if(x1-x2==y1-y2)printf("Case %lld: 1\n",ct);
                else{
                    printf("Case %lld: 2\n",ct);
                }
                g=1;
            }
            else if(g==0){
                printf("Case %lld: impossible\n",ct);
            }
           }
           if(y1%2==0){
            if(x2%2==0 && y2%2==0){
                if(x1-x2==y1-y2)printf("Case %lld: 1\n",ct);
                else{
                    printf("Case %lld: 2\n",ct);
                }
                g=1;
            }
            if(x2%2!=0 && y2%2!=0){
                if(x1-x2==y1-y2)printf("Case %lld: 1\n",ct);
                else{
                    printf("Case %lld: 2\n",ct);
                }
                g=1;
            }
            else if(g==0){
                printf("Case %lld: impossible\n",ct);
            }

        }
    }
  }
}
