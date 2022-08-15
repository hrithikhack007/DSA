// similar as n meetings in onr room.
// sort the meetings according to the increasing order of their finishing time and if their finishing time is same then sort then according to
// their increasing order of indexes.
// now set en to -1 and a ans array.
// start from i=0 to n - 1 and in each iteration, if the starting time of the ith meeting is > en of previous meeting then we can attend this
// meeting so set the en to ending time of ending meeting and push the index of the ith meeting in the ans array.
// sort the ans array before returning as asked in the question.


class Solution {
public:


    static bool comp(vector<int> &a, vector<int> &b) {

        if (a[1] != b[1]) return a[1] < b[1];
        else return a[2] < b[2];
    }

    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {

        vector<vector<int>> meetings;


        for (int i = 0; i < N; i++) {


            meetings.push_back({S[i], F[i], i + 1});
        }

        sort(meetings.begin(), meetings.end(), comp);

        int en = -1;
        vector<int> ans;

        for (int i = 0; i < N; i++) {

            if (meetings[i][0] > en) {
                en = meetings[i][1];
                ans.push_back(meetings[i][2]);

            }

        }

        sort(ans.begin(), ans.end());

        return ans;



    }
};

// t.c. = O(N) + O(NLogN) + O(N) + O(NLogN) = O(NLogN)
// s.c. = O(3*N) = O(N)
