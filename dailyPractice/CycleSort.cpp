// [0, n] or [1, n], and appears exactly once.
// O(n^2), but advantage: minimal writes, not minimal comparisons
#include <iostream>
#include <vector>

using namespace std;

void CycleSort(vector<int> &nums){
    int i = 0;
    while(i < nums.size()){
        if(nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
        else i++;
    }
}

void printArray(vector<int> &nums){
    for (const auto &num : nums)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> nums = { 3, 2, 4, 5, 1};
    cout << "Before sorting array: \n";
    printArray(nums);
    CycleSort(nums);
    cout << "Sorted array: \n";
    printArray(nums);
  return 0;

}