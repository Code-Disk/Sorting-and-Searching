#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n = 0;
   cin>>n;

   map <int,int> customers;

   while(n--){

      int arrival = 0, leaving =0;
      cin>>arrival>>leaving;

      customers.insert(pair<int , int> (arrival , 1));
      customers.insert(pair<int , int> (leaving , -1));
   }
   int presesntCustomers = 0;
   int maximumCustomers = 0;

   for(auto i = customers.begin() ; i!=customers.end() ; i++){
         presesntCustomers+= i->second;
         maximumCustomers = max(maximumCustomers , presesntCustomers);
   }

   cout<<maximumCustomers;
}