#include<bits/stdc++.h>
#define N 800005
#define  ll long long
#define pare pair<int,int>
using namespace std;

int ct=0,cases,res,bit[N];
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
map<int ,int>M,R;
void update(int x,int value){
    while(x<800002){
        bit[x] = bit[x] + value;
        //printf("bit[x]=%d\n",bit[x]);
        x += x & (-x);
    }
    //for(int i=3;i<=7;i++){
    //    printf("x=%d and bit[x]=%d\n",i,bit[i]);
    //}
}
int query(int x){
    res = 0;
    while(x){
        res = res + bit[x];
        x -= x & (-x);
    }
    //printf("res=%d\n",res);
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    //cout<<cases<<endl;
    while(cases--){
        ct++;
        pare input;
        vector<pare>V;
        int i,j,k=0,n,q,a,b,Q[50005],A[200005];

        memset(bit,0,sizeof bit);
        memset(A,0,sizeof A);
        memset(Q,0,sizeof Q);
        M.clear();
        V.clear();
        R.clear();
        scanf("%d %d",&n,&q);

        for(i=1;i<=n;i++){
            scanf("%d %d",&a,&b);
            input.first = a;
            input.second = b;
            V.push_back(input);
            if(R[a] == 0){
                A[k] = a;
                k++;
                R[a] = 1;
            }
            if(R[b] == 0){
                A[k] = b;
                k++;
                R[b] = 1;
            }

        }
        int r;
        for(i=0;i<q;i++){

            scanf("%d",&Q[i]);
            if(R[Q[i]] == 0){
                R[Q[i]] = 1;
                A[k] = Q[i];
                k++;
            }
        }
        sort(A,A+k);
        j = 1;
        for(i=0;i<k;i++){
            if(M[A[i]] == 0){
                M[A[i]] = j;
            //cout<<A[i]<<" = "<<M[A[i]] <<endl;
                j++;
            }
        }
        printf("Case %d:\n",ct);
        for(i=0;i<V.size();i++){
            int x = V[i].first;
            int y = V[i].second;
            //cout<<x<<" "<<y<<endl;
            //cout<<"change "<<M[x]<<" "<<M[y]<<endl;
            update(M[x],1);
            //printf("bit = %d\n",bit[16]);
            update(M[y]+1,-1);
        }
        for(i=0;i<q;i++){
             res = 0;
            //cout<<Q[i]<<" = "<<M[Q[i]]<<" AND "<<M[Q[i]]-1<<endl;
            int ans = query(M[Q[i]]);
            printf("%d\n",ans);
        }
    }
}
