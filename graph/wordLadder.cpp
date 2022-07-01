// using bfs and map.

// basically, we will push the beginword into queue and while queue is not empty at each iteration, generate all the 1 differ words of the
// current word and for each of those word check if distance is 0 and present in the wordlist if true then add the distance of that word
// to distace of curr word's + 1 and push it into queue. basically we are trying to find
// all 1 distance words from current word.

// if while pushing into queue the word is same as endword return its distance(saves time).after while loop ends meaning we couldn't find the
// sequence so return 0

class Solution
{
public:
	int ladderLength(string beginWord, string endWord, vector<string> &wordList)
	{

		unordered_map<string, bool> present;
		unordered_map<string, int> distance;
		distance[beginWord] = 1;
		for (auto word : wordList) present[word] = true;

		queue<string> q;

		q.push(beginWord);

		while (!q.empty())
		{

			auto word = q.front();
			q.pop();
			string temp = word;
			for (int i = 0; i < word.size(); i++)
			{

				for (char ch = 'a'; ch <= 'z'; ch++)
				{

					if (ch != word[i])
					{

						temp[i] = ch;
						if (present[temp] && distance[temp] == 0)
						{
							if (temp == endWord) return 1 + distance[word];
							q.push(temp);
							distance[temp] = 1 + distance[word];
						}

					}
				}
				temp[i] = word[i];
			}
		}

		return 0;
	}
};
// t.c. = O(26*l*N) + O(N) , l is the length of word
// s.c. = O(N)