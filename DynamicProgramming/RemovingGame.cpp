#include<iostream>
#include<climits>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin>>n;
  vector<long long> v(n);

  for(int i=0;i<n;i++)
    cin>>v[i];

  vector<vector<long long>> dp(n+3, vector<long long>(n+1));


  for(int i=1;i<=n;i++)
    dp[i][i]=v[i-1];


  for(int l=n;l>0;l--){
    for(int r=l+1;r<=n;r++){
      dp[l][r]=v[l-1];
     
        dp[l][r]+=min(dp[l+2][r], dp[l+1][r-1]);

      dp[l][r]=max(dp[l][r], v[r-1]+min(dp[l+1][r-1], dp[l][r-2]));
    }
  }

  cout<<dp[1][n]<<'\n';
}
