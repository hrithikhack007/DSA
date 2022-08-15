// so first of all if N<M then we cannot survive even a single day so return -1.
// now, set ans , days,have,extra to 0 and curr = 1 i.e. monday. sunday is from 0 and so on.
// now run a while loop as long as days(survive days) < S and in each iteration:
// if(have>=M): this means if we already have enough food to survive the current day so decrement M from have and if curr!=0 the add N in
// extra i.e. we are keeping track of foods that we can buy at this day if in future we ran out of food.
// else: now, if curr == 0 i.e. we are on sunday so we cannot buy any food so let's check in extra, if extra + have >=M if it is then
// remove N from extra because we would have buy food on some day before so we can use that here therefore we removed that amount of food from
// extra. and if extra doesn't have enough food so we cannot survive the current day so return -1.
// now we added N from extra so we have to add it in have and then remove M from  it i.e. we will consume M food on current day. so even if
// curr is 0 or not we will do this as if curr is 0 we would have get food from some day back so we will have N more food and if curr is not
// 0 then we can simply buy the food on current day and after consuming we will remain with N-M so have -= (N-M) and also ans++ because we
// are buying the food on some day.
// after all this, increment day by 1 as we have survived this day and move curr to (curr+1)%7.



class Solution {
public:
   int minimumDays(int S, int N, int M) {

      if (N < M) return -1;

      int ans = 0, days = 0, have = 0, curr = 1, extra = 0;

      while (days < S) {


         if (have >= M) {

            have -= M;
            if (curr != 0) extra += N;

         } else {

            if (curr == 0) {
               if (extra + have >= M) extra -= N;
               else return -1;

            }

            have += (N - M);
            ans++;


         }

         days++;
         curr = (curr + 1) % 7;

      }


      return ans;

   }
};

// t.c. = O(S)
// s.c. = O(1)

// optimized.

// first we will check how many sundays are present in S days to do this just divide S by 7.
// now no. of days we can buy food let's call it buyingDays = S - sundays, because on sundays we cannot buy.
// total food required to survive S days is S *M where M is the food required per day.
// daysNeeded to buy the required food is ceil(foodRequired/N) where N is the number of food we can buy per day.
// now, if daysNeeded <= buyingDays then return daysNeeded, else we cannot buy the required food for survival in buying days so return -1.


class Solution {
public:
   int minimumDays(int S, int N, int M) {


      int sundays = S / 7;

      int buyingDays = S - sundays;

      int foodRequired = S * M;

      int daysNeeded = ceil((double)foodRequired / N);

      if (daysNeeded <= buyingDays) return daysNeeded;

      return -1;

   }
};

// t.c. = O(1)
// s.c. = O(1)
