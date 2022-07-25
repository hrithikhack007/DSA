// first take the size of the string in n, declare a vector of int mapBrackets to map respective opening and closing brackets.
// take a stack. traverse the string from i = 1 to n-1 because 0th element will always be a integer. if str[i] == '(' push it into
// stack and if str[i]==')' then the topmost opening bracket is it matching opening bracket so in mapBrackets map the st.top opening bracket
// with ith closing bracket and pop the top opening bracket index.
// now call the buildTree function by passing st=-1,en = n,str and mapBrackets as arguments.
// st and en defines the range of current node within which it will have left and right child.
// in each func. call, first we have to calculate the data of the current node so it can have>1 digits so we will start from i=st+1 and
// till i<en and str[i]!='(' we will iterate and in each iteration we will just calculate the number by multiplying the num by 10 and
// adding current digit.
// loop ends when i reaches en or closing opening bracket. now we will create node with data as num and if i==en that means we haven't
// found the opening bracket for the current node so there is no left or right child for this node and simply return node.
// else if we have encountered a opening bracket at index i then the expression from i till mapBrackets[i] will contain the left child
// of current node where mapBrackets[i] is the closing index for ith opening bracket.
// so the opening bracket for right child will be just next to the closing of left i.e. mapbrackets[i]+1.
// if we have found opening bracket that means left child definitely exist so we will recursively call the buildtree on opening and closing
// of left child and assign the returned node's address to node->left.
// but finding the opening bracket doesn't gurantees that the node will have right child so we will first check if the opening of right
// is < n and if str[openingRight] is opening bracket then only we can say node has a right child so we will recursively call on the
// opening of right and mapbrackets[rightOpening] i.e. the closing index for the right Opening and assign its returned node address to
// node->right.


class Solution
{
public:

    Node* buildTree(int st, int en, string &str, vector<int> &mapBrackets) {



        int num = 0;
        int i = st + 1;
        for (; i < en && str[i] != '('; i++) {

            num = (num * 10 + (str[i] - '0'));

        }

        Node *node = new Node(num);

        if (i == en) {
            return node;
        }

        int openingRight = mapBrackets[i] + 1;

        node->left = buildTree(i, mapBrackets[i], str, mapBrackets);
        if (openingRight < str.size() && str[openingRight] == '(') {
            node->right = buildTree(openingRight, mapBrackets[openingRight], str, mapBrackets);
        }

        return node;




    }

    Node *treeFromString(string str)
    {

        int n = str.size();

        vector<int> mapBrackets(n);

        stack<int> st;

        for (int i = 1; i < n; i++) {

            if (str[i] == '(') {
                st.push(i);
            } else if (str[i] == ')') {
                mapBrackets[st.top()] = i;
                st.pop();
            }

        }

        return buildTree(-1, n, str, mapBrackets);

    }
};

// t.c. = O(N) + O(N) = O(2*N) = O(N)
// s.c. = O(N) + O(H)

// optimized version without using external stack.
// in this we will pass start variable initialized to -1 as an argument to the buildTree function and we will pass it by reference.
// now for every node it will be pointing to the opening bracket of that node except root node. so we have to do a start++ to reach
// integer from there we will calculate the data for this node and stop the while loop as soon as we have reached end of str or we have
// encountered opening or closing bracket.
// after this we will create a node with data that we have calculated.
// if start reaches the end of str or start is at the closing bracket that means there is no left child for the current node so we will
// simply return this node,also if left doesn't exist then right also doesn't exist because we are first creating left then right.
// else,if start is at the opening bracket then we definitely know that left child of node exist so we will recursively call the buildtree
// function and at that call our start will be at the opening bracket of left child and after returning it would have build the left subtree
// and will be pointing on the closing bracket of the left child for e.g. str = "100(25(30)(12) )(2(35))" then for node 100 after
//                                                                                              ^
// building its left subtree start will be at the closing bracket                               |
// so to check if right child of node exist or not we will simply check if start+1<str.size() and start+1 is an opening bracket then only
// we will call for right child and while calling right child we will increment start to reach the opening bracket of right child
// now after returning from the right child call our start would be pointing on the closing of right child but the current node might be
// the left child of its ancestor so we have to increment the start so we reach the closing of left w.r.t its ancestor also if right
// child didn't existed then the start would have pointing to the closing of the left but if we didn't increment start then the start would
// be one less to the closing of left w.r.t its ancestor. e.g. 1(2(3(5)(6)))(7(8)), say after completing left child of node 2 the start
// will be  at the closing of left of node's 2 left child so before returning we should increment start by 1 so it reaches closing of
// node's 1 left child i.e. its ancestor.



class Solution
{
public:

    Node* buildTree(int &start, string &str) {

        int num = 0;
        start++;

        while (start < str.size() && str[start] != '(' && str[start] != ')') {
            num = (num * 10 + (str[start++] - '0'));
        }


        Node *node = new Node(num);

        if (start == str.size() || str[start] == ')') {
            return node;
        }


        node->left = buildTree(start, str);
        if (start + 1 < str.size() && str[start + 1] == '(') {
            start++;
            node->right = buildTree(start, str);
        }
        start++;

        return node;




    }

    Node *treeFromString(string str)
    {

        int n = str.size();

        int start = -1;

        return buildTree(start, str);

    }
};


// t.c. = O(N)
// s.c. = O(H)