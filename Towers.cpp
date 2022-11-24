#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    cin >> n;
    // 3 8 2 1 5
    multiset<int> towers;
    int cube = 0;
    multiset<int>::iterator it;
    for (int i = 0; i < n; i++)
    {
        cin >> cube;
        // upper_bound(3) itertor to the end
        it = towers.upper_bound(cube); // 8 next higher value is not present // 2
        if (it == towers.end())
            towers.insert(cube); // 1  5

        else
        {
            towers.erase(it);
            towers.insert(cube);
        }
    }
    cout << (int)towers.size();
}