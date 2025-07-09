#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, x;
  cin>>n>>x;

  vector<int> h(n);
  vector<int> v(n);

  vector<vector<int>> dp(x+1, vector<int>(n+1));

  for(int i=0;i<n;i++)
    cin>>h[i];

  for(int i=0;i<n;i++)
    cin>>v[i];
    
  
  for(int i=1;i<=n;i++){
    for(int j=0;j<=x;j++){
      dp[j][i]=dp[j][i-1];

      if(j-h[i-1] >=0)
        dp[j][i]=max(dp[j][i-1], v[i-1] + dp[j-h[i-1]][i-1]);
      }
    }

  cout<<dp[x][n]<<'\n';
}
