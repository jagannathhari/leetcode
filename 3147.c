#include<limits.h>
#include<stdlib.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)

int maximumEnergy(int* restrict energy, int energySize, int k) {
    int *dp = calloc(energySize+k , sizeof(*dp));
    int ans = INT_MIN;
    for(int i = energySize -1 ; i>=0;i--){
        dp[i] = dp[i+k] + energy[i];
        ans = max(dp[i],ans);
    }
    return ans;
}
