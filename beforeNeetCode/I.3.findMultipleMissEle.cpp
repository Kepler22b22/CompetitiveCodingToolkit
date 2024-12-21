#include <vector>
#include <iostream>
using namespace std;
//g++ -std=c++11

vector<int> findMultiMissEle(vector<int> nums){
    vector<int> res;
    int max = nums[0];
    for(int num : nums){
        if(num > max){max = num;}
    }

    vector<int> hashTable(max, 0);
    for(int i = 0; i < nums.size(); i++){
        hashTable[nums[i]]++;
    }
    for(int i = 1; i < max; i++){
        if(hashTable[i] == 0){res.push_back(i);}
    }
    return res;
}

int main(int argc, char *argv[]){
    vector<int> nums = {4, 7, 2, 5, 3};
    vector<int> missing = findMultiMissEle(nums);

    cout << "Find multiple missing elements: ";
    for (int num : missing) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}