// backtracking. in Ip address there are three dots which form 4 partitions of numbers and each number should be <=255 and should
// not contain leading zeroes like 0 is ok but 0012 or 00 or 012 is invalid.
// now, at each call, we will run a loop from j=1 to 3 because > 3 digits will be >255 as well. then we would have a st that is the
// starting position of the number so will try to extend the length by 1 to 3. for each j + st we will check is it within the bound
// of the original string, if the number formed is <=256 and doesn't contain leading zeroes then we will add this in the resultant
// string and if i is 3 that means 3 dots have already been assigned then we won't append dot else we do , increment the dot ,
// update the starting position st just after this number and call further. if i reaches 4 that means 4 partitions has been made
// but if the st is not equal to the size of string s that means all characters of string s are not considered in the ip address so
// we return else we insert this ip address.


class Solution
{
public:

	void rec(int i, int st, string res, vector<string> &ans, string &s)
	{


		if (i == 4 && st == s.size())
		{
			ans.push_back(res);
			return;
		}

		if (i >= 4) return;


		for (int j = 1; j < 4; j++)
		{
			if (st + j > s.size()) break;

			string t = s.substr(st, j);

			if (stoll(t) <= 255 && !(t[0] == '0' && t.size() > 1)) {
				rec(i + 1, st + j, res + t + (i == 3 ? "" : "."), ans, s);

			}
		}
	}

	vector<string> restoreIpAddresses(string s)
	{

		vector<string> ans;
		rec(0, 0, "", ans, s);

		return ans;
	}
};

// t.c. = O(4^4) => O(1)
// s.c. = O(N)