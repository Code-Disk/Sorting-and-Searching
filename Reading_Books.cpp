#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n = 0;
    cin >> n;
    vector<int> book_time(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> book_time[i];
        sum += book_time[i];
    }

    ll timetaking_book = *max_element(book_time.begin(), book_time.end());
    ll j_time = timetaking_book;
    ll k_time = sum - timetaking_book;
    ll total_time = 0;
    if (j_time > k_time)
        total_time = timetaking_book * 2;
    else
        total_time = sum;
    cout << total_time;

    return 0;
}