// first we have to sort the jobs according to the starting time then dp[i] will represent the maximum profit we can get if
// I execute the ith job in last.
// we have to sort the timings according to startime otherwise we won't be able tell if multiple jobs are overlapping or not.
// so we will first set maxi to 0 and then iterate from i=0 to n-1 and in each iteration first set dp[i] to the profit of the ith
// job then iterate from j=i-1 to 0 and in each iteration check if the endtime of j <= starttime of i then we can execute ith job just after
// jth job so maximum profit till jth job + profit for ith job we will maximize dp[i] with that value i.e. dp[i] = max(dp[i],dp[j]+jobs[i].p)
// now we are sure that if we execute ith job after jth job it won't overlap with any jobs before jth job because end of j <= start of i
// and start of j will obviously be <= start of [i] and the jobs before jth job had their end time <= start of j so their end time will
// also be <= start of i. hence proof.



class Solution {
public:

    struct Job {

        int st , en , p;

        Job(int _st, int _en, int _p) {
            st = _st;
            en = _en;
            p = _p;
        }

    };

    static bool comp(Job a, Job b) {

        return a.st < b.st;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {


        int n = profit.size();

        vector<Job> jobs;

        for (int i = 0; i < n; i++) {

            Job curr = Job(startTime[i], endTime[i], profit[i]);

            jobs.push_back(curr);

        }


        sort(jobs.begin(), jobs.end(), comp);

        vector<int> dp(n);

        int maxi = 0;

        for (int i = 0; i < n; i++) {

            dp[i] = jobs[i].p;

            for (int j = i - 1; j >= 0; j--) {

                if (jobs[j].en <= jobs[i].st) {
                    dp[i] = max(dp[i], dp[j] + jobs[i].p);
                }

            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;




    }
};

// t.c. = O(N) + O(NLogN) + O(N^2) = O(N^2)
// s.c. = O(3*N) + O(N) =  O(N)


// optimized approach. dp + binary search.
// we will sort the jobs according to the finishing time  in non-decreasing order.
// dp[i] represents maximum profit we can get if we optimally execute subset of jobs from starting i+1 jobs.
// now, set dp[0] to the jobs[2] i.e. profit from first job, set maxi to dp[0][2].
// start iterating from i=1 to n-1, in each iteration find out the index of first job in the range 0 to i-1 whose ending time is >
// starting time of ith job using binary search as we have sorted jobs according to finish time.
// now justGreater is the first index of the job whose ending time is > starting time of ith job so that means all the jobs from
// 0 to justgreater - 1 will have endingtime <= starting time of ith job. so what is the maximum profit we can get if we wanted to choose
// subset of jobs from 0 to justGreater - 1 jobs i.e. dp[justGreater-1] and add profit of the ith job in it because endingtime of any
// job in that range is <= starting time of ith job so we can execute ith job after any of the last job performed from that subset.
// so dp[i] = dp[justGreater-1] + jobs[i][2].
// now we can also choose to not perform ith job so in that case we have remaining i-1 jobs so we will maximize dp[i] with that
// i.e. if we don't perform ith job then the maximum profit we can get from the remaining i-1 jobs so dp[i] = max(dp[i],dp[i-1]).
// also edge case: if justGreater is 0 that means there is no jobs available whose endingtime <= starting time of ith job so if we choose
// this job then we cannot choose any jobs from remaining i-1 jobs, so we will already initialized dp[i] with the profit of the ith job.
// and then if justGreater - 1 == -1 then don't then just ignore dp[justGreater-1] + jobs[i][2].


class Solution {
public:

    int upperBound(int l, int r, int st, vector<vector<int>> &jobs) {

        int ub = 0;

        while (l <= r) {

            int mid = (l + r) / 2;

            if (jobs[mid][0] > st) {
                ub = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        return ub;

    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {


        int n = profit.size();

        vector<vector<int>> jobs;

        for (int i = 0; i < n; i++) {



            jobs.push_back({endTime[i], startTime[i], profit[i]});

        }


        sort(jobs.begin(), jobs.end());

        vector<int> dp(n);

        dp[0] = jobs[0][2];


        for (int i = 1; i < n; i++) {

            dp[i] = jobs[i][2];
            int justGreater = upperBound(0, i, jobs[i][1], jobs);
            justGreater--;
            if (justGreater != -1) {
                dp[i] = dp[justGreater] + jobs[i][2];
            }
            dp[i] = max(dp[i - 1], dp[i]);

        }


        return dp[n - 1];




    }
};


// t.c. = O(NLogN) + O(NLogN) = O(NLogN)
// s.c. = O(3*N) + O(N) = O(N)
