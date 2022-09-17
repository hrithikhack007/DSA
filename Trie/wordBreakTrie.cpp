// first create the struct of node, in that define the data members letters which is an array of node pointers of size 26 , a isLeaf boolean variable
// to check if any word ended at the particular node.

// three utility functions,
// newNode in which, curr node and char ch are parameters. it will create a new node and assign its reference to the character ch pointer in letters
// array of curr node and return it.

// In isThere function, we will return if the character ch of curr node is assigned any reference node or not.

// In get function, we will return the reference of the node assigned to character ch in curr node.

// In insert function, we will set curr to root. then iterate the word, for each char ch check if it is pointing to some node that means is it
// already initialized in the current node if it is then get the reference to which this ch is pointing to in the current node and move current
// to that reference node.
// else if it is not already there in the current node then simply create a new node and assign it to curr.
// after the traversal of word is complete,set curr->leaf to true that means a word is ending at this node.

// we have dp array where dp[i] indicates if we can partition the string from index i to n-1 such that each partition is present in dictionary.

// we will traverse the words in A and insert each word in trie ds.
// after this , call the rec. function by passing arguments idx = 0,A,dp and in each rec. call if idx == A.size() that means we have successfully
// partitioned the string so we return true, else if dp[idx]!=-1 that means it is already computed so we return dp[idx] else we set curr to root
// and traverse the string A from i = idx to A.size() - 1 and for each character we check if that character has a reference node or not if
// it is then we will move to that referenced node after this we check if it is a leaf node means some word ended here that is we found a
// dictionary word so in that case we will call on rec by passing idx = i+1 and if it returns true so we return true.
// else if it is not a leaf node then we continue
// else if the current character is not assigned any reference node that means there is no word present in the dictionary with the currently formed
// prefix so we return false.
// after traversing through the string we return false.
// before returning , we save the ans in dp[idx].





class Solution {
public:

    struct Node {

        Node* letters[26];
        bool isLeaf;


        Node() {

            for (int i = 0; i < 26; i++) letters[i] = NULL;
            isLeaf = false;
        }

    };

    Node *root;

    Node* newNode(Node *curr, char ch) {

        return curr->letters[ch - 'a'] = new Node();
    }

    bool isThere(Node *curr, char ch) {

        return curr->letters[ch - 'a'];
    }

    Node* get(Node *curr, char ch) {

        return curr->letters[ch - 'a'];
    }



    void insert(string &word) {

        Node *curr = root;

        for (auto ch : word) {

            if (isThere(curr, ch)) {

                curr = get(curr, ch);
            } else curr = newNode(curr, ch);
        }

        curr->isLeaf = true;
    }

    bool rec(int idx, string &A, int dp[]) {

        if (idx == A.size()) return true;

        if (dp[idx] != -1) return dp[idx];

        Node *curr = root;

        for (int i = idx; i < A.size(); i++) {

            if (isThere(curr, A[i])) {

                curr = get(curr, A[i]);
                if (curr->isLeaf) {

                    if (rec(i + 1, A, dp)) return dp[idx] = true;
                }

            } else return dp[idx] = false;

        }

        return dp[idx] = false;

    }


    int wordBreak(string A, vector<string> &B) {

        root = new Node();
        int n = A.size();
        int dp[n + 1];
        for (int i = 0; i < n; i++) dp[i] = -1;

        for (auto word : B) {

            insert(word);
        }


        return rec(0, A, dp);

    }
};

// t.c. = O(K*l + O(N^2))
// s.c. = O(K*l + O(N))

// K is the number of words in the dictionary and l is the average length of each word. N is the length of the string A.
