// O(n^2), but advantage: minimal writes, not minimal comparisons

#include <iostream>
#include <vector>

using namespace std;

// [0, n] or [1, n], and appears exactly once.
void CycleSort(vector<int> &nums, int base) {   // base = 0 or 1
    int i = 0;
    while (i < nums.size()) {
        int correct = nums[i] - base;
        if (correct < 0 || correct >= (int)nums.size()) throw invalid_argument("value out of range");
        if (nums[i] != nums[correct]) swap(nums[i], nums[correct]);
        else i++;
    }
}

void printArray(vector<int> &nums){
    for (const auto &num : nums)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> nums = { 3, 2, 4, 5, 1, 0};
    cout << "Before sorting array: \n";
    printArray(nums);
    CycleSort(nums, 0);
    cout << "Sorted array: \n";
    printArray(nums);

    nums = {3, 2, 4, 5, 1};
    cout << "Before sorting array: \n";
    printArray(nums);
    CycleSort(nums, 1);
    cout << "Sorted array: \n";
    printArray(nums);

    nums = {3, 2, 4, 5};
    cout << "Before sorting array: \n";
    printArray(nums);
    CycleSort(nums, 2);
    cout << "Sorted array: \n";
    printArray(nums);
  return 0;

}