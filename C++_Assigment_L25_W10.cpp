#include <iostream>
#include <vector>
int binarySearchDesc(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;  // Target not found
}
int main() {
    std::vector<int> arr = {10, 8, 6, 4, 2};
    int target = 6;
    int result = binarySearchDesc(arr, target);

    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << "." << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array." << std::endl;
    }
    return 0;
}

//                                      2 Solution

#include<iostream>
#include<vector>
using namespace std;
int binarySearchInfinite(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (true) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;

        if (left > right)
            return -1;  // Target not found
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 1;
    int result = binarySearchInfinite(arr, target);

    if (result != -1)
        std::cout << "Element " << target << " found at index " << result << "." << std::endl;
    else
        std::cout << "Element " << target << " not found in the array." << std::endl;
    return 0;
}

//                                   3 Solution

#include <vector>
#include <iostream>

bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0;
    int right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int mid_value = matrix[mid / n][mid % n];

        if (mid_value == target) {
            return true;
        } else if (mid_value < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}
int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target1 = 3;
    int target2 = 13;

    bool result1 = searchMatrix(matrix, target1);
    bool result2 = searchMatrix(matrix, target2);

    std::cout << std::boolalpha;
    std::cout << "Target " << target1 << " found: " << result1 << std::endl;  // Output: true
    std::cout << "Target " << target2 << " found: " << result2 << std::endl;  // Output: false

    return 0;
}

//                                     4 Solution

#include <vector>
#include <iostream>

bool search(const std::vector<int>& nums, int target) {
    if (nums.empty()) return false;

    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return true;
        }
        // The tricky part: handling duplicates
        if (nums[left] == nums[mid] && nums[right] == nums[mid]) {
            left++;
            right--;
        } else if (nums[left] <= nums[mid]) {
            // Left part is sorted
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            // Right part is sorted
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return false;
}

int main() {
    std::vector<int> nums1 = {2, 5, 6, 0, 0, 1, 2};
    int target1 = 0;
    std::cout << std::boolalpha << "Target " << target1 << " found: " << search(nums1, target1) << std::endl;

    std::vector<int> nums2 = {2, 5, 6, 0, 0, 1, 2};
    int target2 = 3;
    std::cout << std::boolalpha << "Target " << target2 << " found: " << search(nums2, target2) << std::endl;
    return 0;
}
