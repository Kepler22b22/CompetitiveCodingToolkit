#include <vector>
#include <iostream>
using namespace std;
//g++ -std=c++11 binarySearch.cpp -o binarySearch

int findEqualOrGreater(vector<int> nums, int target){
   int l = 0, r = nums.size() - 1;
   while(l < r){
      int mid = (l + r) / 2;
      if(nums[mid] < target){l = mid + 1;}
      else{r = mid;}
   }
   if(nums[r] >= target){return r;}
   return -1;
}

int findGreater(vector<int> nums, int target){
   int l = 0, r = nums.size() - 1;
   while(l < r){
      int mid = (l + r) / 2;
      if(nums[mid] <= target){l = mid + 1;}
      else{r = mid;}
   }
   if(nums[r] > target){return r;}
   return -1;
}

int findEqualOrSmaller(vector<int> nums, int target){
   int l = 0, r = nums.size() - 1;
   int result = -1;
   while(l < r){
      int mid = (l + r) / 2;
      if(nums[mid] > target){r = mid - 1;}
      else{
         result = mid;
         l = mid + 1;
      }
   }
   return result;
}

int findEqualOrSmaller(vector<int> nums, int target) {
   int l = 0, r = nums.size() - 1;
   while(l <= r){
         int mid = (l + r + 1) / 2;
         if(nums[mid] > target){
            r = mid - 1;
         }
         else{
            l = mid;
         }
   }
   if(nums[r] <= target){return r;}
   return -1;
}

int findSmaller(vector<int> nums, int target){
   int l = 0, r = nums.size() - 1;
   int result = -1;
   while(l < r){
      int mid = (l + r) / 2;
      if(nums[mid] >= target){r = mid - 1;}
      else{
         result = mid;
         l = mid + 1;
      }
      return result;
   }
}

int main(){
    vector<int> nums = {1, 3, 5, 7, 9};
    int target = 4;

    cout << "findEqualOrGreater: " << findEqualOrGreater(nums, target) << endl;
    cout << "findGreater: " << findGreater(nums, target) << endl;
    cout << "findEqualOrSmaller: " << findEqualOrSmaller(nums, target) << endl;
    cout << "findSmaller: " << findSmaller(nums, target) << endl;

    return 0;

}