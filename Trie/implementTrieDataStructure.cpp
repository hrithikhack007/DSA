// create a struct node which will contain data members letter which is a vector of node pointers, a boolean variable leaf which will indicate
// if some word is ending at this node or not.
// a constructor, which will initialize the node, we resize the letters vector to 26 as we will have only lowercase english alphabets.
// then we will point all this 26 node pointers to NULL, and set leaf to false.

// in the trie constructor, we will initialize our root node.
// we will use 3 utility functions,
// newNode which will take current node and a character and create a new node ans assign its reference to the
// character ch pointer in that current node's letter array.
// isthere function which will tell if the character in the current node is assigned a node referece or not.
// get function, which will return the reference the character ch is storing of current node.

// In insert function, we will set curr to root. then iterate the word, for each char ch check if it is pointing to some node that means is it
// already initialized in the current node if it is then get the reference to which this ch is pointing to in the current node and move current
// to that reference node.
// else if it is not already there in the current node then simply create a new node and assign it to curr.
// after the traversal of word is complete,set curr->leaf to true that means a word is ending at this node.
// t.c. = O(N) where N is the length of word.
// s.c. = O(N)

// In search function, set curr to root,traverse each character of word,and if any character don't have any node assign to it that means the
// word doesn't exist so return false else move to the referenced node
// after traversing the word, check if the current node is the leaf or not if it is that means the word exist else the word exist only as a part of
// the prefix so return false.
// t.c. = O(N) where N is the length of the word.
// s.c. = O(1)

// startsWith function, set curr to root. traverse each char ch of word and if exist so move to its referenced node else return false,
// after traversal is over then return true. because we have completed traverse the word and there is some words which are starting with the
// given word.
// t.c. = O(N) where N is the length of the word/prefix
// s.c. = O(1)


class Trie {
public:

    struct Node {

        vector<Node*> letters;
        bool leaf;

        Node() {
            letters.resize(26);
            for (int i = 0; i < 26; i++) letters[i] = NULL;
            leaf = false;
        }

    };


    Node *root;

    Trie() {

        root = new Node();

    }

    Node* newNode(Node *curr, char ch) {

        return curr->letters[ch - 'a'] = new Node();
    }

    bool isThere(Node *curr, char ch) {

        return curr->letters[ch - 'a'];
    }

    Node *get(Node *curr, char ch) {

        return curr->letters[ch - 'a'];
    }

    void insert(string word) {

        Node *curr = root;

        for (auto ch : word) {

            if (isThere(curr, ch)) {
                curr = get(curr, ch);
            } else {
                curr = newNode(curr, ch);
            }

        }

        curr->leaf = true;


    }

    bool search(string word) {

        Node *curr = root;

        for (auto ch : word) {

            if (isThere(curr, ch)) {
                curr = get(curr, ch);
            } else return false;

        }

        return curr->leaf;

    }

    bool startsWith(string prefix) {

        Node *curr = root;

        for (auto ch : prefix) {

            if (isThere(curr, ch)) {
                curr = get(curr, ch);
            } else return false;

        }


        return true;



    }
};
