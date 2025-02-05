#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &nums, int n, int i){
    int root = i, l = 2 * i + 1, r = 2 * i + 2;
    if(l < n && nums[l] > nums[root]){
        root = l;
    }
    if(r < n && nums[r] > nums[root]){
        root = r;
    }
    if(root != i){
        swap(nums[root], nums[i]);
        heapify(nums, n, root);
    }
}

void maxHeap(vector<int> &nums){
    for(int i = nums.size() / 2 - 1; i >= 0; i--){
        heapify(nums, nums.size(), i);
    }
}

void printArray(const vector<int> &nums) {
    for (int num : nums) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> nums = {4, 10, 3, 5, 1, 6, 8, 7, 9, 2};

    cout << "Original Array: ";
    printArray(nums);

    maxHeap(nums);

    cout << "Max Heap: ";
    printArray(nums);

    return 0;
}