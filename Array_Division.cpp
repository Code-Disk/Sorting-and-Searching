#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool splittingPossible(const vector<ll> &nums, int k, ll maxSum)
{
    ll currentSum = 0;
    ll subarrayCount = 1;
    for (int num : nums)
    {
        ll total = currentSum + num;
        if (total > maxSum)
        {
            subarrayCount++;
            currentSum = num;
            if (subarrayCount > k)
                return false;
        }
        else
            currentSum += num;
    }
    return true;
}

ll arrayDivision(const vector<ll> &nums, int k)
{
    ll left = *max_element(nums.begin(), nums.end());
    ll right = accumulate(nums.begin(), nums.end(), 0LL);
    ll result = right;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (splittingPossible(nums, k, mid))
        {
            result = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return result;
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    ll result = arrayDivision(nums, k);
    cout << result;
    return 0;
}