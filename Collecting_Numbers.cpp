#include <bits/stdc++.h>
using namespace std;
#define ll long long
int collectingNumbers(vector<int> loc, int n)
{
   int pass = 0;
   for (int i = 1; i < n; i++)
   {
      if (loc[i + 1] < loc[i])
         pass++;
   }
   return pass + 1;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n = 0;
   cin >> n; // 5
   int input = 0;
   vector<int> location(n + 1); // 0 1 2 3 4 5
   int i = 0;
   while (cin >> input) // 4 2 1
   {
      location[input] = i; // location[1] = 3
      i++;
   }
   cout << collectingNumbers(location, n);
}
