#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n , m ;
   cin>>n>>m;
   multiset<int , greater<int>> priceOfTicket;
   for(int i = 1 ; i<=n ; i++)
   {
       int t;
       cin>>t;
       priceOfTicket.insert(t);
   }

    int customerPrice=0;

    multiset<int>:: iterator it;
    while(m--){
        cin>>customerPrice;

        it = priceOfTicket.lower_bound(customerPrice);
        if(it == priceOfTicket.end())
            cout<<-1<<"\n";
        else
        {
            cout<<*it<<"\n";
            priceOfTicket.erase(it);
        }

    }

}