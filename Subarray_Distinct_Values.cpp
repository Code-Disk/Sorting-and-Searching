#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll kDistictSubaaray(vector<ll> &nums, int k)
{
    int n = nums.size();     // size of the arraY
    int left = 0, right = 0; // TWO POINTERS
    unordered_map<ll, int> count;
    ll result = 0;
    while (right < n)
    {

        //? Add in the current window
        count[nums[right]]++;

        //! Attack
        while ((int)count.size() > k)
        {
            count[nums[left]]--;
            if (count[nums[left]] == 0)
                count.erase(nums[left]);
            left++;
        }

        //? Calculate
        result += right - left + 1;
        right++;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<ll> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    ll result = kDistictSubaaray(nums, k);
    cout << result << endl;
}
