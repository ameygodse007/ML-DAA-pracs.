#include <bits/stdc++.h>
using namespace std;

int knaps(vector<int>& v,int w,int i,vector<int>& p,int n,int pr,map<int,int>& mp){
  if(i>=n || w<=0){
    return pr;
  }
  if(mp[w]!=0){
    return mp[w];
  }
  int with =0;
  if(w-v[i]>=0){
   with = knaps(v,w-v[i],i+1,p,n,pr+p[i],mp);
  }
  int without =knaps(v,w,i+1,p,n,pr,mp);
  return mp[w] = max(with,without);
}
int main() {
  vector<int> v = {10,20,30};
  vector<int> p = {60,100,120};
  map<int,int> mp;
  cout<<knaps(v,50,0,p,3,0,mp);
  return 0;
} 