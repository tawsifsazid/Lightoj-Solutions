#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int cases,n,a,i,ct=1;
    double r,R;
    scanf("%d",&cases);
    //printf("%.10lf\n",pi);
    while(cases--){
        scanf("%lf %d",&R,&n);
        double theta = 360.0/(2.0*n);
        theta = (pi*theta)/180.0;
        r=(sin(theta)*R)/(sin(theta)+1);
        printf("Case %d: %.10lf\n",ct++,r);

    }


    return 0;
}
