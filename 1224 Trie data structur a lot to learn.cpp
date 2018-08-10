#include<bits/stdc++.h>
#define N 2500005
#define  ll long long
#define pare pair<int,int>
using namespace std;

int ct=0,cases;
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
struct node{
    int val,visitednode;
    int child[4];
    void clear(){
        memset(child,0,sizeof child);
        visitednode = 0;
    }
}trie[N];
int ind = 1,ans = 0;
string A;
void insertTrie(string s){
    int len = s.size();
    int i,j,k,cur = 0,c;

    for(i=0;i<len;i++){
            if(s[i] == 'A') c = 0;
            else if(s[i] == 'C') c = 1;
            else if(s[i] == 'G') c = 2;
             else c = 3;
         // printf("cur == %d && c == %d\n",cur,c);
        if(trie[cur].child[c] == 0){
            trie[ind].clear();
            trie[cur].child[c] = ind;
            ind++;
        }
        cur = trie[cur].child[c];
        trie[cur].visitednode++;
        //printf("increasing cur = %d\n",cur);
        //flag[cur]++;
    }
}
void dfs(int node,int depth){
   // printf("node = %d and depth = %d\n",node,depth);
    int i,j,res;
    for(i=0;i<4;i++){
        ans = max(ans,trie[node].visitednode*depth);
        if(trie[node].child[i] != 0){
             dfs(trie[node].child[i],depth + 1);
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&cases);
    while(cases--){
        ct++;
        ind = 1;
        int n,i;
        ans = 0;
        scanf("%d",&n);
        trie[0].clear();
        while(n--){
            cin>>A;
            insertTrie(A);
        }
        dfs(0,0);
         printf("Case %d: %d\n",ct,ans);
    }

}
