#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll kadane(vector<ll>arr , int n){

  ll sumTillHere = 0; // warrior
  ll memory = *max_element(arr.begin() , arr.end());  // MaximumSum  -2 -2 -4 -5 -1    

  for(int i = 0 ; i<n ; i++){
    sumTillHere = sumTillHere + arr[i];

    if(sumTillHere>memory)
      memory = sumTillHere;

    if(sumTillHere<0)
      sumTillHere = 0;  // Refreshing our Warrior


  }

  return memory;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n=0;
   cin>>n;
   vector<ll>array;

   ll input=0;
   while (cin>>input)
     array.push_back(input);

  cout<<kadane(array , n);
  
   

}