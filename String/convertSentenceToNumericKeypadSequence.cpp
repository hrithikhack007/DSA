// using unordered map. we will map each character to its corresponding integer in keypad and count of how many times we have to press that key
// to access that character. we noticed that every key excluding 7 and 9 has 3 characters mapped to it. so we will keep a counter and a curr
// char where counter will count the positions of the curr key. like if counter = 1 and curr = '2' that means we are at the first position
// of the key 2, therefore whatever character will be there will be assigned mp[ch] = {curr,counter} signifying that this character is mapped
// to key 2 and counter number of times have to press to access that char.

// at each iteration we will increment counter under mode 3. if counter becomes 0 that means we have noted all the chars of the curr key and
// move on to next key.

// edge case: key 7 has extra character 'S' and key 9 has extra character 'Z' so we will handle them separately.

string printSequence(string S)
{
	//code here.

	unordered_map<char, pair<char, int>> mp;
	int counter = 0, curr = '2';

	for (char ch = 'A'; ch <= 'Z'; ch++) {

		int pos = ch - 'A';

		if (ch == 'S') {
			mp[ch] = {char(curr - 1), 4};

		}
		else if (ch == 'Z') {
			mp[ch] = {char(curr - 1), 4};

		} else {

			mp[ch] = {curr, counter + 1};

		}

		if (ch != 'S' && ch != 'Z') {
			counter = (counter + 1) % 3;
			if (counter == 0) curr = char(curr + 1);
		}

	}

	mp[' '] = {'0', 1};
	string ans = "";

	for (auto a : S) {

		ans += string(mp[a].second, mp[a].first);

	}

	return ans;


}

// t.c. = O(N)
// s.c. = O(1)
