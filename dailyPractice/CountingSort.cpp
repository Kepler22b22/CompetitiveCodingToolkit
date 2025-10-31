#include <iostream>
#include <vector>

using namespace std;

void CountingSort(vector<int> &nums){
    int m = *max_element(nums.begin(), nums.end());
    vector<int> count(m + 1, 0);
    for(int num : nums){
        count[num]++;
    }
    int idx = 0;
    for(int i = 0; i < nums.size(); ++i){
        while(count[i]-- > 0){
            nums[idx++] = i;
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
    vector<int> nums = {2, 5, 3, 0, 2, 3, 0, 3};

    cout << "Before: " << endl;
    printArray(nums);
    cout << "Counting Sort: " <<endl;
    CountingSort(nums);
    printArray(nums);

    return 0;
}

/*
Before: 
2 5 3 0 2 3 0 3 
Counting Sort: 
0 0 2 2 3 3 3 5
*/