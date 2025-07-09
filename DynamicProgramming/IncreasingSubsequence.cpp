#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
    cin>>arr[i];

  set<int> s;

  for(int i=0;i<n;i++){
    auto itr = s.lower_bound(arr[i]);
    if(itr==s.end())
      s.insert(arr[i]);

    else{
      s.erase(itr);
      s.insert(arr[i]);
    }
  }


  cout<<s.size()<<'\n';
    
}
