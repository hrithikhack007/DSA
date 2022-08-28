// so we will set idx to -1, declare an unordered map to store the indexes of inorder elements.
// then we will call buildTree function by passing st=0,en=n-1,pre,idx=-1,mp as arguments. then in each rec. call,
// EDGE CASE: if the range is invalid i.e. start > en then we will simply return NULL, else if the range is valid then we will
// increment idx by 1 i.e. there exist some valid node in prefix[idx] so we will first find the index of this node in inorder then we
// will create a new node with prefix[idx] and then we will call on st,inIdx-1 for building left subtree and inIdx+1,en to build the
// right subtree and setting node->left and node->right to the node address returned by the respective calls.
// then return node.


// intuition: we know that first node in the preorder is always the root node so we are finding the index of that node in inorder
// because we also know that in inorder traversal firt the subtree is visited then root then right subtree so if we find the index of the
// root then everything on its left will be the part of left subtree and everything on its right will be the part of right subtree.
// this will be true for every other subtree as well. so at the node, we can call on st,inIdx-1 to build the left subtree and
// inIndx+1,en to build the right subtree where inIdx is the index of the node in inorder traversal. Also when st == en that means it
// is a leaf node so simply create a new node and return it.
// IMP: when the range is valid then only increment the idx else we may miss some nodes in the tree.



class Solution {
public:

    Node* buildTree(int st, int en, int pre[], int &idx, unordered_map<int, int> &mp) {

        if (st > en) return NULL;

        idx++;

        if (st == en) {
            return new Node(pre[idx]);
        }

        int inIdx = mp[pre[idx]];

        Node *node = new Node(pre[idx]);

        node->left = buildTree(st, inIdx - 1, pre, idx, mp);
        node->right = buildTree(inIdx + 1, en, pre, idx, mp);
        return node;
    }

    Node* buildTree(int in[], int pre[], int n)
    {
        int idx = -1;

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[in[i]] = i;
        }

        return buildTree(0, n - 1, pre, idx, mp);

    }
};


// t.c. = O(N) + O(N) = O(2*N) = O(N)
// s.c. = O(N)(map) + O(H)(stack space till height of tree).
