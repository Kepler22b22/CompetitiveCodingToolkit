#include <iostream>
#include <vector>

using namespace std;

int findEqualOrGreater(vector<int> &nums, int target){
    int l = 0, r = nums.size() - 1, res = -1;
    while(l <= r){
        int mid = l + ((r - l) >> 1);
        if(nums[mid] < target) l = mid + 1;
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
        int mid = l + ((r - l) >> 1);
        if(nums[mid] <= target) l = mid + 1;
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
        int mid = l + ((r - l) >> 1);
        if(nums[mid] > target) r = mid - 1;
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
        int mid = l + ((r - l) >> 1);
        if(nums[mid] >= target) r = mid - 1;
        else{
            res = mid;
            l = mid + 1;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};

    int target1 = 6; // Between 5 and 7
    int target2 = 10; // Between 9 and 11
    int target3 = 1;  // First element
    int target4 = 12; // Greater than the largest
    int target5 = 0;  // Less than the smallest

    cout << "findEqualOrGreater(6): " << findEqualOrGreater(nums, target1) << endl;  // Expect index 3 (7)
    cout << "findGreater(6): \t" << findGreater(nums, target1) << endl;                // Expect index 3 (7)
    cout << "findEqualOrSmaller(6): " << findEqualOrSmaller(nums, target1) << endl;  // Expect index 2 (5)
    cout << "findSmaller(6): \t" << findSmaller(nums, target1) << endl;                // Expect index 2 (5)

    cout << "findEqualOrGreater(10): " << findEqualOrGreater(nums, target2) << endl; // Expect index 5 (11)
    cout << "findGreater(10): \t" << findGreater(nums, target2) << endl;               // Expect index 5 (11)
    cout << "findEqualOrSmaller(10): " << findEqualOrSmaller(nums, target2) << endl; // Expect index 4 (9)
    cout << "findSmaller(10): \t" << findSmaller(nums, target2) << endl;               // Expect index 4 (9)

    cout << "findEqualOrGreater(1): " << findEqualOrGreater(nums, target3) << endl;  // Expect index 0 (1)
    cout << "findGreater(1): \t" << findGreater(nums, target3) << endl;                // Expect index 1 (3)
    cout << "findEqualOrSmaller(1): " << findEqualOrSmaller(nums, target3) << endl;  // Expect index 0 (1)
    cout << "findSmaller(1): \t" << findSmaller(nums, target3) << endl;                // Expect -1 (No smaller)

    cout << "findEqualOrGreater(12): " << findEqualOrGreater(nums, target4) << endl; // Expect -1 (No equal or greater)
    cout << "findGreater(12): \t" << findGreater(nums, target4) << endl;               // Expect -1 (No greater)
    cout << "findEqualOrSmaller(12): " << findEqualOrSmaller(nums, target4) << endl; // Expect index 5 (11)
    cout << "findSmaller(12): \t" << findSmaller(nums, target4) << endl;               // Expect index 5 (11)

    cout << "findEqualOrGreater(0): " << findEqualOrGreater(nums, target5) << endl;  // Expect index 0 (1)
    cout << "findGreater(0): \t" << findGreater(nums, target5) << endl;                // Expect index 0 (1)
    cout << "findEqualOrSmaller(0): " << findEqualOrSmaller(nums, target5) << endl;  // Expect -1 (No equal or smaller)
    cout << "findSmaller(0): \t" << findSmaller(nums, target5) << endl;                // Expect -1 (No smaller)

    return 0;
}