#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin>>n;
  long long ans=0;
  long long prev=0;
  long long v;
  for(int i=0;i<n;i++){
    cin>>v;
    if(v<prev)
      ans+=prev-v;
    else
      prev=v;
  }
  cout<<ans<<'\n';
}
