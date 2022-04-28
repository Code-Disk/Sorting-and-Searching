#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n = 0;
   cin>>n;

   vector< pair<int,int> >movies;  

   for(int i = 0 ; i<n ; i++)
   {
       int starting , ending = 0;  // 3 5
       cin>>starting>>ending;

       movies.push_back( {ending , starting} );  // 5 3
   }

   sort(movies.begin() , movies.end());

    int start = movies[0].first; // ending time 
    int watchList = 1;
   for(int i = 1 ; i<n ; i++){

       if(movies[i].second >= start)
       {
           start = movies[i].first; 
           watchList++; //update
       }
   }

   cout<<watchList;
}