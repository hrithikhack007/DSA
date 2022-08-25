//so let's start with the brute force approach , for every element in nums1 first we will search it in nums2 and after that we will find the next
// greater element of it
// t.c. O(n*m) n is the size of nums1 and m is the size of nums2
// s.c. O(1)
//now let's try to optimize its time complexity to linear
//so first of all we will use an unordered map so that our search time of any element will become O(1), after this  we will find all the next
//greater element of nums2 array beforehand . we will use stack for this.
// so for the ith element, it will pop out elements out of the stack till it find some element which is greater than itself or stack becomes empty.
//if stack become empty then it indicates that there is no greater element in right of it so we will put -1 as it ans else top element and in last we
// will push the current element in the stack.
//after next greater array is ready we can traverse the nums1 array and for each of its element we will find the index of that in nums2 from mp
// and the next greater element of that index for nums2 will be stored in ng array.



class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {



        stack<int> st;
        int n = nums2.size();
        vector<int> nextGreater(n);
        unordered_map<int, int> mp;
        for (int i = n - 1; i >= 0; i--) {

            while (!(st.empty()) && st.top() < nums2[i]) st.pop();

            nextGreater[i] = !(st.empty()) ? st.top() : -1;
            st.push(nums2[i]);
            mp[nums2[i]] = i;

        }

        vector<int> ans;

        for (auto a : nums1) {
            ans.push_back(nextGreater[mp[a]]);
        }

        return ans;


    }
};

// t.c. = O(N+M)
// s.c. = O(N)