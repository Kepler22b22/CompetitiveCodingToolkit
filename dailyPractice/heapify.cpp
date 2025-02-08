#include <iostream>
#include <vector>

using namespace std;

void heapifyMax(vector<int> &nums, int n, int i){
    int root = i, l = 2 * i + 1, r = 2 * i + 2;
    if(l < n && nums[l] > nums[root]){root = l;}
    if(r < n && nums[r] > nums[root]){root = r;}
    if(root != i){
        swap(nums[root], nums[i]);
        heapifyMax(nums, n, root);
    }
}

void maxHeap(vector<int> &nums){
    for(int i = nums.size() / 2 - 1; i >= 0; i--){
        heapifyMax(nums, nums.size(), i);
    }
    for(int i = nums.size() - 1; i > 0; i--){
        swap(nums[i], nums[0]);
        heapifyMax(nums, i, 0);
    }
}

void heapifyMin(vector<int> &nums, int n, int i){
    int root = i, l = 2 * i + 1, r = 2 * i + 2;
    if(l < n && nums[l] < nums[root]){root = l;}
    if(r < n && nums[r] < nums[root]){root = r;}
    if(root != i){
        swap(nums[root], nums[i]);
        heapifyMin(nums, n, root);
    }
}

void minHeap(vector<int> &nums){
    for(int i = nums.size() / 2 - 1; i >= 0; i--){
        heapifyMin(nums, nums.size(), i);
    }
    for(int i = nums.size() - 1; i > 0; i--){
        swap(nums[0], nums[i]);
        heapifyMin(nums, i, 0);
    }
}

void printArray(const vector<int> &nums) {
    for (int num : nums) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> numsMax = {4, 10, 3, 5, 1, 6, 8, 7, 9, 2};
    vector<int> numsMin = numsMax;

    cout << "Original Array: ";
    printArray(numsMax);

    maxHeap(numsMax);

    cout << "Max Heap: ";
    printArray(numsMax);

    cout << "Original Array: ";
    printArray(numsMin);

    minHeap(numsMin);

    cout << "Min Heap: ";
    printArray(numsMin);

    /*
    Expected Output:
    Original Array: 4 10 3 5 1 6 8 7 9 2 
    Max Heap: 10 9 8 7 2 6 3 4 5 1 
    Original Array: 4 10 3 5 1 6 8 7 9 2 
    Min Heap: 1 2 3 5 4 6 8 7 9 10
    */

    return 0;
}