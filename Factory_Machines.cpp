#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    ll t = 0;
    cin >> n >> t;
    vector<ll> time;
    time.reserve(n);
    ll input = 0;
    while (cin >> input)
        time.push_back(input);
    ll low = 0;
    ll high = (1e18);
    ll time_needed = 0;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll products_made = 0;
        for (ll i : time)
        {
            products_made += mid / i;
            if (products_made >= t)
                break;
        }
        if (products_made >= t)
        {
            time_needed = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << time_needed;
}