#include<bits/stdc++.h>

///Note:::more optimization required:: !
///Sieve of eratosthenes
///LINK-> http://lightoj.com/article_show.php?article=1001
///


using namespace std;
int n,k=1,flag[1000007],A[1000007],ct=0,cases;
void sieve(){
    int i;
    A[k]=2;
    for(i=3;i<=150;i=i+2){
        flag[i]=0;
    }
    for(i=3;i<=150;i=i+2){
        if(flag[i]==0){
            k++;
            A[k]=i;
            //printf("%d\n",A[k]);
        }
        if(flag[i]==0){
            //long long sqrtn=sqrt(n);
            for(int j=i*i;j<=150;j=j+i){
                flag[j]=-1;
            }
        }
    }
}
int main(){
    sieve();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i,j,res[102];
    scanf("%d",&cases);
    while(cases--){
        ct++;
        int koyta=0;
        scanf("%d",&n);
        //int sqrtn = sqrt(n);
        printf("Case %d: %d = ",ct,n);
        for(i=1;A[i]<=n;i++){
            koyta++;
            int temp=n,result=0;
             while(temp){
                temp = temp / A[i];
                result = result + temp;
             }
             res[A[i]] = result ;
               //printf("%d %d\n",A[i],res[A[i]]);
        }
       for(i=1;A[i]<=n;i++){
            if(koyta==1){
                printf("%d (%d)",A[i],res[A[i]]);
                break;
            }
            else if(koyta>1 && i==1){
                printf("%d (%d)",A[i],res[A[i]]);
            }
            else{
                printf(" * %d (%d)",A[i],res[A[i]]);
            }
       }
       printf("\n");
    }
}
//Case 3: 6 = 2 (4) * 3 (2) * 5 (1)
