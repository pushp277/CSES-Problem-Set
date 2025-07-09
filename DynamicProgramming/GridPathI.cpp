#include<iostream>
#include<vector>

using namespace std;

const long long MOD=1e9+7;
int main(){

  int n;
  cin>>n;

  vector<string> v(n);
  vector<vector<long long>> dp(n+1, vector<long long>(n+1));


  for(int i=0;i<n;i++){
      cin>>v[i];
  }


  int l=0;
  while(l<n && v[0][l]!='*')
      dp[0][l++]=1;

  l=0;
  while(l<n && v[l][0]!='*')
      dp[l++][0]=1;



  for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
      if(v[i][j]=='.')
        dp[i][j]=dp[i][j-1]+dp[i-1][j];

      dp[i][j]%=MOD;
    }
  }

  cout<<dp[n-1][n-1]<<'\n';
}
