// set leafDepth to -1, ok to true. call rec. by passing root,leafDepth,depth=0,ok as arguments, in each func. call, if root
// is null then return, else if root is a leaf node then if leafdepth is -1 then it is the first leaf node so update leafDepth
// to depth else if it is not the first leaf then some other leaf was already visited and we have its leafDepth so if it is
// not equal to current depth then two leafs will be at different level so we will make ok = false.



class Solution {
public:

  void rec(Node *root, int &leafDepth, int depth, bool &ok) {

    if (root == NULL) {
      return;
    }

    if (root->left == NULL && root->right == NULL) {
      if (leafDepth == -1) {
        leafDepth = depth;
      }

      ok = (ok && (leafDepth == depth));
      return;
    }

    rec(root->left, leafDepth, depth + 1, ok);
    rec(root->right, leafDepth, depth + 1, ok);
  }

  /*You are required to complete this method*/
  bool check(Node *root)
  {
    //Your code here

    int leafDepth = -1;
    bool ok = true;

    rec(root, leafDepth, 0, ok);

    return ok;

  }
};

// t.c. = O(N)
// s.c. = O(H)


// iterative, level order

// declare leafDepth to -1, depth to 0.
// declare a queue of pointers, push root into queue.
// while q is not empty, in each iteration take the size of the queue i.e. the number of nodes in the current level.
// then traverse the current level, and in each iteration take the front node of the queue in node and pop it out of queue.
// check if it is a leaf node, if it is then check if leafdepth is -1 that means it is the first leaf node so update leafdepth
// to depth and if leafdepth != depth for any leaf node that means leafs are not at same level so return false.
// after this, if node->left  exist then push it into queue also if node->right exist then push it into queue.
// after the completion of current level, increment the depth by 1.
// in last return true after q becomes empty.

class Solution {
public:
  /*You are required to complete this method*/
  bool check(Node *root)
  {

    int leafDepth = -1;

    int depth = 0;


    queue<Node*> q;

    q.push(root);

    while (!(q.empty())) {


      int sz = q.size();

      for (int i = 0; i < sz; i++) {

        auto node = q.front();
        q.pop();

        if (node->left == NULL && node->right == NULL) {
          if (leafDepth == -1) {
            leafDepth = depth;
          }

          if (leafDepth != depth) {
            return false;
          }
        }

        if (node->left) q.push(node->left);
        if (node->right)q.push(node->right);
      }

      depth++;


    }

    return true;


  }
};

// t.c. = O(N)
// s.c. = O(N/2) = O(N)