// I will call the rec. function by passing root as an argument. then in each rec. call if root is null then return {0,0}.
// else, take the left result by calling left subtree and right result from right subtree. result[0] will contain the maximum
// sum i can have in a subtree of that node if i don't choose that node in the sum and result[1] will contain the maximum
// sum i can have in a subtree of that node if i consider that node in the sum.

// so if i don't consider the current root in the sum then I have 4 choices,:
// I can choose the root of left subtree and choose root of right subtree i.e. left[1] + right[1]
// I can choose the root of left subtree and not choose root of right subtree i.e. left[1] + right[0]
// I not choose the root of left subtree and choose the root of right subtree  i.e. left[0] + right[1]
// I not choose the root of left subtree and not choose the root of right subtree i.e. left[0] + right[0]
// for the above 4 choices whichever give the maximum i will store it in res[0] for current root.
// or I can choose the current root then i have only one choice: that is don't condier the root of left as well as right
// subtree i.e. current + left[0] + right[0]. and store it in res[1].
// return res;
// after rec is completely over, our ans will be the max of (res[0],res[1]). i.e. the maximum sum we can get if i don't choose
// root node or i choose root node.




class Solution {
public:

  vector<int> rec(Node *root) {

    if (root == NULL) {
      return {0, 0};
    }

    vector<int> Left = rec(root->left);
    vector<int> Right = rec(root->right);

    int current = root->data;
    vector<int> res(2, 0);

    //   I am not taking current node;

    res[0] = max({(Left[1] + Right[1]), (Left[1] + Right[0]), (Left[0] + Right[1]), (Left[0] + Right[0])});

    // taking current node
    res[1] = current + Left[0] + Right[0];

    return res;


  }


  int getMaxSum(Node *root)
  {

    auto res = rec(root);

    return max(res[0], res[1]);


  }
};

// t.c. = O(N)
// s.c. = O(H)
