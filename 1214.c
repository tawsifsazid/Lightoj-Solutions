#include<stdio.h>
#include<string.h>
#include<math.h>
char str[600000],k;
int main(){
    //freopen("in.txt","r",stdin);
     //freopen("out.txt","w",stdout);
    int cases;
    long long a,flag,ct,b,i,j,rem,n,ans;;
     char c;
     ct=0;
    rem=0;
    scanf("%d",&cases);
    while(cases--){
           ct++;
        scanf("%s %lld",str,&a);
        if(a<0){
            a=fabs(a);
            //printf("%d\n",a);
        }
           b=strlen(str);
          if(str[0]=='-'){
             rem =(str[1]-48)%a;
           for(i=1;i<b;i++){
                rem=rem%a;
                ans=rem;
                //printf("%d\n",ans);
                //printf("%d\n",rem);
                rem=rem*10 + (str[i+1]-48);
           }
           if(ans==0){
            printf("Case %d: divisible\n",ct);
           }
           else{
            printf("Case %d: not divisible\n",ct);
           }
          }
          else{
           rem =(str[0]-48)%a;
           for(i=0;i<b;i++){
                rem=rem%a;
                ans=rem;
                //printf("%d\n",ans);
                //printf("%d\n",rem);
                rem=rem*10 + (str[i+1]-48);
           }
           if(ans==0){
            printf("Case %d: divisible\n",ct);
           }
           else{
            printf("Case %d: not divisible\n",ct);
           }
          }
    }
}
