/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b)) ? (a) : (b)
#define len(arr) sizeof(arr)/sizeof(arr[0])
#define print_arr(arr,n,f) for(int i=0;i<n;++i) printf("%"#f" ",arr[i])


int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *result = malloc(1000*sizeof(*result));

    int freq1[1001]={0};
    int freq2[1001]={0};

    for(int i=0;i<nums1Size;i++) freq1[nums1[i]]++;
    for(int i=0;i<nums2Size;i++) freq2[nums2[i]]++;
    for(int i=0;i<1001;i++){
        int till = min(freq1[i],freq2[i]);
        if(till > 0){
            for(int j= 0;j<till;j++){
                result[(*returnSize)++] = i;
            }
        }
    }
    return result;
}

