// it is similar to duplicate subtree in binary tree where we just have to check if duplicate binary tree exist or not here we
// just need to return all duplicate binary trees.
// entire approach is similar just we will use a map here which will store the frequency of serialization of subtrees if two binary
// subtrees with same serialization is present then the frequency of its serialization string serial will be >=2 but we just want one
// occurence of duplicate subtree in our ans so whenever frequency of serial becomes 2 that means we have found a duplicate binary tree
// sp we will push the root in our ans and we won't push it when it becomes 3,4,5 and so on because we have already considered its
// one occurence.
// rest of the part remains same as of check duplicate subtree in binary tree problem

string rec(Node *root, unordered_map<string, int> &f, vector<Node*> &ans) {

    if (root == NULL) {
        return "N";
    }

    string serial = to_string(root->data);
    serial += "L" + rec(root->left, f, ans);
    serial += "R" + rec(root->right, f, ans);

    f[serial]++;
    if (f[serial] == 2) {
        ans.push_back(root);
    }

    return serial;

}


vector<Node*> printAllDups(Node* root)
{
    vector<Node*> ans;

    unordered_map<string, int> f;

    rec(root, f, ans);

    return ans;



}

// t.c. = O(N^2)
// s.c. = O(N) + O(H)
