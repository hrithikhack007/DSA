// declare an activities array array and in that push the end time,start time of activities and sort it according to the increasing order of
// end time.
// now our argument is we will select that activity first which has the lowest finishing time so that other activitiy gets chance to start
// resulting in maximum number of activities to be performed.
// so set maxi to 1 and set the current ending i.e. en to ending of first activity i.e. with the lowest finishing time.
// so en = activities[0][0].
// now iterate from i=1 to n-1 and in each iteration, if the sarting time of ith activity is > en then we can select this activity so increment
// maxi by 1 and set current ending to the ending of this ith activity and continue.


class Solution
{
public:

    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {

        vector<vector<int>> activities;

        for (int i = 0; i < n; i++) {

            activities.push_back({end[i], start[i]});
        }

        sort(activities.begin(), activities.end());

        int maxi = 1;
        int en = activities[0][0];

        for (int i = 1; i < n; i++) {

            if (activities[i][1] > en) {
                maxi++;
                en = activities[i][0];
            }
        }

        return maxi;

    }
};


// t.c. = O(NlogN) + O(N) + O(N) = O(NlogN)
// s.c. = O(2*N) = O(N)