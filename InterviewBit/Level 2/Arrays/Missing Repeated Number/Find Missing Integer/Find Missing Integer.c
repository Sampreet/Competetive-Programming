int find(int *nums, int numsSize){
    int i;
    for(i=0;i<numsSize;i++){
        if(abs(nums[i])-1<numsSize && nums[abs(nums[i])-1]>0){
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]>0){
            return i+1;
        }
    }
    return numsSize+1;
}

int firstMissingPositive(int* A, int n1) {
    int i,j=0;
    for(i=0;i<n1;i++){
        if(A[i]<=0){
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            j++;
        }
    }
    return find(A+j,n1-j);
}
