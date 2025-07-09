#include<iostream>
#include<vector>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,x;
  cin>>n>>x;
  vector<int> dp(x+1,1e6+7);
  vector<int> v(n);

 for(int i=0;i<n;i++)
    cin>>v[i];


 dp[0]=0;

  for(int i=0;i<n;i++){
    for(int j=v[i];j<=x;j++){
          dp[j]=min(dp[j], 1+dp[j-v[i]]);
    }
  }
  if(dp[x]>=1e6+6)
    cout<<-1<<'\n';
  else
    cout<<dp[x]<<'\n';
}
