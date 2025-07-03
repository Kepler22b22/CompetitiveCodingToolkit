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

void quickSortI(vector<int> &nums, int low, int high){
    if(low < high){
        int idx = partitionI(nums, low, high);
        quickSortI(nums, low, idx - 1);
        quickSortI(nums, idx + 1, high);
    }
}

int partitionII(vector<int> &nums, int low, int high){
    int pivot = nums[high], l = low - 1;
    for(int r = low; r <= high; r++){
        if(nums[r] < pivot){
            l++;
            swap(nums[l], nums[r]);
        }
    }
    swap(nums[high], nums[l + 1]);
    return l + 1;
}

void quickSortII(vector<int> &nums, int low, int high){
    if(low < high){
        int idx = partitionII(nums, low, high);
        quickSortII(nums, low, idx - 1);
        quickSortII(nums, idx + 1, high);
    }
}

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