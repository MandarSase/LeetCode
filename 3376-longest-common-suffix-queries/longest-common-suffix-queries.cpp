class TrieNode {
public:
    vector<shared_ptr<TrieNode>> children;
    int length;
    int index;

    TrieNode() {
        children.resize(26, nullptr);
        length = INT_MAX;
        index = -1;
    }
};

class Solution {
public:
    shared_ptr<TrieNode> root = make_shared<TrieNode>();

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        vector<int> ans;
        int minIndex = 0;

        
        for (int i = 0; i < wordsContainer.size(); i++) {
            if (wordsContainer[i].length() <
                wordsContainer[minIndex].length()) {
                minIndex = i;
            }

            insert(wordsContainer[i], i);
        }

        
        root->index = minIndex;
        root->length = wordsContainer[minIndex].length();

        for (string& query : wordsQuery) {
            ans.push_back(search(query));
        }

        return ans;
    }

private:
    void insert(const string& word, int wordIndex) {
        shared_ptr<TrieNode> node = root;

        
        if (word.length() < node->length) {
            node->length = word.length();
            node->index = wordIndex;
        }

        for (int i = word.length() - 1; i >= 0; i--) {

            int ch = word[i] - 'a';

            if (node->children[ch] == nullptr) {
                node->children[ch] = make_shared<TrieNode>();
            }

            node = node->children[ch];

            
            if (word.length() < node->length) {
                node->length = word.length();
                node->index = wordIndex;
            }
        }
    }

    int search(const string& word) {
        shared_ptr<TrieNode> node = root;

        for (int i = word.length() - 1; i >= 0; i--) {

            int ch = word[i] - 'a';

            if (node->children[ch] == nullptr) {
                return node->index;
            }

            node = node->children[ch];
        }

        return node->index;
    }
};