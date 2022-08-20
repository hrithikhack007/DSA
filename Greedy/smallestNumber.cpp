// set num to empty string.
// start from i = 0 to D - 1, and for each position we will try to place the smallest digit so start from d = '0' to '9' and for each
// digit check if i==0 && d=='9' then we cannot place '0' in the first position so continue else, if we place digit d at ith position
// then the remaining D - i - 1 positions should be able to form number with sum S - d so we will check if the maximum sum we can form
// with the remaining position is >= remaining sum i.e. S - d then we can place the digit d at position i so push digit d in num and
// subtract d from S and break. after the completion of the inner loop if the size of num is not equal to i+1 that means we were not
// able to select any digit for the ith position so it is impossible to form the number with sum S with d digits.


class Solution {
public:
    string smallestNumber(int S, int D) {

        string num = "";


        for (int i = 0; i < D; i++) {

            for (char d = '0'; d <= '9'; d++) {

                if (i == 0 && d == '0') continue;

                if ((D - i - 1) * (9) >= (S - (d - '0'))) {

                    S -= (d - '0');
                    num.push_back(d);
                    break;
                }
            }

            if (num.size() != i + 1) return "-1";
        }

        return num;

    }
};

// t.c. = O(D*10) = O(D)
// s.c. = O(1)

// we can beforehand check the condition where it is impossible to form the valid number and the conditon is if D*9 < S then we cannot
// form it so directly return "-1".

class Solution {
public:
    string smallestNumber(int S, int D) {


        if (9 * D < S) return "-1";

        string num = "";


        for (int i = 0; i < D; i++) {

            for (char d = '0'; d <= '9'; d++) {

                if (i == 0 && d == '0') continue;

                if ((D - i - 1) * (9) >= (S - (d - '0'))) {

                    S -= (d - '0');
                    num.push_back(d);
                    break;
                }
            }

        }

        return num;

    }
};

