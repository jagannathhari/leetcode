int *productExceptSelf(int *nums, int numsSize, int *returnSize) {
    int product = 1;
    int flag = 0;
    int countZeroes = 0;

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == 0) {
            flag = 1;
            countZeroes++;
            continue;
        }
        product *= nums[i];
    }

    int *ans = malloc(numsSize * sizeof(*ans));
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == 0) {
            if (countZeroes > 1) {
                ans[i] = 0;
            } else {
                ans[i] = product;
            }
        } else {
            if (flag) {
                ans[i] = 0;
            } else {
                ans[i] = product / nums[i];
            }
        }
    }

    return ans;
}
