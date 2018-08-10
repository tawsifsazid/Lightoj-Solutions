#include<bits/stdc++.h>
#define N 200005
#define  ll long long
#define pare pair<int,int>

using namespace std;

///Note: trie data structure
///example abcde
///trie [0] . child ['a'] tey rakhbo porer node er adress 'b' = 1,tne trie [1].child['b']
///tey rakhbo 'c' = 2 er adress eivabe

int ct=0,cases,n;
///dir array for Queen int dxq[10] = {-1,-1,-1,1,1,1,0,0};
///dir array for Queen int dyq[10] = {-1,0,1,-1,0,1,-1,1};
///dir array for knight int dxk[10] = {-2,-2,-1,-1,1,1,2,2};
///dir array for knight int dyk[10] = {1,-1,-2,2,-2,2,-1,1};

struct node{
    int val;
     int child[15];
     void clear(){
        memset(child,0,sizeof child);

     }
}trie[N];

int ind,flag[N],consistent=0;

void insertTrie(char A[]){
    //printf("dhukse\n");
    int len = strlen(A);
    int i,j,k;
    int cur = 0,fl = 0;
    for(i=0;i<len;i++){
        int c = A[i] - '0';
        ///printf("cur =%d c == %d tey rakhbo notun node er adress ind = %d and \n",cur,c,ind);
        ///printf("cheking cur= %d er node ar c =%d tey aage kono node er adress chilo kina\n",cur,c,trie[cur].child[c]);
        if(trie[cur].child[c]==0){
            //printf("chilo na :D\n");
            trie[ind].clear();
            if(flag[cur] == 1){
                consistent = 1;
                ///printf("cur ======== %d\n",cur);
            }
            trie[cur].child[c] = ind;
            ind++;
            fl = 1;
        }
        cur = trie[cur].child[c];
    }
    if(fl == 0){
            consistent = 1;
        ///printf("heh\n");
    }
    flag[cur] = 1;
    ///printf("shesh holo cur = %d\n",cur);
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        int i,j,k;
        memset(flag,0,sizeof flag);
        scanf("%d",&n);
        ind =1;
        consistent = 0;
        trie[0].clear();
        for(i=0;i<n;i++){
            char A[15];
            scanf("%s",A);
            //cout<<a<<endl;
            insertTrie(A);
        }
        if(consistent == 1)printf("Case %d: NO\n",ct);
        else printf("Case %d: YES\n",ct);
        //for(i=0;i<=100000;i++)trie[i].clear();
    }
}
