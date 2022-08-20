// take an unordered map , set maxfreq to 0. traverse the string s and increment the freq of ch also maximize the maxfreq with this freq.
// if maxfreq>ceil(n/2) then we cannot re-arrange.
// else, take a max heap, traverse the map and push the freq[ch],ch in the heap.
// now set a res string to empty string.
// after this, while the size of heap is > 1 , in each iteration , pop out the two characters having maximum frequency , push the highest
// freq. character first in res then the second highest character. after thi decrement the frequency of both characters by 1. check if the
// freq of character1 is not 0 then again push it into heap similalry check for character 2.
// after the while loop is over check if the size of heap is 1 then push the top character in the res.




class Solution {
public:
    string reorganizeString(string s) {


        int n = s.size();

        unordered_map<char, int> freq;
        int maxFreq = 0;

        for (auto ch : s) {

            freq[ch]++;
            maxFreq = max(maxFreq, freq[ch]);
        }

        if (maxFreq > ceil(n / 2.0)) return "";

        priority_queue<pair<int, char>> pq;

        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        string res = "";

        while (pq.size() > 1) {

            auto ch1 = pq.top();
            pq.pop();
            auto ch2 = pq.top();
            pq.pop();

            res.push_back(ch1.second);
            res.push_back(ch2.second);

            ch1.first--;
            ch2.first--;

            if (ch1.first) pq.push(ch1);
            if (ch2.first) pq.push(ch2);

        }

        if (pq.size() == 1) {
            res.push_back(pq.top().second);
        }

        return res;

    }
};

// t.c. = O(N) + O(26) + O(26*Log(26)) +  O((N/2)*Log(26)) = O(N)
// s.c. = O(26) + O(26) = O(1)



// returning the rearrange string. so first of all we will check if we can rearragne the string with no same adjacent characters by above method
// if we can't then return empty string else, we will try to place max frequency elements on the even indexes first like 2,4,6, and so on.
// since maxf <= ceil(n/2.0) it will at max take all the even positions then after that we will place all the remaining characters and
// at any instance if i becomes >= n then we will reassign it to 1 that means now we are placing characters on odd inidces.

// important edge case: there may be a chance if smaller frequency characters are placed first aftet that maxf characters is place then
// adjacent characters might become same. for e.g.  s = "baaacd", b->1, a->3 , c->1, d->1.
// b a a c a d
// _ _ _ _ _ _
// 0 1 2 3 4 5

// in the above e.g. we can see that maxf char a is placed together because it doesn't start from the 0th index so resulting in using
// odd index as well for placing all the occurences. to tackle this we will first fill maxf characters first.

// a b a c a d
// _ _ _ _ _ _
// 0 1 2 3 4 5

// this makes sure that no characters are adjacent. we can easily prove this , number of even positions is ceil(n/2.0) so as maxf is less than
// it , it can atmax occupy all the even indices and remaining elements will be start from the odd index and for every remaining element it will
// be in between maxf characters so no same adjacent will be placed.
// if maxf characters < ceil(n/2.0) then maxf char will not use all even indices therefore the next char will start from even index but in order
// to make adjacent characters same the frequency of remaining character must be >= ceil but maxf is already less than ceil(n/2.0) so no
// char can be placed such that they form same adjacent char.


class Solution
{
public:
    string reorganizeString(string s)
    {

        vector<int> mp(26, 0);
        int maxi = 0, n = s.size();
        char maxch = '?';

        for (auto a : s)
        {
            mp[a - 'a']++;
            if (mp[a - 'a'] > maxi)
            {
                maxi = mp[a - 'a'];
                maxch = a;
            }
        }

        if (maxi > ceil(n / 2.0)) return "";

        int i = 0;
        string ans(n, ' ');

        while (mp[maxch - 'a'])
        {

            ans[i] = (maxch);
            i += 2;
            mp[maxch - 'a']--;
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {

            while (mp[ch - 'a'] > 0)
            {

                if (i >= n) i = 1;
                mp[ch - 'a']--;
                ans[i] = ch;
                i += 2;
            }
        }

        return ans;
    }
};


// t.c. = O(26 + N) => O(N)
// s.c. = O(26) => O(1)