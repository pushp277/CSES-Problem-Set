#include<iostream>
#include<numeric>
#include<unordered_set>

using namespace std;

int main(){
  long long n;
  cin>>n;

  long long sum = (n*(n+1))/2;

  if(sum&1){
    cout<<"NO"<<'\n';
  }

  else{
  sum/=2;

  cout<<"YES"<<'\n';
  unordered_set<long long> us;

    int l=n;
  while(sum){
    if(sum<=l){
        us.insert(sum);
        sum=0;
        continue;
    }

    sum-=l;
    us.insert(l);
    l--;
  }

  cout<<us.size()<<'\n';

  for(auto itr=us.begin();itr!=us.end();itr++){
    cout<<*itr<<" ";
  }
  cout<<'\n';
  cout<<n-us.size()<<'\n';

  for(int i=1;i<=n;i++){
    if(us.find(i)==us.end())
      cout<<i<<" ";
  }
  cout<<'\n';
  }
}
