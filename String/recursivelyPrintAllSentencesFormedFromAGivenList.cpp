// recursion + backtracking. we will start from idx = 0 i.e. first list of words and will call till idx == n i.e. till all the list is
// covered. at each list we have m choices of words to pick from so we will choose one word at a time and add it to the sentence
// and call further on list  idx+1, after returning from that call we will pop that word out from sentence and choose some other word.
// if  idx==n we insert the formed sentence in sentences array.

class Solution {
public:

	void rec(int idx, vector<vector<string>> &list, vector<string> &sentence, vector<vector<string>> &sentences) {

		if (idx == list.size()) {
			sentences.push_back(sentence);
			return;
		}


		for (int i = 0; i < list[idx].size(); i++) {

			sentence.push_back(list[idx][i]);
			rec(idx + 1, list, sentence, sentences);
			sentence.pop_back();
		}




	}

	vector<vector<string>> sentences(vector<vector<string>>&list) {
		//Write your code here


		vector<vector<string>> sentences;

		vector<string> sentence;



		rec(0, list, sentence, sentences);

		return sentences;

	}
};

// t.c. = O(M^N) => M is the no. of columns and N is the no. of rows in list.
// s.c. = O(M^N(to store sentences) + O(N)(stack space))
