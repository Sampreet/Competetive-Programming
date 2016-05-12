int max(int a, int b){
    return a>=b?a:b;
}

int rob(int* nums, int numsSize) {
    if(numsSize==0 || nums==NULL){
        return 0;
    }
    int dp[numsSize+1],i;
    dp[0]=0;
    dp[1]=nums[0];
    for(i=2;i<numsSize+1;i++){
        dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
    }
    return dp[numsSize];
}
