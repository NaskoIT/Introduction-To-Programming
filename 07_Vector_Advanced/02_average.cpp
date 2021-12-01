#include <iostream>
#include <vector>

using namespace std;

double average(vector<int>& nums) {
    double sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }

    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < nums.size(); i++) {
        cin >> nums[i];
    }

    cout << average(nums);
}