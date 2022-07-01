// refer checkifstringsrotaionofother. here its just optimized in space by calculating powers on the go.

class Solution
{
public:
	vector <int> search(string pat, string txt)
	{

		vector<int> ans;

		long prime = 31, power = 1, hash = 0, mod = 1e9 + 7;



		for (int i = 0; i < pat.size(); i++) {

			hash = (hash + ((pat[i] - 'a' + 1) * power) % mod) % mod;

			power = (power * prime) % mod;
		}

		long currHash = 0;
		long lpower = 1, rpower = 1;


		for (int l = 0, r = 0; r < txt.size(); r++) {

			currHash = (currHash + ((txt[r] - 'a' + 1) * rpower) % mod) % mod;

			if (r - l + 1 == pat.size()) {
				if ((hash * lpower) % mod == currHash) {
					ans.push_back(l + 1);
				}

				l++;
				currHash = (currHash - (((txt[l - 1] - 'a' + 1) * lpower) % mod) + mod) % mod;

				lpower = (lpower * prime) % mod;
			}

			rpower = (rpower * prime) % mod;

		}

		if (ans.size() == 0) {
			ans.push_back(-1);
		}

		return ans;

	}

};


// t.c. = O(N+M)
// s.c. = O(1)
