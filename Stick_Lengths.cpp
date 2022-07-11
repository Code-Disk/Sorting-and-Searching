#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n = 0;
   cin>>n;
   vector<ll>stick_lengths;

   int input=0;
   while(cin>>input)
    stick_lengths.push_back(input);

   sort(stick_lengths.begin() , stick_lengths.end());

   int median = stick_lengths[n/2];

   ll cost = 0;

   for(int i  = 0 ; i< n ; i++)
        cost += abs(median-stick_lengths[i]);
    cout<<cost;
}