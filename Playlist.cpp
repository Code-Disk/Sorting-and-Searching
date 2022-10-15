#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int war_area; // n
    cin >> war_area;
    map<int, int> enemy_location;       //
    vector<int> war_zone(war_area + 1); // indexing from 1 1 2 1 3 2 7 4 2
    for (int i = 1; i <= war_area; i++)
        cin >> war_zone[i]; // 1 1 2..

    int warrior1 = 1;
    int king = 0; // 0

    for (int warrior2 = 1; warrior2 <= war_area; warrior2++)
    {
        // warrior 1 condtion
        if (warrior1 < enemy_location[war_zone[warrior2]] + 1)
            warrior1 = enemy_location[war_zone[warrior2]] + 1;

        // condition for kings points
        if (king < warrior2 - warrior1 + 1) // window size more king takes the point
            king = warrior2 - warrior1 + 1;

        // Fill the enemy location
        enemy_location[war_zone[warrior2]] = warrior2;
    }
    cout << king;
}