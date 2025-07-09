#include<iostream>
#include<vector>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin>>n;

  vector<int> dp(n+1,1e6+1);
  
  dp[0]=0;
  for(int i=1;i<=n;i++){
    int t=i;

    while(t){
      dp[i]=min(dp[i], 1+dp[i-t%10]);
      t/=10;
    }
  }


  cout<<dp[n]<<'\n';
}
