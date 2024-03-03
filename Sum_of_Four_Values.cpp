#include <bits/stdc++.h>
using namespace std;
#define ll long long
int twoSum(int front, int rear, int s, int size, vector<pair<int, int>> &container, int target_value)
{

    int sum = 0;
    while (front < rear)
    {

        sum = s;
        sum += container[front].first + container[rear].first;

        if (sum < target_value)
            front++;
        else if (sum > target_value)
            rear--;
        else if (sum == target_value)
        {
            cout << container[front].second << " " << container[rear].second << " ";
            return 1;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size = 0, target = 0;
    cin >> size >> target;
    vector<pair<int, int>> container;
    int input = 0;
    int postion = 1;
    while (cin >> input)
        container.push_back({input, postion++}); //{1,1} {2,2} {3,3} {5,4} {3,5} {4,6}

    sort(container.begin(), container.end()); //! {1,4} {2,2} {3,3} {3,5} {4,6} {5,4}
    int sum = 0, result = 0;
    for (int locking_index = 0; locking_index < size; locking_index++)
    {
        for (int locking_index2 = locking_index + 1; locking_index2 < size; locking_index2++)
        {
            int locked_number = container[locking_index].first;
            int locked_number2 = container[locking_index2].first;

            int front = locking_index2 + 1, rear = size - 1, sum = locked_number + locked_number2;

            result = twoSum(front, rear, sum, size, container, target);
            if (result == 1)
            {
                cout << container[locking_index].second << " " << container[locking_index2].second;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}