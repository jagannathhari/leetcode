void sortColors(int* restrict nums, int numsSize) {
    int total[] = {0,0,0};
    for(int i=0;i<numsSize;i++) total[nums[i]]++;
    for(int i=0;i<total[0];i++) nums[i] = 0;
    for(int i=total[0];i<total[0]+total[1];i++) nums[i] = 1;
    for(int i=total[0]+total[1];i<numsSize;i++) nums[i] = 2;
}
