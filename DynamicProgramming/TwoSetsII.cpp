#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
const long long MOD=1e9+7;

long long modinv(long long a) {
    long long res = 1, b = MOD - 2;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin>>n;

  int sum = (n*(n+1))/2;

  if(sum&1){
    cout<<0<<'\n';
    return 0;
  }

  sum/=2;

  vector<long long> dp(sum+1);
  dp[0]=1; 

  for(int i=1;i<=n;i++){
    for(int j=sum;j>=i;j--){
      dp[j]=dp[j-i]+dp[j];
      dp[j]%=MOD;
    }
  }

  cout<<(dp[sum]*modinv(2))%MOD<<'\n';
}
