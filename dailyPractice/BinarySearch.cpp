#include <iostream>
#include <vector>

using namespace std;

int findEqualOrGreater(vector<int> &nums, int target){
    int l = 0, r = nums.size() - 1, res = -1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(nums[mid] < target){l = mid + 1;}
        else{
            res = mid;
            r = mid - 1;
        }
    }
    return res;
}

int findGreater(vector<int> &nums, int target){
    int l = 0, r = nums.size() - 1, res = -1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(nums[mid] <= target){l = mid + 1;}
        else{
            res = mid;
            r = mid - 1;
        }
    }
    return res;
}

int findEqualOrSmaller(vector<int> &nums, int target){
    int l = 0, r = nums.size() - 1, res = -1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(nums[mid] > target){r = mid - 1;}
        else{
            res = mid;
            l = mid + 1;
        }
    }
    return res;
}

int findSmaller(vector<int> &nums, int target){
    int l = 0, r = nums.size() - 1, res = -1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(nums[mid] >= target){r = mid - 1;}
        else{
            res = mid;
            l = mid + 1;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int target = 6;

    cout << "findEqualOrGreater: " << findEqualOrGreater(nums, target) << endl;
    cout << "findGreater: " << findGreater(nums, target) << endl;
    cout << "findEqualOrSmaller: " << findEqualOrSmaller(nums, target) << endl;
    cout << "findSmaller: " << findSmaller(nums, target) << endl;

    /*
    Expected Output:
    findEqualOrGreater: 3
    findGreater: 3
    findEqualOrSmaller: 2
    findSmaller: 2
    */

    return 0;

}