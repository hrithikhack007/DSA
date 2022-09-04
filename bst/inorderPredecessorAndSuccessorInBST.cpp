// inorder predecessor of the key means node which is having value just smaller than key and inorder successor means node which is having
// value just greater than the key.
// so, we will set both pre and suc to NULL, then we will set possiblePred and possibleSuc to root.

// while possiblePred is not null then in each iteration check if possiblePred->key >= key that means it cannot be the predecessor and also all
// the nodes right of it so we move possiblePred to left else if it is smaller then it might be the predeccesor so move to right as we want to
// find the closest node which is < key.

//while possibleSuc is not null then in each iteration check if possibleSuc->key <= key that means it cannot be the successor and also all the
// nodes left of it so move possibleSuc to right else if it is greater then it might be the successor so update suc to successor and as we want
// closest node having value > than key we will move possibleSuc to left.


void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

  pre = suc = NULL;

  Node *possiblePred = root, *possibleSuc = root;

  while (possiblePred) {

    if (possiblePred->key >= key) possiblePred = possiblePred->left;
    else {
      pre = possiblePred;
      possiblePred = possiblePred->right;
    }
  }

  while (possibleSuc) {

    if (possibleSuc->key <= key) possibleSuc = possibleSuc->right;
    else {
      suc = possibleSuc;
      possibleSuc = possibleSuc->left;
    }
  }

}

// t.c. = O(H) + O(H) = O(H)
// s.c. = O(1)