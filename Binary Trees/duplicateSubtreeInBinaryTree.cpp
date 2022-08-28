// Brute force.
// set ok to false, then call rec. function by passing root,ok and mainroot=root as arguments. now in each rec. call, root is
// null or root is leaf then return. else , call exist function by passing root and mainRoot as arguments, if it returns true
// then update ok to true and return. basicallt exist function will tell us if there exist any subtree which matches with the
// current root's subtree.
// else if it returns false then call on root->left subtree if ok is still false then call on root->right subtree.

// In the exist function, if root is null or root is curr or root is leaf node then return false.
// else, we will choose the root and try to match root->subtree with curr->subtree so we will call on match by passing root
// and curr as arguments if it returns true then curr's subtree matches with some subtree so we return true else we will
// check root->left subtree and root->right subtree if either one of them return true we return true else false.

// In the match function, we will compare curr and root subtree one by one , let's call root as dup and curr as og.
// so if dup is not null and og is also not null then compare their values if they are not equal then simply return false
// else call on dup->left,og->left and dup->right,og->right we want both of the call to return true then only we can say that
// dup subtree is equal to og subtree, else if one of them are null and other is not null them return false, else if  both
// of them are null then return true.


// intuition: for each node in the tree, we are fixing that node's subtree and will check all other node's subtree if it
// matches with the current node's subtree. so in the rec. function we are fixing current node then in existing function
// we are fixing some duplicate node to match with current node's subtree and in match function we are matching nodes of
// curr as og and root in exist as dup one by one. if curr subtree equals root subtree in exist then all dup and og structure
// as well as values will match.



class Solution {
public:

  bool match(Node *dup, Node *og) {

    if (dup != NULL && og != NULL) {
      if (dup->data != og->data) return false;
      return match(dup->left, og->left) && match(dup->right, og->right);
    } else if (dup || og) return false;
    else return true;


  }

  bool exist(Node *curr, Node *root) {

    if (root == NULL || root == curr) return false;

    if (root->left == NULL && root->right == NULL) return false;



    if (match(root, curr)) {
      return true;
    }

    return exist(curr, root->left) || exist(curr, root->right);



  }

  void rec(Node *root, int &ok, Node *mainRoot) {

    if (root == NULL) {
      return;
    }

    if (root->left == NULL && root->right == NULL) {
      return;
    }


    if (exist(root, mainRoot)) {
      ok = 1;
      return;
    }

    rec(root->left, ok, mainRoot);
    if (ok) return;
    rec(root->right, ok, mainRoot);


  }

  int dupSub(Node *root) {

    int ok = 0;

    rec(root, ok, root);

    return ok;

  }
};


// O(N*N*N) = O(N^3)
// s.c. = O(3*H) = O(H)

// optimizing using hashing + serialization.
// declare an unordered map of ll,ll where key is hash value and value in number of subtrees which has this hash value.
// we will first precalculate hash values of all the subtrees by calling precalculateHash function by passing root, mp
// as arguments.
// in  each precalculateHash func. call, if the root is null or root is leaf then return.
// else, serialize the current root's subtree by calling serialization function by passing root and serial as arguments
// serial is a string which will store serialization of root's subtree.

// In the serialization,if the root is null then simply push 'N' in the serial and return, else convert root->data in string
// and append it to serial then append 'L' to it and call on left subtree after that append 'R' to it and call on its right
// subtree.

// after serialization function is over, serial will have the serialized form of root subtree. so we will use this serial to
// calculate a unique hash value of the root's subtree.
// declare hash = 0, power = 1.
// we had globally defined a prime number > ascii value of characters in serial i.e. p = 313 and mod equals to a prime number
// so while calculating the hash doesn't overflow.

// now , iterate from i=0 to serial.size() - 1, in each iteration first multiply the power with current character - '0'
// then add it to hash also keep taking mod to avoid overflow at any instance of calculation.
// after this, multiply power with p to move to next power of p.
// when the loop is over , hash will store the unique value for the root's subtree in long long dataype.
// so we will increment the occurence of this hash in our map.
// then we will call on root->left subtree and root->right subtree.

// after precalculatehash is over, we will iterate the map and check if occurence of any hash value is > 1 that means more
// than two subtree has same hashvalue that means there are atleast two similar subtrees in the tree so we return true.
// if no duplicate subtrees then return false.




class Solution {
public:

#define ll long long
  ll mod = (ll)(1e9 + 7);
  ll p = 313;

  void serialization(Node *root, string &serial) {

    if (root == NULL) {
      serial.push_back('N');
      return;
    }

    serial += (to_string(root->data));
    serial += "L";
    serialization(root->left, serial);
    serial += "R";
    serialization(root->right, serial);
  }

  void precalculateHash(Node *root, unordered_map<ll, ll> &mp) {

    if (root == NULL || (root->left == NULL && root->right == NULL)) return;
    string serial = "";
    serialization(root, serial);

    ll hash = 0, power = 1;

    for (ll i = 0; i < serial.size(); i++) {

      hash = ((hash % mod) + (((power % mod) * ((serial[i] - '0') % mod)) % mod)) % mod;
      power = ((power % mod) * (p % mod)) % mod;
    }

    mp[hash]++;
    precalculateHash(root->left, mp);
    precalculateHash(root->right, mp);

  }



  int dupSub(Node *root) {

    unordered_map<ll, ll> mp;

    precalculateHash(root, mp);


    for (auto a : mp) {
      if (a.second > 1) return true;
    }

    return false;


  }
};

// t.c. = O(N^2)
// s.c. = O(N) + O(H)

// using unordered set for hashing.
// declare an unordered set of string st.
// call rec. function by passing root and st as arguments.
// in each rec. call, if root is null or leaf node then return false.
// else, declare a string serial.
// call serialization to serialize the current root's subtree by passing root and serial as arguments.

// In the serialization,if the root is null then simply push 'N' in the serial and return, else convert root->data in string
// and append it to serial then append 'L' to it and call on left subtree after that append 'R' to it and call on its right
// subtree.

// after serialization function is over, serial will have the serialized form of root subtree.

// if the serial string is already present in the set that means there is some subtree equivalent to current root's subtree
// so we return true else we will insert this serial in st and call on left subtree and right subtree and if either of them
// return true then there is duplicate subtree in the tree.



class Solution {
public:


  void serialization(Node *root, string &serial) {

    if (root == NULL) {
      serial.push_back('N');
      return;
    }

    serial += (to_string(root->data));
    serial += "L";
    serialization(root->left, serial);
    serial += "R";
    serialization(root->right, serial);
  }

  bool rec(Node *root, unordered_set<string> &st) {

    if (root == NULL || (root->left == NULL && root->right == NULL)) return false;
    string serial = "";
    serialization(root, serial);


    if (st.count(serial)) return true;
    st.insert(serial);

    return rec(root->left, st) || rec(root->right, st);

  }



  int dupSub(Node *root) {

    unordered_set<string> st;

    return rec(root, st);

  }
};

// t.c. = O(N^2)
// s.c. = O(N) + O(H)

// clean code.
// declare an unordered set of string st.
// set ok to false. call rec. function by passing root,st and ok as arguments. in each rec. call, if root is null then simply
// return string "N", else declare a string serial i.e. serialization of root's subtree.
// convert root->data to string and append it to serial, after this append "L" to serial and call on left subtree and append
// the string returnd by left subtree call, similarly before calling right subtree, append "R" to serial and then append the
// string returned by right subtree call.
// every node is returning its own serialized string and we are just appending it so we again don't have to calculate.

// after this, if root is not a lead node and serial is already present in set that means there is a subtree which has same
// serialization as current root's subtree so there is duplicate subtree so set ok to true. after this,insert serial in st
// and return serial.

class Solution {
public:


  string rec(Node *root, unordered_set<string> &st, bool &ok) {

    if (root == NULL) {
      return "N";
    }
    string serial = "";


    serial += (to_string(root->data));
    serial += ("L" + rec(root->left, st, ok));
    if (ok) return "";
    serial += ("R" + rec(root->right, st, ok));

    if (!(root->left == NULL && root->right == NULL) && st.count(serial)) {
      ok = true;
    }
    st.insert(serial);
    return serial;

  }



  int dupSub(Node *root) {

    unordered_set<string> st;
    bool ok = false;

    rec(root, st, ok);
    return ok;


  }
};

// t.c. = O(N^2)
// s.c. = O(N) + O(H)
