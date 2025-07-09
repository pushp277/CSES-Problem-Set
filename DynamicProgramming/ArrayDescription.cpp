#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

const long long MOD=1e9+7;

int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;
  cin>>n>>m;
  vector<long long> nums(n);

  vector<vector<long long>> dp(n+1, vector<long long>(m+1));

  for(int i=0;i<=m;i++)
    dp[0][i]=1;

  for(int i=0;i<n;i++){
    cin>>nums[i];
  }


  for(int i=1;i<n;i++){
    for(int j=1;j<=m;j++){
      if(nums[i-1] == 0){
        dp[i][j] = dp[i-1][j];
        if(j-1>0)
          dp[i][j]+=dp[i-1][j-1];

        if(j+1<=m)
          dp[i][j]+=dp[i-1][j+1];
      }

      else if(abs(nums[i-1]-j)>1)
        dp[i][j]=0;

      else{
        dp[i][j] = dp[i-1][nums[i-1]];
      }

      dp[i][j]%=MOD;
    }
  }


  if(nums[n-1]){
    cout<<dp[n-1][nums[n-1]]<<'\n';
  }
  else{
    long long ans=0;
    for(int i=1;i<=m;i++){
        ans+=dp[n-1][i];
        ans%=MOD;
    }
    cout<<ans<<'\n';
  }
}
