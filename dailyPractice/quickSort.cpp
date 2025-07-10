#include <iostream>
#include <vector>

using namespace std;

int partitionI(vector<int> &nums, int low, int high){
    int pivot = nums[low], l = low, r = high;
    while(l < r){
        while(l <= high && nums[l] <= pivot){l++;}
        while(r >= low && nums[r] > pivot){r--;}
        if(l < r){swap(nums[l], nums[r]);}
    }
    swap(nums[low], nums[r]);
    return r;
}

void quickSortI()

int main(){
    //Quick Sort I
    vector<int >nums = {5, 4, 3, 2, 1};
    cout << "Original array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;
    quickSortI(nums, 0, nums.size() - 1);
    cout << "Quick Sorted array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;

    //Quick Sort II: nums[high] as pivot
    nums = {5, 4, 3, 2, 1};
    cout << "Original array II: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;
    quickSortII(nums, 0, nums.size() - 1);
    cout << "Quick Sorted array II: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;

    return 0;
}