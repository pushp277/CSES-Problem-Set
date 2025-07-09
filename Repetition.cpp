#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  string s;
  cin>>s;
  n=s.length();
  int ans=1;
  int i=0;
  while(i<n){
    int t=0;
    while(i+t < n && s[i+t]==s[i])
      t++;

    ans = max(ans,t);
    i+=t;
  }
  cout<<ans<<'\n';
}
