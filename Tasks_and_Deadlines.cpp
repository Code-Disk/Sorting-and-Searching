#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    cin >> n;
    int duration = 0, deadline = 0;
    vector<pair<int, int>> tasks;
    while (n--)
    {
        cin >> duration >> deadline;
        tasks.push_back({duration, deadline});
    }
    sort(tasks.begin(), tasks.end()); // nlogn

    ll ans = 0, tt = 0;
    for (auto it : tasks)
    {
        // deadline - finishing time
        ans += it.second - it.first - tt;
        tt += it.first;
    }
    cout << ans;
}