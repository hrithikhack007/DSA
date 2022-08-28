//we will keep a last pointer which will keep track of last visited node in the inorder traversal , initially it will be
//null and also set head to null. call rec. function by passing root,last and head as arguments, and in each rec. call
// if root is null then simply return, else recursively call on the left subtree and after returning from it , assign
// root->left to last because last was the prev node we had visited and this root will be the next node after the prev node
// in inorder traversal so that's why we are assigning root->left to last and if last is null that means this root will be
// the head of the dll because this is the leftmost node from the root or the first node in inorder traversal that's why last
// is currently null so if this is the case then simply assign this root to the head of dll. and if last is not null then
// set last->right to root and after this set root as last and call on the right subtree of root.
// aftet the rec. function is over and returned to main function then last will point to the last node in inorder traversal
// so set last->right to NULL and return head.


class Solution
{
public:

    void rec(Node *root, Node *&last, Node *&head) {

        if (root == NULL) {
            return;
        }

        rec(root->left, last, head);
        root->left = last;
        if (last) {
            last->right = root;
        } else head = root;
        last = root;
        rec(root->right, last, head);
    }

    Node * bToDLL(Node *root)
    {

        Node *last = NULL, *head = NULL;

        rec(root, last, head);

        last->right = NULL;

        return head;


    }
};

// t.c. = O(N)
// s.c. = O(H),stack space
