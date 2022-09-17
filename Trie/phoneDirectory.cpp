// create a struct of node and define data members letters which is a map of char,Node pointer.
// a vector to store indexes of the words that has been visited the node so we can print them.

// three utility functions,
// newNode in which, curr node and char ch are parameters. it will create a new node and assign its reference to the character ch pointer in letters
// array of curr node and return it.

// In isThere function, we will return if the character ch of curr node is assigned any reference node or not.

// In get function, we will return the reference of the node assigned to character ch in curr node.

// In insert function, we will set curr to root. then iterate the word, for each char ch check if it is pointing to some node that means is it
// already initialized in the current node if it is then get the reference to which this ch is pointing to in the current node and move current
// to that reference node.
// else if it is not already there in the current node then simply create a new node and assign it to curr.
// after this we will push the index of this word in the indexes vector of current.

// in the main function, sort the contact as we want the output in increasing order, also as the question says to print the distinct contact
// numbers for each prefix we have to skip duplicates(edge case) while inserting.
// set sz to size of string s.
// after inserting all words in the trie, we will traverse the string s and for each character ch we will check if that character is present in
// root node if it is then we will move to its reference node and we will traverse the indexes array of that node and push the respective contacts
// in the list vector.also decrement sz by 1 as we have processed one character.
// else we will simply break as there is no word present in the contact which matches with the prefix of s so it won't match with further prefix of
// s as well. remember to break here , don't just push "0" in the list and push it into ans and continue as  the next character of s might be present
// in the root node but the prefix then won't be contiguous so as soon as we found a mismatch we will break(edge case).
// after this, if sz > 0 then push list of "0" in ans decrement sz by 1 till it becomes 0.


class Solution {
public:

    struct Node {

        unordered_map<char, Node*> letters;
        vector<int> indexes;

    };

    Node *root;

    Node* newNode(Node *curr, char ch) {

        return curr->letters[ch] = new Node();
    }

    bool isThere(Node *curr, char ch) {

        return curr->letters[ch];
    }

    Node* get(Node *curr, char ch) {

        return curr->letters[ch];
    }



    void insert(string &word, int idx) {

        Node *curr = root;

        for (auto ch : word) {

            if (isThere(curr, ch)) {

                curr = get(curr, ch);
            } else curr = newNode(curr, ch);

            curr->indexes.push_back(idx);
        }


    }


    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {

        root = new Node();

        sort(contact, contact + n);

        for (int i = 0; i < n; i++) {
            insert(contact[i], i);
            int j = i;
            while (j + 1 < n && contact[j + 1] == contact[j]) j++;
            i = j;
        }

        vector<vector<string>> ans;

        int sz = s.size();

        for (auto ch : s) {

            vector<string> list;

            if (isThere(root, ch)) {

                sz--;
                root = get(root, ch);
                for (auto index : root->indexes) {
                    list.push_back(contact[index]);
                }

            } else {
                break;
            }

            ans.push_back(list);

        }

        while (sz--) {
            ans.push_back({"0"});
        }

        return ans;

    }
};


// t.c. = O(NlogN + N*l + |s|*(N))
// s.c. = O(N*l) excluding ans space.

// N is the size of contact list, l is the average length of each contact, |s| is the size of string s.
