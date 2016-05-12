void moveZeroes(int* nums, int numsSize) {
    int p1=0,p2=0;
    while(p1<numsSize){
        if(nums[p1]!=0 && p1>p2){
            int temp=nums[p1];
            nums[p1]=nums[p2];
            nums[p2]=temp;
        }
        while(nums[p2]!=0 && p2<numsSize){
            p2++;
            if(p2==numsSize)
                break;
        }
        p1++;
        if(p1==numsSize || p2==numsSize)
            break;
    }
}
