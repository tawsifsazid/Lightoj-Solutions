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

using namespace std;

int f1[30],f[30],k,res,ct,cases,n,dec[40],a,b,c,d,st1[40],k1,k2,k3,st2[40],st3[40],st4[40];
int bin(int x){
   int i,j;
    for(i=1;i<=25;i++){
        f1[i]=0;
        f[i]=0;
    }
    int y=0,rem,v=0;
    while(x!=0 || v==0){
          v=1;
         rem=x%2;
         //printf("rem==%d\n",rem);
        y++;
        f1[y]=rem;
        //printf("y=%d f[y]=%d\n",y,f1[y]);
        x=x/2;
    }
    if(y!=8){
        for(i=1;i<=8-y;i++){
            f[i]=0;
        }
        j=i;
    }
    else{
        j=1;
    }
    for(i=y;i>=1;i--){
        f[j]=f1[i];
        //printf("%d\n",f[j]);
        j++;
    }

    return 8;
}
void init(){
    for(int i=0;i<=25;i++){
        st2[i]=0;
        st1[i]=0;
        st3[i]=0;
        st4[i]=0;
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        int i,j;
        init();
        char A[40],B[40];
         ct++;
        k=0;
        k1=0;
        k2=0;
        k3=0;
        char tmp[40];
        scanf("%s",A);
        for(i=0;i<strlen(A);i++){
           if(isdigit(A[i])){
             tmp[k]=A[i];
             k++;
           }
           else{
             tmp[k]=NULL;
                a=atoi(tmp);
                //printf("%d\n",a);
                k=0;
             break;
           }
        }
        for(i=i+1;i<strlen(A);i++){
           if(isdigit(A[i])){
             tmp[k]=A[i];
             k++;
           }
           else{
             tmp[k]=NULL;
                b=atoi(tmp);
                //printf("%d\n",b);
                k=0;
             break;
           }
        }
        for(i=i+1;i<strlen(A);i++){
           if(isdigit(A[i])){
             tmp[k]=A[i];
             k++;
           }
           else{
             tmp[k]=NULL;
             //printf("%d\n",c);
                c=atoi(tmp);
                k=0;
             break;
           }
        }
        for(i=i+1;i<strlen(A);i++){
           if(isdigit(A[i])){
             tmp[k]=A[i];
             k++;
           }
        }
        tmp[k]=NULL;
            d=atoi(tmp);
            //printf("%d\n",d);
            k=0;
        scanf("%s",B);
        k=0;
        k1=0;
        k2=0;
        k3=0;
        for(i=0;i<strlen(B);i++){
            if(i<=7 && B[i]!='.'){
                k++;
                st1[k]=B[i]-48;
                //printf("1== %d\n",st1[k]);
            }
            else if(i<=16 && B[i]!='.'){
                k1++;
                st2[k1]=B[i]-48;
                //printf("2== %d i==%d\n",st2[k1],i);
            }
            else if(i<=25 && B[i]!='.'){
                k2++;
                st3[k2]=B[i]-48;
                //printf("3== %d i==%d\n",st3[k2],i);
            }
            else if(i<=34 && B[i]!='.'){
                k3++;
                st4[k3]=B[i]-48;
                //printf("4== %d i==%d\n",st4[k3],i);
            }
        }
        int len,flag=0;
        len=bin(a);
        for(i=1;i<=8;i++){
            if(st1[i]!=f[i]){
                flag=1;
            }
        }
        if(flag==0){
            len=bin(b);
            for(i=1;i<=8;i++){
                if(st2[i]!=f[i]){
                    flag=1;
                }
            }
        }
        if(flag==0){
            len=bin(c);
            for(i=1;i<=8;i++){
                if(st3[i]!=f[i]){
                    flag=1;
                }
            }
        }
         if(flag==0){
            len=bin(d);
            for(i=1;i<=8;i++){
                if(st4[i]!=f[i]){
                    flag=1;
                }
            }
        }

                if(flag==1)printf("Case %d: No\n",ct);
                else{
                    printf("Case %d: Yes\n",ct);
                }
    }
}
