/*
 Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 
 You may assume no duplicates in the array.
 */

int searchInsert(int* nums, int numsSize, int target) {
    int index = 0;
    while(index < numsSize)
    {
        if (nums[index] < target)
        {
            index++;
            continue;
        }
        if (nums[index] >= target)
        {
            return index;
        }
    }
    return index;
}
