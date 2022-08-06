// res[0] represent maximum size subset if I don't considet that node and res[1] represents the maximum size
// subset I can get if I consider that node.
// so for a particular node we have two choices we can either take it in the subset or not, so if we take it
// then its children cannot be present in the subset so we will say res[0] = Left[0] + Right[0] + 1 i.e. the
// Left[0]=> maximum size subset I can get if don't consider the left child and Right[0] is the maximum size
// subset I can get if I don't consider the right child and as I am consideting the node itself so +1 in that.
// another choice is to not consider the current node so then we can choose the left child or not and same for right child.
// so we will choose max(left[0],left[1]) + max(right[0],right[1]) because if we don't consider the node then we have the liberty to pick
// the left child or skip it and also pick the right child or skip it so we will  make that choice which will give us maximum size.



vector<int> rec(Node *root) {

    if (root == NULL) {
        return {0, 0};
    }

    auto Left = rec(root->left);
    auto Right = rec(root->right);

    vector<int> res = {0, 0};

    res[1] = Left[0] + Right[0] + 1 ;
    res[0] = max(Left[0], Left[1]) + max(Right[0], Right[1]);

    return res;

}


int LISS(Node *root)
{


    auto res = rec(root);

    return max(res[0], res[1]);


}


// t.c. = O(N)
// s.c. = O(H)