# include<stdio.h>
#include<math.h>

int main(){
    int a,i;
    double r,pi,d,res;
    pi=2*acos(0.0);
    i=1;

    scanf("%d",&a);
    while(a--){
        scanf("%lf",&r);
        d=2*r;
        res=((2*r)*(2*r))-(pi*(r*r));
        printf("Case %d: %.2lf\n",i,res);
        i++;
    }
}
