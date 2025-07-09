#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n=0;
  cin>>n;
  if(n==1){
    cout<<1<<'\n';
    return 0;
  }
  if(n<=3){
    cout<<"NO SOLUTION"<<'\n';
    return 0;
  }
  if(n&1){
    for(int i=1;i<=n;i+=2)
      cout<<i<<" ";

    for(int i=2;i<n;i+=2){
      cout<<i<<" ";
    }
  }
  else{
    for(int i=2;i<=n;i+=2)
      cout<<i<<" ";

    for(int i=1;i<n;i+=2){
      cout<<i<<" ";
    }
  }

    cout<<'\n';
}
