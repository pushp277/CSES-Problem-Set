#include<iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long long n;
  cin>>n;

  while(n!=1){
    cout<<n<<" ";
    n=n&1 ? 3*n+1L : n>>1;
  }

  cout<<1<<'\n';
}
