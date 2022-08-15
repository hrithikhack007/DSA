// set cost to 0, sort the horizontal and vertical cuts costs in increasing order. set vp(number of vertical pieces) and hp(number of horizontal
// pieces) to 1.
// now we can have n - 1 horizontal cuts and m - 1 vertical cuts so set h = n - 2 and v = m - 2 (0 based indexing).
// now as long as h>=0 and v>=0 then in each iteration, if cost of horizontal cut is > than cost of vertical cost then it is better to perform
// the horizontal cut first because if we perform the vertical cut first then the number of horizontal pieces will increase and more cost will
// be required to perform the same horizontal cut so it is better to perform  horizontal cut with maximum cost on minimum pieces.
// so increment the cost by horizontal cut cost * horizontal pieces i.e. y[h]*hp then decrement the h by 1 and increment the vertical pieces
// vp by 1.
// similarly if the cost of vertical cut is more than the current horizontal cut the perform the vertical cut so increment the cost by
// the vertical cost * vertical pieces i.e. x[v]*vp and then decrement v by 1 and increment the number of horizontal pieces by 1.
// if h or v finished reached -1 then break.
// if h is still >=0 then we have to perform the remainig cuts so increment the cost by y[h]*hp and decrement h by 1 do this till h>=0
// similarly if v is still >=0 that means some vertical cuts are remaining so increment the cost by x[v]*vp and decrement v by 1 do this
// till v>=0.


class Solution {
public:
    int minimumCostOfBreaking(vector<int> x, vector<int> y, int M, int N) {

        int cost = 0;

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        int vp = 1, hp = 1;

        int h = N - 2 , v = M - 2;

        while (h >= 0 && v >= 0) {

            if (y[h] > x[v]) {
                cost += (y[h--] * hp);
                vp++;
            } else {
                cost += (x[v--] * vp);
                hp++;
            }

        }

        while (h >= 0) {
            cost += (y[h--] * hp);
        }

        while (v >= 0) {
            cost += (x[v--] * vp);
        }


        return cost;

    }
};

// t.c. = O(NLogN) + O(MLogM) + O(N+M) = O(NLogN + MLogM)
// s.c. = O(1)