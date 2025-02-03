#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums, int low, int mid, int high){
    vector<int> temp(nums.size());
    int i = low, j = mid + 1, k = low;
    while(i <= mid && j <= high){
        if(nums[i] < nums[j]){
            temp[k++] = nums[i++];
        }
        else{
            temp[k++] = nums[j++];
        }
    }
    while(i <= mid){
        temp[k++] = nums[i++];
    }
    while(j <= high){
        temp[k++] = nums[j++];
    }
    for(i = low; i <= high; i++){
        nums[i] = temp[i];
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

    return 0;
}