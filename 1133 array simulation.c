#include<stdio.h>

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,cases,ct,operation,element,add,multi,k,a,b,z,c,v,d,res;
    int array[1005];
	char ask[5];
    ct=0;
    char ch;
    scanf("%d",&cases);
    while(cases--){
        ct++;
        i=0;
        scanf("%d",&element);
        scanf("%d",&operation);
        while(element--){
            scanf("%d",&j);
            array[i]=j;
            i++;
        }
            z=i-1;

        while(operation--){
            i=z;
            j=0;
            //getchar();
            scanf("%s",&ask);
            if(ask[0]=='S'){
                scanf("%d",&add);
                while(j<=i){
                    array[j]=array[j]+add;
                    j++;
                }
            }
            else if(ask[0]=='M'){
                 scanf("%d",&multi);
                while(j<=i){
                    array[j] = array[j]*multi;
                    j++;
                }
            }
            else if(ask[0]=='R'){
                    while(j<=i){
                        c=array[i];
                        array[i] = array[j];
                        array[j] = c;
                        i--;
                        j++;
                    }

            }
            else if(ask[0]=='P'){
                scanf("%d %d",&a,&b);
                    c=array[a];
                    array[a] = array[b];
                    array[b] = c;
            }
            else if(ask[0]=='D'){
                     scanf("%d",&k);
                while(j<=i){
                    array[j] = array[j]/k;
                    j++;
                }
            }
        }
                j=1;
                i=z;
                printf("Case %d:\n",ct);
                printf("%d",array[0]);
               while(j<=i){
                printf(" %d",array[j]);
                j++;
               }
               printf("\n");

    }
}
