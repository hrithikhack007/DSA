// we will store the path from root to node A and path from root to node B in pathA and pathB vectors respectively.
// in rec. function, if root is null then we will simply return false, else if root is equal to a then we have found the target node so
// push it into path vector and return true signifying that we have found the target node. else we will call on the left subtree and right
// subtree and if either of them returns true that means target node is present within current node's subtree so this node is definitely
// going to be included in the path from root to target node so we will push this root in path vector and return true else return false.

// now the path is stored from bottom to top i.e. in reverse order so we will also start comparing nodes from last index in pathA and pathB
// as long as i and j are >=0 and pathA[i] == pathB[j] we will decrement i and j by 1 and at the moment we found a mismatch node or i or j
// becomes < 0 then the path for node a and node b is diverged and the previous matched node in the path was there lca so the remaining nodes
// from the mismatch index for both path we will add them and also add a 1 for the lca that will give us the number of nodes between node a
// and b so we will return distance - 1 i.e. number of edges between node a and b.



class Solution {
public:

    bool rec(Node *root, vector<int> &pathA, int a) {

        if (root == NULL) {
            return false;
        }

        if (root->data == a) {
            pathA.push_back(root->data);
            return true;
        }

        if (rec(root->left, pathA, a) || rec(root->right, pathA, a)) {
            pathA.push_back(root->data);
            return true;
        }

        return false;

    }

    int findDist(Node* root, int a, int b) {

        vector<int> pathA , pathB;


        rec(root, pathA, a);
        rec(root, pathB, b);

        int i = pathA.size() - 1, j = pathB.size() - 1;

        while (i >= 0 && j >= 0 && pathA[i] == pathB[j]) {
            i--, j--;
        }

        int distance = (i + 1) + (j + 1) + 1;

        return distance - 1;


    }
};

// t.c. = O(N) + O(N) + O(N) = O(3*N) = O(N)
// s.c. = O(N) + O(H)(stack space) = O(N)

// Using lca.

// first we will find the lca between nodes a and b using same algorithms as in lca of binary tree problem.
// then we will calculate distance from lca to a target node in lca->left subtree and lca->right subtree and add their distance which
// will give us the distance from node a and b because as we have lca we know node a and b will lie under its subtree only so we node a and
// b can lie in two different subtrees or they can lie in the same subtree if one of the target node itself is lca.
// so in the dist. function, if the root is null we return 0, else if root is some target node then we return 1 else we call on left subtree
// and right subtree then we check if left is not 0 then target node is present in left subtree so we will return left(height from root->left
//  to target node) + 1 else if right is not 0 then target node is present in right subtree so we return right + 1 else if target node is
// node is not present in either of the subtree so we return 0. this function will give us the distance from lca to a target node.
// after calling dist. function on lca->left and lca->right we will add them and it will be our ans.


class Solution {
public:

    Node* rec(Node *root, int a, int b) {

        if (root == NULL) return NULL;

        if (root->data == a || root->data == b) {
            return root;
        }

        auto Left = rec(root->left, a, b);
        auto Right = rec(root->right, a, b);

        if (Left && Right) {
            return root;
        } else if (Left) return Left;
        else return Right;
    }

    int dist(Node *root, int a, int b) {

        if (root == NULL) return 0;

        if (root->data == a || root->data == b) {
            return 1;
        }


        auto Left = dist(root->left, a, b);
        auto Right = dist(root->right, a, b);

        if (Left) {
            return Left + 1;
        } else if (Right) {
            return Right + 1;
        } else return 0;
    }

    int findDist(Node* root, int a, int b) {


        auto lca = rec(root, a, b);

        auto Left = dist(lca->left, a, b);
        auto Right = dist(lca->right, a, b);

        return Left + Right;

    }
};

// t.c. = O(N) + O(N) = O(2*N)
// s.c. = O(H)
