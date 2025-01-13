#include <bits/stdc++.h>
using namespace std;
#define ll long long

int theatre(vector<pair<int, int>> &movies, multiset<int> &availableMembers)
{
    int maxMovies = 0;

    for (const auto &movie : movies)
    {
        int start = movie.second;
        int end = movie.first;

        // Find the earliest member who can watch the movie.
        auto it = availableMembers.upper_bound(start);
        if (it != availableMembers.begin())
        {
            --it;
            availableMembers.erase(it);
            availableMembers.insert(end);
            maxMovies++;
        }
    }
    return maxMovies;
}

int main()
{
    int n, k;
    cin >> n >> k; // Number of movies and members

    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        movies[i] = {end, start}; // Store ending time first
    }

    sort(movies.begin(), movies.end());

    multiset<int> availableMembers;

    // Initialize all members to be free at time free : 0
    for (int i = 0; i < k; i++)
        availableMembers.insert(0);

    cout << theatre(movies, availableMembers) << endl;

    return 0;
}
