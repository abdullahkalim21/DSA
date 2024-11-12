# Binary Search

## Definition

*__LeetCode Definition__*
Binary Search operates on a contiguous sequence with a specified `left` and `right` index. This is called the `Search Space`. Binary Search maintains the `left`, `right`, and `middle` indicies of the search space and compares the search `target` or applies the search condition to the `middle` value of the collection; if the condition is unsatisfied or values unequal, the half in which the `target` cannot lie is eliminated and the search continues on the remaining half until it is successful. If the search ends with an empty half, the condition cannot be fulfilled and `target` is not found.

*__General Concept__*
Binary search is an efficient algorithm for finding a `target` value within a sorted array or list. The basic idea is to repeatedly divide the search interval in half. If the value of the `target` is less than the value at the `midpoint`, we narrow our search to the `left` half, otherwise, we narrow it to the `right` half. This allows us to quickly eliminate half of the remaining elements in each step.


## Step-by-Step Algorithm walkthrough

The algorithm that got accepted in *__LeetCode__* to solve this problem is as follow:
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = int(nums.size()) - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
        }
        return -1;
    }
};
```

1. __Variables for Search Space__

- `left`: This is the starting index of the array (`0`).
- `right`: This is the ending index of the array (`nums.size() - 1`), where `nums.size()` gives the total number of elements in the array.
- At the beginning of the search, our entire array is the search space, from index `0` to `nums.size() - 1`.

2. __While Loop to Narrow Search Space__
```cpp
while (left <= right)
```
- The `while` loop continues as long as `left` is less than or equal to `right`. This means the search space is not empty yet.

3. __Calculate Midpoint__
```cpp
int mid = (left + right) / 2;
```
- `mid` is the midpoint of the current search range (from `left` to `right`).
- This is the key to the binary search process: it splits the search space in half.
- The division uses integer division, so it effectively rounds down when the sum of `left` and `right` is odd.

4. __Check if `target` is found__
```cpp
if (nums[mid] == target)
    return mid;
```
- We check if the element at the `mid` index is equal to the `target`.
- If it is, we immediately return the index `mid`, since we've found the `target`.

5. __Target is Greater than Mid Value__
```cpp
else if (nums[mid] < target)
    left = mid + 1;
```
- If the element at `mid` is smaller than the `target`, this means the `target` must be in the right half of the array.
- Therefore, we adjust the `left` boundary to `mid + 1` to search only the right half of the array.

6. __Target is Less than Mid Value__
```cpp
else if (nums[mid] > target)
    right = mid - 1;
```
- If the element at `mid` is greater than the `target`, this means the `target` must be in the left half of the array.
- We adjust the `right` boundary to `mid - 1` to search only the left half of the array.

7. __Return `-1` if Target is Not Found__
```cpp
return -1;
```
- If the `while` loop exits, it means that the `target` is not in the array. Therefore, we return `-1` to indicate that the `target` wasn't found.

____
## Let's Understand with an Example...!

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

```
Input: nums = [-1, 0, 3, 5, 9, 12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```
Let’s go through this algorithm step-by-step using the given example:

Input:
```cpp
nums = [-1, 0, 3, 5, 9, 12]
target = 9
```
We are given a sorted array `nums` and need to find the index of the `target` value `9`. Here's how the binary search algorithm works for this example:
___

**Initial Setup**

- Array (`nums`): `[-1, 0, 3, 5, 9, 12]`
- Target: `9`

We initialize the two pointers:

- `left = 0` (starting index of the array)
- `right = 5` (ending index of the array)

Now, we are going to perform the binary search.

I. __First Iteration__

Calculate Midpoint:
- `mid = (left + right) / 2` 
- - `mid = (0 + 5) / 2 = 2` (integer division).
- The element at index `mid` is `nums[mid] = nums[2] = 3`.
- Compare `nums[mid]` with `target`: `nums[mid] = 3` and `target = 9`.
- - Since `3 < 9`, we know the `target` must be in the right half of the array.
- - Therefore, we update `left = mid + 1 = 2 + 1 = 3` to search the right half.
```cpp
nums = [-1, 0, 3, 5, 9, 12] // [5, 9, 12] become our Search Space for next Iteration
// [-1, 0, 3] These are still a part of given array but these are ignored by loop condition to narrow down search space
```
II. __Second Iteration__
Now the updated search range is from `left = 3` to `right = 5`.
```cpp
nums = [-1, 0, 3, 5, 9, 12] // [5, 9, 12] become our Search Space
// [-1, 0, 3] These are still a part of given array but these are ignored by loop condition to narrow down search space
```
Calculate Midpoint:

- `mid = (left + right) / 2 = (3 + 5) / 2 = 4`.
- The element at index `mid` is `nums[mid] = nums[4] = 9`.

Compare `nums[mid]` with `target`: `nums[mid] = 9` and `target = 9`.
- Since `nums[mid] == target`, we've found the `target` at index `4`.

The `target 9` is found at index `4` in the array `nums`. Therefore, the function will return `4`.
Final Result:
```cpp
Output: 4
```