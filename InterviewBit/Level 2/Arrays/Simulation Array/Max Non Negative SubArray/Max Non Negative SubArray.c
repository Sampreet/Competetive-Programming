int* maxset(int* A, int n1, int *length_of_array) {
    int i,start=0,curr_start=0,max_len=0,curr_len=0;
    unsigned long long curr_max=0,max_sum=0;
    for(i=0;i<n1;i++){
        if(A[i]>=0){
            curr_len++;
            curr_max+=A[i];
            if(curr_max>max_sum){
                max_len=curr_len;
                max_sum=curr_max;
                start=curr_start;
            }
            else if(curr_max==max_sum && max_len<curr_len){
                max_len=curr_len;
                max_sum=curr_max;
                start=curr_start;
            }
        }
        else{
            curr_max=0;
            curr_len=0;
            curr_start=i+1;
        }
    }
    *length_of_array=max_len;
    int *result = (int*)malloc(max_len*sizeof(int));
    for(i=0;i<max_len;i++){
        result[i]=A[start+i];
    }
    return result;
}
