// case 1: if count of negative is even then we can mutliply all the negative numbers with all the positive numbers.
// case2 : if count of negative is odd then we will leave the least negativity number of greates -ve number and multipy the rest of the -ve
// numbers with all the positive numbers.
// edge case: we have to take atleast one number so if n == 1 then return a[0].
// now set countnegative to 0, greatestNegative to -inf, greatestNegative index to -1, positiveProduct to 0, negativeProduct to 0.
// now iterate from i = 0 to n - 1, and in each iteration if a[i]==0 so continue, if a[i] is < 0 then if a[i] is > greatestNegative then
// set greatestNegative as a[i] and greatestNegativeIndex as i after this increment the countNegative by 1.
// else if a[i]>0, then if positiveProduct is currently zero then set it to 1 and multiply the a[i] with it.

// now if countNegative is even then we can take the greatestnegative element as well so set greatestNegative as -1 else we have to skip the
// greatestNegative.
// now again loop from i=0 to n - 1 and in each iteration if a[i]<0 and i != greatestNegativeIndex then if negativeProduct is 0 then
// set it to 1 and multiply it with a[i].
// now we have maximum positiveProduct and maximumNegative Product , so check if positiveProduct is 0 if it is then simply return negativeProduct
// else check if negativeProduct is 0 if it is then simply return positiveProduct else if both are not 0 then we can multiply them to get the
// maximum product so return mul(positiveProduct,negativeProduct).


class Solution {
public:

#define ll long long
  ll mod = (ll)(1e9 + 7);

  ll mul(ll a, ll b) {

    return ((a % mod) * (b % mod)) % mod;
  }


  long long int findMaxProduct(vector<int>&a, int n) {

    if (n == 1) return a[0];


    ll countNegative = 0, greatestNegative = LLONG_MIN, greatestNegativeIndex = -1;

    ll positiveProduct = 0, negativeProduct = 0;

    for (int i = 0; i < n; i++) {

      if (a[i] == 0) continue;
      else if (a[i] < 0) {

        if (a[i] > greatestNegative) {
          greatestNegative = a[i];
          greatestNegativeIndex = i;
        }
        countNegative++;
      } else {
        if (positiveProduct == 0) positiveProduct = 1;

        positiveProduct = mul(positiveProduct, a[i]);
      }
    }

    if (countNegative % 2 == 0) greatestNegativeIndex = -1;

    for (int i = 0; i < n; i++) {

      if (a[i] < 0 && i != greatestNegativeIndex) {

        if (negativeProduct == 0) negativeProduct = 1;
        negativeProduct = mul(negativeProduct, a[i]);
      }
    }


    if (positiveProduct == 0) {
      return negativeProduct;
    } else if (negativeProduct == 0) {
      return positiveProduct;
    } else {
      return mul(positiveProduct, negativeProduct);
    }


  }
};

// t.c. = O(N) + O(N) = O(N)
// s.c. = O(1)