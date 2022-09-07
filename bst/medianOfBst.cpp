// first count the number of elements in bst i.e. n.
// then take two mids mid1 = ceil(n/2) and mid2 = mid1+1.
// take t1=-1,t2=-1.
// now do inorder traversal of bst and in each call if root is null then return else call on root->left subtree then decrement mid1 by 1
// and if mid1==0 then we are at the mid1'th term of the inorder traversal so set t1 to root->data , similarly decrement mid2 by 1 and if mid2
// becomes 0 then set t2 to root->data.
// then after this call on right subtree.
// after doing the inorder traversal, if n is odd then simply return t1 else return (t1+t2)/2.0

int count(Node* root) {

    if (root == NULL) return 0;

    return count(root->left) + count(root->right) + 1;
}

void inorder(Node *root, int &mid1, int &mid2, int &t1, int &t2) {

    if (root == NULL) return;

    inorder(root->left, mid1, mid2, t1, t2);
    mid1--;
    if (mid1 == 0) t1 = root->data;
    mid2--;
    if (mid2 == 0) t2 = root->data;
    inorder(root->right, mid1, mid2, t1, t2);
}

float findMedian(struct Node *root)
{

    int n = count(root);

    int mid1 = ceil(n / 2.0);
    int mid2 = mid1 + 1;

    if (n == 1) return (float)root->data;

    int t1 = -1, t2 = -1;

    inorder(root, mid1, mid2, t1, t2);

    if ((n & 1)) return t1;
    else return (t1 + t2) / 2.0;



}

// t.c. = O(N) + O(N) = O(N)
// s.c. = O(H)

// using morris traversal.
// first , we will count the number of nodes in bst using morris travesal.
// then we will take two mids, mid1 = ceil(n/2.0) and mid2 = mid1+1 and  we will again do the morris inorder traversal to find the mid1'th term t1
// and mid2'th term t2. and if n is odd we will return t1 else (t1+t2)/2.0 .
// because median is the middle of sorted sequence and as we are doing the inorder traversal of the bst we will be traversing over increasing
// sequence so at each node in the traversal we will decrement mid1 and mid2 by 1 and when mid1 becomes 0 means we are at the mid1'th element
// so set t1 to curr->data and similarly if mid2 becomes 0 means we are at the mid2'th element so set t2 to curr->data.


int count(Node* root) {

    Node *curr = root;
    int n = 0;
    while (curr) {
        if (curr->left) {
            Node *pred = curr->left;

            while (pred->right != NULL && pred->right != curr) pred = pred->right;

            if (pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
                n++;
            } else {
                pred->right = NULL;
                curr = curr->right;
            }
        } else {
            n++;
            curr = curr->right;
        }
    }

    return n;

}

void inorder(Node *root, int &mid1, int &mid2, int &t1, int &t2) {

    Node *curr = root;

    while (curr) {

        if (curr->left) {
            Node *pred = curr->left;

            while (pred->right != NULL && pred->right != curr) pred = pred->right;

            if (pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;

            } else {
                mid1--, mid2--;
                if (mid1 == 0) t1 = curr->data;
                if (mid2 == 0) t2 = curr->data;
                pred->right = NULL;
                curr = curr->right;
            }
        } else {
            mid1--, mid2--;
            if (mid1 == 0) t1 = curr->data;
            if (mid2 == 0) t2 = curr->data;
            curr = curr->right;
        }
    }
}

float findMedian(struct Node *root)
{

    int n = count(root);

    int mid1 = ceil(n / 2.0);
    int mid2 = mid1 + 1;

    if (n == 1) return (float)root->data;

    int t1 = -1, t2 = -1;


    inorder(root, mid1, mid2, t1, t2);

    if ((n & 1)) return t1;
    else return (t1 + t2) / 2.0;


}

// t.c. = O(N)
// s.c. = O(1)

