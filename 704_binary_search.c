int search(int* nums, int numsSize, int target) {
    int low, mid, high;
    low = 0;
    high = numsSize - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if (target > nums[mid]) {
            low = mid + 1;
        } else if (target < nums[mid]) {
            high = mid - 1;
        } else {
            return mid;
        }
    }  
    return -1;  
}

#include <assert.h>
int main() {
  int nums[] = {-1,0,3,5,9,12};
  assert(search(nums, 6, 9) == 4);
}
