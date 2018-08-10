#include<stdio.h>
#include<string.h>
#include<math.h>
double res;

double array[1000009];
double fact(){
    int i;
    array[1]=log10(1);
    for(i=2;i<=1000000;i++){
        array[i]= array[i-1] + log10(i);
    }
}
int main(){

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    long long base,n,i,j,k,cases,ct=1,realres;
    fact();
    scanf("%lld",&cases);
    while(cases--){
             //printf("dhuk");
             res=0;
             scanf("%lld %lld",&n,&base);
                //printf("%lf\n",res);

            res=array[n]/log10(base);
            //printf("%lf\n",res);
            res= res + 1;
            realres=res;
             printf("Case %lld: %lld\n",ct++,realres);
    }
}
