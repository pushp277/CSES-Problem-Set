#include<iostream>
#include<vector>
using namespace std;

long long findV(long long n){
  long long N=n/2;
  if(n==0)
      return 1;

  if(n&1)
    return 4*(n*N - N*(N-1)+1);

  else
    return 1+findV(n-1);

}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  //let's do preprocessing

    int t;
  cin>>t;
  vector<long long> ans;
  while(t--){
    long long x,y;
    cin>>y>>x;
    y--;
    x--;
    
    if(x>=y){
      if(x&1){
       ans.emplace_back(findV(x)-(2*x-y));
      }
      else
        ans.emplace_back(findV(x)+(2*x-y));
    }

    else{
      if(y&1){
        ans.emplace_back(findV(y)-x);
      }
      else
          ans.emplace_back(findV(y)+x);
    }

  }


  for(long long x: ans){
    cout<<x<<'\n';
  }
}
