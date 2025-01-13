#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll countSubarraysWithSum(vector<ll> &arr, int n)
{
    map<ll, int> prefixSumCount;
    ll sum = 0;
    ll count = 0;

    // Initialize with 0 sum occurring once
    prefixSumCount[0] = 1;

    for (int i = 0; i < n; i++)
    {
  
        sum = (sum + arr[i]) % n;

        if (sum < 0)
            sum += n;
        
        count += prefixSumCount[sum];
 
        prefixSumCount[sum]++;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    cin >> n;
    vector<ll> array(n);

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << countSubarraysWithSum(array, n);
    return 0;
}
