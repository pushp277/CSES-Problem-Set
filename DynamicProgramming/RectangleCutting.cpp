#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<climits>

using namespace std;

int main(){

  int a,b;
  cin>>a>>b;

  vector<vector<int>> dp(a+1,vector<int>(b+1, INT_MAX));

  for(int i=1;i<=a;i++){
    dp[i][1]=i-1;
  }

  for(int i=1;i<=b;i++){
    dp[1][i]=i-1;
  }

  for(int i=1;i<=min(a,b);i++)
      dp[i][i]=0;

  for(int i=2;i<=a;i++){
    for(int j=2;j<=b;j++){

      for(int k=1;k<max(i,j);k++){
        if(k<i){
          dp[i][j]=min(dp[i][j], 1+dp[i-k][j]+dp[k][j]);
        }
        if(k<j){
          dp[i][j]=min(dp[i][j], 1+dp[i][j-k]+dp[i][k]);
        }
      }
    }
  }

  cout<<dp[a][b]<<'\n';

}
