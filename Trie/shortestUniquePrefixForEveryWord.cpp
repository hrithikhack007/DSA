// create a struct Node in which declare data members letters array of type Node pointer of size 26 and a count variable.
// a constructor which will initialize the node object, by setting all 26 pointers to NUll and count to 0.

// three utility functions,
// newNode in which, curr node and char ch are parameters. it will create a new node and assign its reference to the character ch pointer in letters
// array of curr node and return it.

// In isThere function, we will return if the character ch of curr node is assigned any reference node or not.

// In get function, we will return the reference of the node assigned to character ch in curr node.

// Insert function, In this we will set the curr to root and then traverse the word , and for each character ch, we will check if this node is
// already assigned to the reference node if it is then we will simply move to that referencece node else we will first create it then go to the
// that node. now when we reach a new node we will increment its count by 1 indicating that a word has visited this node.

// so in the main function, we will traverse each word in the array and insert them in out trie data structure.
// now after this there is a shortestPrefix, set curr to root,string res = "".
// traverse the word and for each character ch, first move to its reference node and add it to the res and then check if the count in the curr
// node is 1 if it is that means only this word has reached till this node so we can uniquely represent it with the res prefix so we break and
// return res else we continue.




class Solution
{
public:

    struct Node {

        Node* letters[26];
        int count;

        Node() {

            for (int i = 0; i < 26; i++) letters[i] = NULL;
            count = 0;
        }

    };

    Node* newNode(Node *curr, char ch) {

        return curr->letters[ch - 'a'] = new Node();
    }

    bool isThere(Node *curr, char ch) {

        return curr->letters[ch - 'a'];
    }

    Node* get(Node *curr, char ch) {

        return curr->letters[ch - 'a'];
    }

    void insert(string word, Node *root) {

        Node *curr = root;

        for (auto ch : word) {

            if (isThere(curr, ch)) {

                curr = get(curr, ch);
            } else {
                curr = newNode(curr, ch);
            }

            curr->count++;
        }



    }

    string shortestPrefix(string &word, Node *root) {

        Node *curr = root;
        string res = "";

        for (auto ch : word) {
            curr = get(curr, ch);
            res.push_back(ch);
            if (curr->count == 1) break;
        }

        return res;
    }

    vector<string> findPrefixes(string arr[], int n)
    {

        Node *root = new Node();

        for (int i = 0; i < n; i++) {

            insert(arr[i], root);

        }

        vector<string> ans;

        for (int i = 0; i < n; i++) {
            ans.push_back(shortestPrefix(arr[i], root));

        }

        return ans;


    }

};


// t.c. = O(N*l)
// s.c. = O(N*l)

// where l is the average length of words and N is the total number of words.
