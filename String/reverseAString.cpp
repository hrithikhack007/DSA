// using stack. initialize stack of characters. traverse the string from start to end and push the characters into the stack. now while popping
// characters out of the stack we will get it in the reverse order. we can use this to reverse the string. we will again traverse from
// start to end and at each index we will assign the top character of the stack to the s[i] and pop the top character.

string reverseWord(string str) {

	//Your code here

	stack<char> st;

	for (auto character : str) {

		st.push(character);
	}

	for (int i = 0; i < str.size(); i++) {
		str[i] = st.top();
		st.pop();
	}

	return str;

}

// t.c. = O(N)
// s.c. = O(N)

// using two pointers. initialize two pointers l and r starting from 0 and n-1 respectively. in each iteration, swap(s[i],s[j]) and increment
// i and decrement j . repeat this until i crosses j.

string reverseWord(string str) {

	//Your code here

	int l = 0, r = str.size() - 1;

	while (l < r) {

		swap(str[l++], str[r--]);
	}

	return str;

}

// t.c. = O(N)
// s.c. = O(1)