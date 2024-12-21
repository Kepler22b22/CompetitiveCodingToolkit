#include <vector>
#include <iostream>
using namespace std;
//g++ -std=c++11 2.findSingleMissEle.cpp -o 2.findSingleMissEle

int findSingleMissEle1(vector<int> nums){
    int total = (nums.size() + 1) * (nums[0] + nums[nums.size() - 1]) / 2;
    int sum = 0;
    for(int num : nums){
        sum += num;
    }
    return total - sum;
}

int findSingleMissEle2(vector<int> nums){
    int res = -1;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] - i != nums[0]){
            res = i + nums[0];
            return res;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {1, 3, 4, 5, 6};
    cout << "find single missing ele (Method 1): " << findSingleMissEle1(nums) << endl;
    cout << "find single missing ele (Method 2): " << findSingleMissEle2(nums) << endl;
    return 0;

}