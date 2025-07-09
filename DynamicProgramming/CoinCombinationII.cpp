#include<iostream>
#include<vector>

using namespace std;

const long long MOD=1e9+7;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,x;
  cin>>n>>x;

  vector<int> v(n);

  for(int i=0;i<n;i++)
    cin>>v[i];

  vector<long long> dp(x+1);
  dp[0]=1;

  for(int i=0;i<n;i++)
    for(int j=v[i];j<=x;j++){
      dp[j]+=dp[j-v[i]];
      dp[j]%=MOD;
    }
      

  cout<<dp[x]<<'\n';
}
