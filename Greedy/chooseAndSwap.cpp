// we will store the first occurence of every character in the map.
// set ch1 and ch2 = '?'
// iterate from i=0 to n - 1 and in each iteration we will try to swap this ith character with the character having least ascii value so we
// will run a loop from ch = 'a' till ch < a[i] and for that character ch it must follow two conditions first it should be present in the string
// and second is the first occurence of that character should be > i.
// it must follow second condition else let's say it didn't follow second condition and there is one occurence of character ch before ith
// character so we know ch < a[i] so if we replace ch with a[i] we will make the string lexographically greater than previously it was.
// because if we swap a[i] with ch we also have to swap ch with a[i] so ch should always be on the right side of a[i].
// now if it follow the second condition then we can say we have found an optimal swapping character pair so we set ch1 to a[i] and ch2 to ch.
// and break.
// now we again iterate from i = 0 to n - 1 and in each iteration,if a[i] is ch1 we replace it with ch2 and else if it is ch2 we replace it with
// ch1.

// edge case: use else if here while replacing because if a[i] is ch1 and you replace it with ch2 and you didn't use else for next if then
// the next if will also execute which will again make a[i] from ch2 to ch1. so use else if here.


class Solution {
public:
    string chooseandswap(string a) {

        int n = a.size();

        unordered_map<char, int> mp;

        for (int i = n - 1; i >= 0; i--) {
            mp[a[i]] = i;
        }

        char ch1 = '?', ch2 = '?';

        for (int i = 0; i < n; i++) {
            bool ok = false;
            for (char ch = 'a'; ch < a[i]; ch++) {

                if (mp.find(ch) != mp.end() && mp[ch] > i) {
                    ok = true;
                    ch1 = a[i], ch2 = ch;
                    break;
                }
            }
            if (ok) break;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] == ch1) {
                a[i] = ch2;
            }
            else if (a[i] == ch2) {
                a[i] = ch1;
            }
        }

        return a;

    }

};

// t.c. = O(N) + O(26*N) + O(N) = O(N)
// s.c. = O(26) = O(1)