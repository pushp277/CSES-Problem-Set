#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

const long long MOD=1e9+7;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  vector<vector<long long>> dp(1000001, vector<long long>(9,0));
  
  for(int i=1;i<=8;i++)
    dp[0][i]=1;
  
  vector<vector<int>> groups({{3,7,8},{1,2,4,5,6}});
  
  vector<int> group(9);

  group[1]=1;
  group[2]=0;
  group[3]=1;
  group[4]=1;
  group[5]=1;
  group[6]=1;
  group[7]=0;
  group[8]=0;

  for(int i=1;i<=1000000;i++){
    for(int j=1;j<=8;j++){
      vector<int> g = groups[group[j]];
      for(int x: g){
        dp[i][j]+=dp[i-1][x];
        dp[i][j]%=MOD;
      }
    }
  }
cin>>t;
  while(t--){

    int v;
    cin>>v;
    cout<<(dp[v-1][3]+dp[v-1][7])%MOD<<'\n';
  }
}
