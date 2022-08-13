// so we have n trains and m platforms. a train has arrival time, departure time and platform number where the train wants to stop.
// now we can segregate/separate the trains of the similar platforms in one group. for e.g. trains who wants to stop at 5 will be grouped together
// and so on for other platforms.
// so for this we will create an adjacency list of size m + 1 as platforms can be from 1 to m. then we will traverse all trains and push its depart,
// arrival in its respective platform slot i.e. train of platform 5 will push it dep,arr time in adj[5].
// now traverse all platforms and sort the train timings for each platform according to the increasing order of their departure time.
// now set maxi to 0.
// again traverse all platforms from 1 to m and if there is atleast one train then increment maxi by 1 and set current end to departure time of the
// first train , now traverse the timings of trains of that ith platform and for each timing if the arrival is >= current ending then we can stop the
// jth train after the departure of previous train so increment maxi by 1 and update en to departure time of current train.


// intuition: same as max length chain, just we have to group similar platforms together as they trains with platform x won't interfere with trains of
// of platform y wher x != y.



#include<bits/stdc++.h>

int maxStop(vector<vector<int>> &trains, int n, int m)
{

    vector<vector<int>> adj[m + 1];

    for (auto train : trains) {

        adj[train[2]].push_back({train[1], train[0]});
    }

    for (int i = 1; i <= m; i++) sort(adj[i].begin(), adj[i].end());

    int maxi = 0;

    for (int i = 1; i <= m; i++) {

        if (adj[i].size() != 0) {

            maxi++;
            int en = adj[i][0][0];

            for (int j = 1; j < adj[i].size(); j++) {

                if (adj[i][j][1] >= en) {
                    maxi++;
                    en = adj[i][j][0];
                }
            }
        }
    }

    return maxi;


}

// t.c. = O(N) + O(M) + O(M+N) = O(M+N)
// s.c. = O(M + N)
