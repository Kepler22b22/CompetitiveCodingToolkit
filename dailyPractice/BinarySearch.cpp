
int main(){
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int target = 6;

    cout << "findEqualOrGreater: " << findEqualOrGreater(nums, target) << endl;
    cout << "findGreater: " << findGreater(nums, target) << endl;
    cout << "findEqualOrSmaller: " << findEqualOrSmaller(nums, target) << endl;
    cout << "findSmaller: " << findSmaller(nums, target) << endl;

    return 0;

}