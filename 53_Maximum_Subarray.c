/*
shis is a DP problem

定义一下子问题：_maxSubArrayIncludeLastItem(int *nums, int numSize)
返回以最后一个元素结尾的最大子串和

解释一下：_maxSubArrayIncludeLastItem（a, 5）返回的是包含第五个元素的最大值

那么 _maxSubArrayIncludeLastItem（a, 5） = _maxSubArrayIncludeLastItem（a, 4）> 0 ? _maxSubArrayIncludeLastItem（a, 4）+ a[4] : a[4]

要求以第五个元素结尾的最大子串和，可以通过以第四个元素结尾的最大子串和很快求出：

如果以第四位结尾的最大子串和为正数，那么 以第五个元素结尾的最大子串和 就是 以第四位结尾的最大子串和 加上 第五个元素
如果以第四位结尾的最大子串和为负数或者等于0，那么 第五个元素结尾的最大子串和 就是 第五个元素 本身

这样递归求解，我们就可以求出，以每个元素结尾的最大子串和， 假设我们用一个数组记录下来以每个元素结尾的子串的最大和，
那么 原始问题就是这个数组中的元素的最大值

因为，任意一个子串，总需要以某一个元素结尾

这样，我们就构造出一个时间复杂度为 O(n), 空间复杂度为O(n)的解法

但是，我们在遍历求解以某一个元素结尾的最大子串和的过程中，可以在规模一步步扩大时，记录一下当前规模原始问题的最大值
这样就可以节省掉存储每一个元素结尾的最大子串和的数组，将空间复杂度从O(n)降到O(1)

下面就是最终解决方案

*/
 int maxSubArray(int* nums, int numsSize) {
    
     int result = INT_MIN;
     int preMax = INT_MIN;
    
     for (int i = 0; i < numsSize; ++i)
     {
         int currentMax = preMax > 0 ? preMax + nums[i] : nums[i];
         result = result > currentMax ? result : currentMax;
         preMax = currentMax;
     }
        
     return result;
 }

/*
这个问题有一个变种，就是如果最大子串和为负数，则返回0, 可以将代码稍作调整，如下
*/
int positiveMaxSubArray(int* nums, int numsSize) {
    
    int result = 0;
    int preMax = INT_MIN;
    
    for (int i = 0; i < numsSize; ++i)
    {
        int currentMax = preMax > 0 ? preMax + nums[i] : nums[i];
        result = result > currentMax ? result : currentMax;
        preMax = currentMax;
    }
        
    return result;
}
