#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;
vector<int> nums;

void printArr(vector<vector<int>> &dp, vector<int> &curr, vector<int> &arr1, vector<int> &arr2, int n, int m, int K){
  if(n==0 || m==0){
    if(curr.size() == K){
       nums=curr; 
    }
    return;
  }

  if(arr1[n-1]==arr2[m-1]){
    curr.emplace_back(arr1[n-1]);
    printArr(dp, curr, arr1, arr2, n-1, m-1, K);

    curr.pop_back();
  }

  else{
    if(dp[n-1][m] >= dp[n][m-1])
      printArr(dp, curr, arr1,arr2,n-1,m,K);
    else
      printArr(dp, curr, arr1, arr2, n, m-1, K);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  vector<int> arr1(n);
  vector<int> arr2(m);

  nums.clear();

  for(int i=0;i<n;i++)
   cin>>arr1[i];

  for(int i=0;i<m;i++)
    cin>>arr2[i];
  
  vector<vector<int>> dp(n+1, vector<int>(m+1));

  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(arr1[i-1]==arr2[j-1]){
        dp[i][j] = 1+dp[i-1][j-1];

      }

      else{
        dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  int k=dp[n][m];
  cout<<k<<'\n';
 
  vector<int> curr;
  printArr(dp,curr, arr1, arr2, n, m, k );

  for(int i=k-1;i>=0;i--)
    cout<<nums[i]<<" ";

  cout<<'\n';
}
