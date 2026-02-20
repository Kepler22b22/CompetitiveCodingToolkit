#include <iostream>
#include <vector>

using namespace std;

void CountingSort(vector<int> &nums){
    int mx = *max_element(nums.begin(), nums.end());
    int mn = *min_element(nums.begin(), nums.end());
    vector<int> count(mx - mn + 1, 0);
    for(int num : nums){
        count[num - mn]++;
    }
    int idx = 0;
    for(int i = 0; i <= mx - mn; ++i){
        while(count[i]-- > 0){
            nums[idx++] = i - mn;
        }
    }
}

void printArray(vector<int> &nums){
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;
}

// Unstable: equal elements may not preserve original relative order (usually fine).
int main() {
    vector<int> nums1 = {2, 5, 3, 0, 2, 3, 0, 3};

    cout << "Before: " << endl;
    printArray(nums1);
    cout << "Counting Sort: " <<endl;
    CountingSort(nums1);
    printArray(nums1);

    vector<int> nums2 = {-1, 0, 3, 7, 4, -2};

    cout << "Before: " << endl;
    printArray(nums2);
    cout << "Counting Sort: " <<endl;
    CountingSort(nums2);
    printArray(nums2);

    return 0;
}

/*
Before: 
2 5 3 0 2 3 0 3 
Counting Sort: 
0 0 2 2 3 3 3 5
*/