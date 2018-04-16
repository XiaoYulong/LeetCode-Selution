/*169. Majority Element
*/

int majorityElement(int* nums, int numsSize) {
    int result = nums[0];
    int time = 1;
    for (int i = 1; i < numsSize; ++i)
    {
        nums[i] == result ? time++ : time--;
        if (time == 0)
        {
            result = nums[i];
            time++;
        }
    }
    return result;
}