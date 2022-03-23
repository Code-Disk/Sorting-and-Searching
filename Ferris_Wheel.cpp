#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0, x = 0;
    cin >> n >> x;
    vector<int> weight;
    int input;
    while (cin >> input)
        weight.push_back(input);

    sort(weight.begin(), weight.end());

    int i = 0;
    int j = n - 1;

    int count = 0;
    while (i <= j)
    {
        if (weight[i] + weight[j] <= x)
        {
            count++;
            i++;
            j--;
        }
        else
        {
            count++;
            j--;
        }
    }

    cout << count;
}