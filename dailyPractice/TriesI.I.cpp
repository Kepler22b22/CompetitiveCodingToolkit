#include <iostream>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;

    TrieNode(): endOfWord(false) {}
};

class PrefixTree {
private:
    TrieNode *root;

public:
    PrefixTree(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode *cur = root;
        for(char ch : word){
            if(!cur->children.count(ch)){
                cur->children[ch] = new TrieNode();
            }
            cur = cur->children[ch];
        }
        cur->endOfWord = true;
    }

    bool startsWith(string prefix){
        TrieNode *cur = root;
        for(char  ch : prefix){
            if(!cur->children.count(ch)){return false;}
            cur = cur->children[ch];
        }
        return true;
    }

    bool search(string word){
        TrieNode *cur = root;
        for(char ch : word){
            if(!cur->children.count(ch)){return false;}
            cur = cur->children[ch];
        }
        return cur->endOfWord;
    }
};

int main() {
    PrefixTree trie;

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