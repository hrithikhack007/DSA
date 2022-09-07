// do a preorder traversal of first tree and store the frequency of elements in map.
// then do a preorder traversal of second tree and for each node increment the count by mp[x-root->data].


class Solution
{
public:

    void rec1(Node *root, unordered_map<int, int> &mp) {

        if (root == NULL) return;

        mp[root->data]++;
        rec1(root->left, mp);
        rec1(root->right, mp);
    }

    void rec2(Node *root, unordered_map<int, int> &mp, int &count, int x) {

        if (root == NULL) return;

        count += mp[x - root->data];
        rec2(root->left, mp, count, x);
        rec2(root->right, mp, count, x);
    }

    int countPairs(Node* root1, Node* root2, int x)
    {
        unordered_map<int, int> mp;

        rec1(root1, mp);
        int count = 0;
        rec2(root2, mp, count, x);
        return count;

    }
};

// t.c. = O(N) + O(N) = O(N)
// s.c. = O(H) + O(N) = O(N)


// using two pointer technique.
// set curr1 to root1 and curr2 to root2.
// now move curr1 to the smallest value node in tree 1 and i.e. keep moving left from curr1 and before moving push curr1 to st1, do this until
// curr1 is not null.
// similarly, move curr2 to the largest value node in tree 2 , i.e. keep moving right from curr2 and before moving push curr2 to st2, do this
// until curr2 is not null.
// set count to 0.
// now, while st1 and st2 are not empty, in each iteration, take sum = st1.top() + st2.top();
// now if sum is equals to x then increment count by 1 and move to the next smaller node in tree 1 and move to the previous larger node in the
// tree 2, else if sum < x that means if we try to move to previous larger then sum is going to decrease more so we will move to the next smaller
// in tree 1 , else if sum > x then if we try to move to the next smaller then the sum is going to increase more so we will try to move to the
// previous larger.

// in moveRight function, pop out the top node and assign it to node.
// set curr to node->right, now while curr is not null push curr in st and move curr to curr->left.

// in moveLeft function, pop out the top node and assign it to node.
// set curr to node->left, now while curr is not null push curr in st and move curr to curr->right.


class Solution
{
public:

    void moveRight(stack<Node*> &st) {

        auto node = st.top();
        st.pop();

        Node *curr = node->right;
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }

    }

    void moveLeft(stack<Node*> &st) {
        auto node = st.top();
        st.pop();

        Node *curr = node->left;
        while (curr) {
            st.push(curr);
            curr = curr->right;
        }
    }

    int countPairs(Node* root1, Node* root2, int x)
    {


        stack<Node*> st1, st2;

        Node *curr1 = root1, *curr2 = root2;

        while (curr1) {
            st1.push(curr1);
            curr1 = curr1->left;

        }


        while (curr2) {
            st2.push(curr2);
            curr2 = curr2->right;
        }



        int count = 0;

        while (!st1.empty() && !st2.empty()) {

            int sum = st1.top()->data + st2.top()->data;
            if (sum == x) {
                count++;
                moveRight(st1);
                moveLeft(st2);
            } else if (sum < x) {
                moveRight(st1);
            } else moveLeft(st2);

        }

        return count;


    }
};

// t.c. = O(N+M)
// s.c. = O(H1 + H2)