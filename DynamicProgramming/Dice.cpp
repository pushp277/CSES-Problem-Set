#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

const long long MOD=1e9+7;
int main(){
  int n;
  cin>>n;
 
  vector<long long> dp(n+1);
  dp[0]=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=6;j++){
      if(i-j>=0)
        dp[i]+=dp[i-j];
      dp[i]%=MOD;
    }
  }
    cout<<dp[n]<<'\n';
  }
