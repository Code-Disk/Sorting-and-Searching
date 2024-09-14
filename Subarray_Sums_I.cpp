#include <bits/stdc++.h>
using namespace std;
#define ll long long

int slidingWindow(vector<ll> arr, int n, int target)
{

    int left = 0, right = 0; // warriors
    int count = 0;
    int sumTillHere = 0;
    while (right < n)
    {
        sumTillHere = sumTillHere + arr[right];

        while (sumTillHere > target and left <= right)
        {
            sumTillHere -= arr[left];
            left++;
        }
        if (sumTillHere == target)
        {
            count++;
            sumTillHere -= arr[left];
            left++;
        }
        right++;
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0, target = 0;
    cin >> n >> target;
    vector<ll> array;

    ll input = 0;
    while (cin >> input)
        array.push_back(input);

    cout << slidingWindow(array, n, target);
}