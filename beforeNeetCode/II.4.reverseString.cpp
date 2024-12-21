#include <iostream>
using namespace std;

void reverseStr(char str[]){
    int l = 0, r = strlen(str) - 1;
    while(l < r){
        char temp = str[l];
        str[l] = str[r];
        str[r] = temp;
        l++;
        r--;
    }
}

int main(int argv, char *argc[]){
    char str[] = "Hello world!";
    reverseStr(str);
    cout << "After reverse: " << str << endl;
    return 0;
}