#include<iostream>
#include<vector>
#include<numeric>

using namespace std;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin>>n;

  vector<int> val(n);
  int mxSum = 0;
  for(int i=0;i<n;i++){
    cin>>val[i];
    mxSum+=val[i];
  }
vector<bool> dp(mxSum+1);
dp[0]=true;

for(int t=0;t<n;t++){
  for(int j=mxSum;j>=val[t];j--){
    dp[j]=dp[j-val[t]] | dp[j];
  }
}


  int c=0;
  for(int i=1;i<=mxSum;i++){
    c+=dp[i];
  }
  cout<<c<<'\n';
  for(int i=1;i<=mxSum;i++){
    if(dp[i])
      cout<<i<<" ";

  }

  cout<<'\n';

}
