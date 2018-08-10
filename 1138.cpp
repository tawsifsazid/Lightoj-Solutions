#include<bits/stdc++.h>

using namespace std;
int cases,ct=0,p,res;
int zero(int n){
    int ase=0;
    while(n){
        ase = ase + (n/5);
        n = n/5;
    }
    return ase;
}
int binarysearch(int low,int high){
    int mid,num;
    if(low > high){

        return -1;
    }
    mid = (low + high)/2;
    num = zero(mid);
    if(num == p){
           // printf("dhukse")
        while(zero(mid) == num){
            mid--;
        }
        mid++;
        return mid;
    }
    if(num < p){
        return binarysearch(mid+1,high);
    }
    else{
        return binarysearch(low,mid-1);
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        scanf("%d",&p);
        res=binarysearch(1,5000000000);
        if(res==-1)printf("Case %d: impossible\n",ct);
        else{
            printf("Case %d: %d\n",ct,res);
        }
    }
}
