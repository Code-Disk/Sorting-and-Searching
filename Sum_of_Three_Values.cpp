#include <bits/stdc++.h>
using namespace std;
int main()
{
    int size = 0, target = 0;
    cin >> size >> target;
    int input = 0, idx = 0;
    vector<int> array(size);
    while (cin >> input)
        array[idx++] = input;

    vector<pair<int, int>> container;
    for (int i = 0; i < size; i++)
        container.push_back({array[i], i + 1});
    sort(container.begin(), container.end());

    for (int locking_index = 0; locking_index < size; locking_index++)
    {
        int locked_number = container[locking_index].first;

        int front = locking_index + 1, rear = size - 1, sum = 0;

        while (front < rear)
        {
            sum = locked_number + container[front].first +
                  container[rear].first;
            if (sum == target)
            {
                cout << container[locking_index].second << " " << container[front].second << " " << container[rear].second;
                return 0;
            }
            else if (sum < target)
                front++;
            else
                rear--;
        }
    }
    cout << "IMPOSSIBLE";
}