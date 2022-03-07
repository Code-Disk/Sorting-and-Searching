#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired, available;

    int i_desired = 0, j_available = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        int input = 0;
        cin >> input;
        desired.push_back(input);
    }
    for (int i = 0; i < m; i++)
    {
        int input = 0;
        cin >> input;
        available.push_back(input);
    }

    sort(desired.begin(), desired.end());

    sort(available.begin(), available.end());
    while (i_desired < n && j_available < m)
    {

        if (desired[i_desired] - k <= available[j_available] && available[j_available] <= desired[i_desired] + k)

        {
            count++;
            i_desired++;
            j_available++;
        }

        else if (desired[i_desired] < available[j_available])
            i_desired++;
        else
            j_available++;
    }

    cout << count;
}