#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &nums){
    for(int i = 0; i < nums.size() - 1; i++){
        int flag = 0;
        for(int j = 0; j < nums.size() - 1 - i; j++){
            if(nums[j] > nums[j + 1]){
                swap(nums[j], nums[j + 1]);
                flag = 1;
            }
        }
        if(!flag){break;} //means array already sorted
    }
}

void insertionSort(vector<int> &nums){
    for(int i = 1; i < nums.size(); i++){
        int insertVal = nums[i];
        int j = i - 1;
        while(j >= 0 && nums[j] > insertVal){
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = insertVal;
    }
}

void selectionSort(vector<int> &nums){
    for(int i = 0; i < nums.size() - 1; i++){
        int minIdx = i;
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[j] < nums[minIdx]){minIdx = j;}
        }
        if(minIdx != i){swap(nums[i], nums[minIdx]);}
    }
}

int partition(vector<int> &nums, int low, int high){
    int pivot = nums[low];
    int i = low, j = high;
    while(i < j){
        while(i <= high && nums[i] <= pivot){i++;}
        while(j >= low && nums[j] > pivot){j--;}
        if(i < j){swap(nums[i], nums[j]);}
    }
    swap(nums[low], nums[j]);
    return j;
}

void quickSort(vector<int> &nums, int low, int high){
    if(low < high){
        int idx = partition(nums, low, high);
        quickSort(nums, low, idx - 1);
        quickSort(nums, idx + 1, high);
    }
}

void merge(vector<int> &nums, int low, int mid, int high){
    int i = low, j = mid + 1, k = low;
    vector<int> temp(nums.size());
    while(i <= mid && j <= high){
        if(nums[i] < nums[j]){temp[k++] = nums[i++];}
        else{temp[k++] = nums[j++];}
    }
    while(i <= mid){temp[k++] = nums[i++];}
    while(j <= high){temp[k++] = nums[j++];}
    for(int i = low; i <= high; i++){nums[i] = temp[i];}
}

void mergeSortRecursive(vector<int> &nums, int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSortRecursive(nums, low, mid);
        mergeSortRecursive(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
}

void mergeSortIterative(vector<int>& nums) {
    for (int cur_size = 1; cur_size < nums.size(); cur_size *= 2) {
        for (int low = 0; low < nums.size() - 1; low += 2 * cur_size) {
            int mid = min(low + cur_size - 1, (int)nums.size() - 1);
            int high = min(low + 2 * cur_size - 1, (int)nums.size() - 1);
            merge(nums, low, mid, high);
        }
    }
}

void countingSort(vector<int> &nums){
    int max = *max_element(nums.begin(), nums.end());
    vector<int> count(max + 1, 0);
    for(int num : nums){
        count[num]++;
    }
    int i = 0, j = 0;
    while(j < max + 1){
        if(count[j]){
            nums[i++] = j;
            count[j]--;
        }
        else{j++;}
    }
}

void binSort(vector<int> &nums){
    if(nums.size() <= 1){return;}
    int max = *max_element(nums.begin(), nums.end());
    vector<vector<int>> bin(max+1);
    for(int num : nums){
        bin[num].push_back(num);
    }
    int i = 0, j = 0;
    while(j < max + 1){
        if(!bin[j].empty()){
            nums[i++] = bin[j].back();
            bin[j].pop_back();
        }
        else{j++;}
    }
}

//Not Important for LeetCode
void shellSort(vector<int> &nums){
    for(int gap = nums.size() / 2; gap >= 1; gap/=2){
        for(int i = gap; i < nums.size(); i++){
            int temp = nums[i];
            int j = i - gap;
            while(j >= 0 && nums[j] > temp){
                nums[j + gap] = nums[j];
                j = j - gap;
            }
            nums[j + gap] = temp;
        }
    }
}

int main() {
    //Buuble Sort
    vector<int> nums = {12, 11, 13, 5, 6};
    cout << "Original Array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;
    bubbleSort(nums);
    cout << "Bubble Sorted Array: ";
    for (int num : nums) { cout << num << " ";}
    cout << endl;

    //Insertion Sort
    nums = {12, 11, 13, 5, 6};
    cout << "Original Array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;
    insertionSort(nums);
    cout << "Insertion Sorted Array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;

    //Selection Sort
    nums = {12, 11, 13, 5, 6};
    cout << "Original Array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;
    selectionSort(nums);
    cout << "Selection Sorted Array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;

    //Quick Sort
    nums = {12, 11, 13, 5, 6};
    cout << "Original array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;
    quickSort(nums, 0, nums.size() - 1);
    cout << "Quick Sorted array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;

    //Merge Sort Recursive
    nums = {12, 11, 13, 5, 6};
    cout << "Original array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;
    mergeSortRecursive(nums, 0, nums.size() - 1);
    cout << "Recursively Merge Sorted array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;

    //Merge Sort Iterative
    nums = {12, 11, 13, 5, 6};
    cout << "Original array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;
    mergeSortIterative(nums);
    cout << "Iteratively Merge Sorted array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;

    //Count Sort
    nums = {3, 6, 5, 2, 3, 3};
    cout << "Original array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;
    countingSort(nums);
    cout << "Counting Sorted array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;

    //Bin Sort
    nums = {3, 6, 5, 2, 3, 3};
    cout << "Original array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;
    binSort(nums);
    cout << "Bin/Bucket Sorted array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;

    //Shell Sort
    nums = {3, 6, 5, 2, 3, 3};
    cout << "Original array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;
    shellSort(nums);
    cout << "Shell Sorted array: ";
    for (int num : nums) {cout << num << " ";}
    cout << endl;

    return 0;
}