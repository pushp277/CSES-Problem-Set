#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  long long n;
  cin>>n;
  long long sum = (n*(n+1))>>1;
  long long s=0;
  long long v;
  for(int i=0;i<n-1;i++){
      cin>>v;
      s+=v;
  }
  cout<<sum-s<<'\n';
}
