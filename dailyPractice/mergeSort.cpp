#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums, int low, int mid, int high){
    vector<int> temp(high - low + 1);
    int l = low, r = mid + 1, k = 0;
    while(l <= mid && r <= high){
        if(nums[l] < nums[r]){temp[k++] = nums[l++];}
        else{temp[k++] = nums[r++];}
    }
    while(l <= mid){temp[k++] = nums[l++];}
    while(r <= high){temp[k++] = nums[r++];}
    for(int i = low; i <= high; i++){
        nums[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &nums, int low, int high){
    if(low < high){
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
}

void mergeSortI(vector<int> &nums){
    for(int i = 1; i < nums.size(); i *= 2){
        for(int l = 0; l < nums.size() - i; l += i * 2){
            int mid = l + i - 1;
            int r = min(static_cast<int>(nums.size() - 1), l + 2 * i - 1);
            merge(nums, l, mid, r);
        }
    }
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