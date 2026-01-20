#include <iostream>
#include <vector>

using namespace std;

int partitionI(vector<int> &nums, int low, int high){
    int pivot = nums[low];
    int l = low, r = high;
    while(l <= r){
        while(l <= high && nums[l] <= pivot){l++;}
        while(r >= low && nums[r] > pivot){r--;}
        if(l < r) swap(nums[l], nums[r]);
    }
    swap(nums[r], nums[low]);
    return r;
}

void quickSortI(vector<int> &nums, int low, int high){
    if(low < high){
        int mid = partitionI(nums, low, high);
        quickSortI(nums, low, mid - 1);
        quickSortI(nums, mid + 1, high);
    }
}

int partitionII(vector<int> &nums, int low, int high){
    int pivot = nums[high];
    int l = low - 1;
    for(int r = low; r <= high; ++r){
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
        int mid = partitionII(nums, low, high);
        quickSortII(nums, low, mid - 1);
        quickSortII(nums, mid + 1, high);
    }
}

int partitionIII(vector<int> &nums, int low, int high){
    int mid = low + ((high - low) >> 1);
    swap(nums[low], nums[mid]);
    if(nums[low] > nums[high]) swap(nums[low], nums[high]);
    if(nums[low + 1] > nums[high]) swap(nums[low + 1], nums[high]);
    if(nums[low] > nums[low + 1]) swap(nums[low], nums[low + 1]);
    int pivot = nums[low + 1];
    int l = low, r = high;
    while(l <= r){
        while(l <= high && nums[l] <= pivot) l++;
        while(r >= low && nums[r] > pivot) r--;
        if(l < r) swap(nums[l], nums[r]);
    }
    nums[low + 1] = nums[r];
    nums[r] = pivot;
    return r;
}

void quickSortIII(vector<int> &nums, int low, int high){
    if(low < high){
        int mid = partitionIII(nums, low, high);
        quickSortIII(nums, low, mid - 1);
        quickSortIII(nums, mid + 1, high);
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

    //Quick Sort III: nums[low + 1] as pivot
    // Median-of-three
    nums = {5, 4, 3, 2, 1};
    cout << "Original array III: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;
    quickSortIII(nums, 0, nums.size() - 1);
    cout << "Quick Sorted array III: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;

    return 0;
}