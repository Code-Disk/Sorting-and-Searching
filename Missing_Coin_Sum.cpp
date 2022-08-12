#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n = 0;
   cin>>n;
   int input=0;
   vector<int>coins;
   while(cin>>input)
        coins.push_back(input);
    
    sort(coins.begin() , coins.end());

    int position=0;
    ll sum = 0;

    while (position<n)
    {
        if( (sum+1) >= coins[position] )
            sum+=coins[position];
        else 
            break;

        position++;
    }
    cout<<sum+1;

}