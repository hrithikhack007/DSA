// set cost to 0.
// take a min priority_queue.
// push all the ropes in heap.
// while size of heap is > 1 , pop the two smallest length rope out of heap add their sum in cost and push the sum of their length
// in heap.

// intuition: the cost will be minimized if at every connection we connect the smallest length ropes so that's why we use min heap
// to keep track of minimum length rope in efficient time.



class Solution
{
public:

#define ll long long
    long long minCost(long long arr[], long long n) {


        ll cost = 0;

        priority_queue<ll, vector<ll>, greater<ll>> pq;

        for (int i = 0; i < n; i++) {

            pq.push(arr[i]);
        }

        while (pq.size() > 1) {

            ll rope1 = pq.top();
            pq.pop();
            ll rope2 = pq.top();
            pq.pop();

            cost += (rope1 + rope2);
            pq.push(rope1 + rope2);
        }

        return cost;

    }
};

// t.c. = O(N)(heapify) + O(NLogN) = O(NLogN)
// s.c. = O(N)