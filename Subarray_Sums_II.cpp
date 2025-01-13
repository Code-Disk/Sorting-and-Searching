#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll countSubarraysWithSum(vector<int> &arr, int n, int target)
{
    map<ll, int> prefixSumCount;
    ll sum = 0;
    ll count = 0;
    prefixSumCount[0] = 1;

    for (int num : arr)
    {
        sum += num;
        count += prefixSumCount[sum - target];
        prefixSumCount[sum]++;
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0, target = 0;
    cin >> n >> target;
    vector<int> array(n);

    for (int i = 0; i < n; i++)
        cin >> array[i];

    cout << countSubarraysWithSum(array, n, target);

    return 0;
}
