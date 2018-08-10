#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<set>

unsigned long long int a, b, c, d, e, f,A[30000],res;
unsigned long int fn(unsigned long long int n ) {
    A[0]=a;
    A[1]=b;
    A[2]=c;
    A[3]=d;
    A[4]=e;
    A[5]=f;
        for(long long i=6;i<=n;i++){
              A[i]=(A[i-1]+A[i-2]+A[i-3]+A[i-4]+A[i-5]+A[i-6])%10000007;
              //printf("%llu\n",A[i]);
        }
    return A[n];
    //return (A[n-1]+A[n-2]+A[n-3]+A[n-4]+A[n-5]);
    //return A[n-1] + A[n-2] + A[n-3] + A[n-4] + A[n-5] + A[n-6] ;
}
int main() {
     //freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
    unsigned long long int n, caseno = 0, cases;
    scanf("%llu", &cases);
    while( cases-- ) {
         for(long long i=0;i<=20000;i++)A[i]=0;
        scanf("%llu %llu %llu %llu %llu %llu %llu", &a, &b, &c, &d, &e, &f, &n);
        res=fn(n);
        printf("Case %llu: %llu\n", ++caseno, res % 10000007);
    }
    return 0;
}
