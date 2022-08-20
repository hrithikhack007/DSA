// brute.
// set mini to inf,declare atms.
// call the rec. function by passing idx=0,atms,k=k,mat,mini as arguments, and in each rec. call check if atms.size() + (mat.size()-idx)
// <k if it is then we cannot select k atms even if we take all elements from idx to k-1 to return from here.
// if atms.size() == k, then we will try to find the maximum cost from(minimum cost from a city to the k selected atms for each city)
// now we will try to minimize our mini with this overall maximum cost.


class Solution {
public:

    void rec(int idx, vector<int> &atms, int k, vector<vector<int>> &mat, int &mini) {

        if (atms.size() + (mat.size() - idx) < k) return;

        if (atms.size() == k) {

            int costOverall = INT_MIN;

            for (int city = 0; city < mat.size(); city++) {

                int costCity = INT_MAX;

                for (auto atm : atms) {

                    costCity = min(costCity, mat[atm][city]);
                }

                costOverall = max(costOverall, costCity);
            }

            mini = min(mini, costOverall);

            return;

        }

        atms.push_back(idx);
        rec(idx + 1, atms, k, mat, mini);
        atms.pop_back();
        rec(idx + 1, atms, k, mat, mini);


    }

    int selectKcities(int n, int k, vector<vector<int>>& mat) {


        int mini = INT_MAX;

        vector<int> atms;

        rec(0, atms, k, mat, mini);

        return mini;

    }
};

// t.c. = O((2^N)*(N*K))
// s.c. = O(N)(stack space) + O(K)
