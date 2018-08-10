#include<bits/stdc++.h>
#define N 1005
#define  ll long long
#define pare pair<int,int>
using namespace std;

int ct=0,cases,n,mid;
int A[100007];
///dir array for Queen int dxq[10] = {-1,-1,-1,1,1,1,0,0};
///dir array for Queen int dyq[10] = {-1,0,1,-1,0,1,-1,1};
///dir array for knight int dxk[10] = {-2,-2,-1,-1,1,1,2,2};
///dir array for knight int dyk[10] = {1,-1,-2,2,-2,2,-1,1};
/*int leap(int a){
    if(a%4==0){
        if(a%100==0){
            if(a%400==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}*/
int check(int ans){
    int i,j,k=ans;
    if(A[0]>ans)return -1;
    else{
        if(A[0] == ans)ans--;
    }
    for(i=1;i<n;i++){
        if(ans < A[i]-A[i-1]){
            return - 1;
        }
        else if(ans >= A[i]-A[i-1]){
            if(ans == (A[i]-A[i-1])){
                ans--;
            }
            else{

            }
        }
    }
    return k;
}
int binarysearch(int low,int high){
        mid = (low + high)/2;
        if(low > high)return low;
        if(check(mid)<0){
            low = mid + 1;
            binarysearch(low,high);
        }
        else{
            high = mid - 1;
            binarysearch(low,high);
        }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        scanf("%d",&n);
        int i,j,k;
        for(i=0;i<n;i++){
            scanf("%d",&A[i]);
        }
       int ans = binarysearch(0,11000000);
        //printf("%d\n",ans);
        printf("Case %d: %d\n",ct,ans);
    }
}
