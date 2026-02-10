// children[ch]: inserts default entry if missing → modifies map
// children.count(ch): only checks existence → no modification

// unique_ptr<T> is a smart pointer that owns a T and deletes it automatically when it goes out of scope.

#include <iostream>
#include <unordered_map>

using namespace std;

class TrieNode {
private:
    unordered_map<char, unique_ptr<TrieNode>> children;
    bool endOfWord;

public:
    TrieNode(): endOfWord(false) {}
    
    void insert(string word){
        TrieNode *cur = this;
        for(char ch : word){
            auto &child = cur->children[ch];
            if(!child) child = make_unique<TrieNode>();
            cur = child.get();
        }
        cur->endOfWord = true;
    }

    bool startsWith(string prefix){
        TrieNode *cur = this;
        for(char ch : prefix){
            auto &child = cur->children[ch];
            if(!child) return false;
            cur = child.get();
        }
        return true;
    }

    bool search(string word){
        TrieNode *cur = this;
        for(char ch : word){
            auto &child = cur->children[ch];
            if(!child) return false;
            cur = child.get();
        }
        return cur->endOfWord;
    }
};

int main() {
    TrieNode trie;

    // Insert words into the Trie
    trie.insert("Apple");
    trie.insert("App");
    trie.insert("banana");
    trie.insert("bat");

    // Search for words
    cout << "Search 'Apple': " << (trie.search("Apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'App': " << (trie.search("App") ? "Found" : "Not Found") << endl;
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
    Search 'App': Found
    Search 'bat': Found
    Search 'ban': Not Found
    Prefix 'Ap': Exists
    Prefix 'ban': Exists
    Prefix 'ba': Exists
    Prefix 'cat': Does Not Exist
    */

    return 0;
}