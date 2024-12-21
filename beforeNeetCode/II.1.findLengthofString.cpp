#include <iostream>
using namespace std;

int findLength(char str[]){
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++){
        count++;
    }
    return count;
}

int main(int argc, char *argv[]){
    char str[] = "test";
    cout << "The length of the string is: " << findLength(str) << endl; 
    return 0;
}