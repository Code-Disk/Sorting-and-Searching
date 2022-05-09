#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);     
   int size = 0, target_value = 0;

   cin>>size>>target_value; // 4 8

   vector<pair<int ,int >>container;   
   int input =0;
   int postion = 1;
   while(cin>>input)
      container.push_back( {input , postion++} );  //{2,1} {7,2} {4,3} {1,4}

   sort(container.begin() , container.end()); // {1,4} {2,1} {4,3} {7,2}

   int front = 0 , rear = size-1 , flag=0;

   while(front!=rear){

      int sum = container[front].first + container[rear].first;

      if(sum<target_value)
         front++;
      else if(sum>target_value)
         rear--;
      
      else if(sum ==target_value){
         cout<<container[rear].second<<" "<<container[front].second;
         flag=1;
         break;
      }
   }
   if(flag==0)
      cout<<"IMPOSSIBLE";

}