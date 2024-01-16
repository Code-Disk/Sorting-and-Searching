#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    cin >> n; // no of customers
    vector<pair<pair<int, int>, int>> bookings(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bookings[i].first.first >> bookings[i].first.second;
        bookings[i].second = i;
    }
    sort(bookings.begin(), bookings.end());
    int room = 0;
    vector<int> booked(n);
    set<pair<int, int>> emptyRoom;
    for (int i = 0; i < n; i++)
    {
        if (emptyRoom.empty())
        {
            room++;
            emptyRoom.insert({bookings[i].first.second, room});
            booked[bookings[i].second] = room;
        }
        else
        {
            auto it = emptyRoom.begin();
            pair<int, int> firstDeparture = *it;
            if (firstDeparture.first < bookings[i].first.first)
            {
                emptyRoom.erase(*it);
                emptyRoom.insert({bookings[i].first.second, firstDeparture.second});
                booked[bookings[i].second] = firstDeparture.second;
            }
            else
            {
                room++;
                emptyRoom.insert({bookings[i].first.second, room});
                booked[bookings[i].second] = room;
            }
        }
    }
    cout << room << "\n";
    for (int i = 0; i < n; i++)
        cout << booked[i] << " ";
}