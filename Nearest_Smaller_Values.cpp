#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> nearestSmallerToLeft(int n, vector<int> &arr)
{
    stack<int> container; // position of the values
    vector<int> pos(n, 0);

    for (int i = 0; i < n; i++)
    {

        // remove
        while (!container.empty() and arr[container.top()] >= arr[i])
            container.pop();

        if (!container.empty())
            pos[i] = container.top() + 1; //..adding 1 to this

        container.push(i);
    }
    return pos;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> result = nearestSmallerToLeft(n, arr);

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";

    cout << "\n";

    return 0;
}