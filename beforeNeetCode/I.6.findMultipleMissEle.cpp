#include <vector>
#include <iostream>
using namespace std;

vector<int> findPair(vector<int> nums, int sum){
    int l = 0, r = nums.size() - 1;
    vector<int> res;
    while(l < r){
        if(nums[l] + nums[r]){
            res.push_back(nums[l]);
            res.push_back(nums[r]);
            break;
        }
        else if(nums[l] + nums[r] < sum){l++;}
        else{r--;}
    }
    return res;
}

int main(int argc, char *argv[]){
        vector<int> nums = {3, 4, 5, 6, 7};
    vector<int> missing = findPair(nums, 10);

    cout << "Find pair of elements: ";
    for (int num : missing) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}