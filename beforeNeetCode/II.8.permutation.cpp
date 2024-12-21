#include <iostream>
#include <vector>
#include <string>
using namespace std;

void perm(string &str, int l, int r, vector<string> &res){
    if(l == r){res.push_back(str);}
    else{
        for(int i = l; i <= r; i++){
            swap(str[l], str[i]);
            perm(str, l + 1, r, res);
            swap(str[l], str[i]);
        }
    }
}

vector<string> permutation(string str){
    vector<string> res;
    perm(str, 0, str.size() - 1, res);
    return res;
}

int main() {
    string str = "abc";
    vector<string> perms = permutation(str);

    cout << "Permutations of " << str << " are:" << endl;
    for (const string &perm : perms) {
        cout << perm << endl;
    }

    return 0;
}