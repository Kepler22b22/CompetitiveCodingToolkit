#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums, int low, int mid, int high){
    vector<int> temp(high - low + 1);
    int l = low, r = mid + 1, k = 0;
    while(l <= mid && )
}

int main(){
    //Merge Sort Recursive
    vector<int> nums = {12, 11, 13, 5, 6};
    cout << "Original array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;
    mergeSort(nums, 0, nums.size() - 1);
    cout << "Recursively Merge Sorted array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;

    nums = {12, 11, 13, 5, 6};
    cout << "Original array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;
    mergeSortI(nums);
    cout << "Iteratively Merge Sorted array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;

    return 0;
}