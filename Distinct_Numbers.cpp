#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    cin >> n;
    vector<int> list;
    int input;
    while (cin >> input)
        list.push_back(input);

    sort(list.begin(), list.end());
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        while (list[i] == list[i + 1])
            i++;

        count++;
    }

    cout << count;
}