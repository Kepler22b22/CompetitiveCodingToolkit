// Use array when the size is fixed and meaningful. Use vector when the size is dynamic and intentional.
// Use the compiler-generated destructor, exactly as if I hadn’t written one — but generate it here.

#include <iostream>
#include <array>

using namespace std;

class TrieNode {
private:
    array<unique_ptr<TrieNode>, 52> children{};
    bool endOfWord;

    static int getIdx(char ch){
        if(islower(ch)) return ch - 'a' + 26;
        if(isupper(ch)) return ch - 'A';
        return -1;
    }

public:
    TrieNode(): endOfWord(false) {}
    ~TrieNode();

    void insert(string word){
        TrieNode *cur = this;
        for(char ch : word){
            int i = getIdx(ch);
            auto &child = cur->children[i];
            if(!child) child = make_unique<TrieNode>();
            cur = child.get();
        }
        cur->endOfWord = true;
    }

    bool startsWith(string prefix){
        TrieNode *cur = this;
        for(char ch : prefix){
            int i = getIdx(ch);
            auto &child = cur->children[i];
            if(!child) return false;
            cur = child.get();
        }
        return true;
    }

    bool search(string word){
        TrieNode *cur = this;
        for(char ch : word){
            int i = getIdx(ch);
            auto &child = cur->children[i];
            if(!child) return false;
            cur = child.get();
        }
        return cur->endOfWord;
    }
};

TrieNode::~TrieNode() = default;

int main() {
    TrieNode trie;

    // Insert words into the Trie
    trie.insert("Apple");
    trie.insert("App");
    trie.insert("banana");
    trie.insert("bat");

    // Search for words
    cout << "Search 'Apple': " << (trie.search("Apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search 'bat': " << (trie.search("bat") ? "Found" : "Not Found") << endl;
    cout << "Search 'ban': " << (trie.search("ban") ? "Found" : "Not Found") << endl;

    // Check for prefixes
    cout << "Prefix 'Ap': " << (trie.startsWith("Ap") ? "Exists" : "Does Not Exist") << endl;
    cout << "Prefix 'ban': " << (trie.startsWith("ban") ? "Exists" : "Does Not Exist") << endl;
    cout << "Prefix 'ba': " << (trie.startsWith("ba") ? "Exists" : "Does Not Exist") << endl;
    cout << "Prefix 'cat': " << (trie.startsWith("cat") ? "Exists" : "Does Not Exist") << endl;

    /*
    Expected Output:
    Search 'Apple': Found
    Search 'app': Not Found
    Search 'bat': Found
    Search 'ban': Not Found
    Prefix 'Ap': Exists
    Prefix 'ban': Exists
    Prefix 'ba': Exists
    Prefix 'cat': Does Not Exist
    */

    return 0;
}