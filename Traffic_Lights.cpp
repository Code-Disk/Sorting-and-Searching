#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x = 0;
    int n = 0;
    int light = 0;
    cin >> x >> n;

    set<int> TrafficLights;
    multiset<int> Distance;

    TrafficLights.insert(0);
    TrafficLights.insert(x);
    Distance.insert(x);

    for (int i = 0; i < n; i++)
    {
        cin >> light;
        auto iterator_right = TrafficLights.upper_bound(light);
        auto iterator_left = iterator_right;
        iterator_left--;

        Distance.erase(Distance.find(*iterator_right - *iterator_left));

        Distance.insert(*iterator_right - light);
        Distance.insert(light - *iterator_left);

        TrafficLights.insert(light);

        cout << *Distance.rbegin() << " ";
    }
}