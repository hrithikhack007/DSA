// simply use map here.
// declare a map of string,vector of string.
// traverse the string_list and for each string and sort it using count sort and the sorted string will act as the key because anagrams in sorted
// are same so insert the list in the vector corresponding to its sorted key.
// In this way, all the anagrams will be pushed into the same vector.
// after this, traverse the map again, and now it.second will be the vector of string which contain all anagrams so push it into ans.
// now sort the ans as we want ans in lexograhpically smaller order.

// countSort function, here we will take a vector as a map of size 26 initialized to 0.
// then we will traverse the string s and for each character ch , we will increment its frequency in the map.
// initialize a string res = ""(or we can simply use the string s as well). loop from i=0 to i<26 and for each i if its frequency in the map
// is not 0 then decrement its frequency by 1 and push the respective character in the res string. in this way we will get the sorted string because
// we are pushing characters from smallest to largest.

class Solution {
public:

  string countSort(string &s) {

    vector<int> mp(26, 0);

    for (auto ch : s) mp[ch - 'a']++;

    string res = "";

    for (int i = 0; i < 26; i++) {
      while (mp[i]--) {
        res.push_back(char('a' + i));
      }
    }

    return res;
  }

  vector<vector<string> > Anagrams(vector<string>& string_list) {


    unordered_map<string, vector<string>> mp;

    for (auto list : string_list) {

      mp[countSort(list)].push_back(list);
    }

    vector<vector<string>> ans;

    for (auto it : mp) {
      ans.push_back(it.second);
    }

    sort(ans.begin(), ans.end());

    return ans;



  }
};

// t.c. = O(N*(26+l) + N*M(LogN))
// s.c. = O(N*l) + O(26) = O(N*l)

// N is the number of words and l is the average length of the word.
