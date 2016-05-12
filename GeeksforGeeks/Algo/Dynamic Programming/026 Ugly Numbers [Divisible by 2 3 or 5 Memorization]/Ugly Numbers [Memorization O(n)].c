#include<stdio.h>
#include<stdlib.h>

int min(int a,int b){
    return a<b?a:b;
}

int min3(int a,int b,int c){
    return min(min(a,b),c);
}

int nthUglyNum(int n){
    int uglyNum[n],i2=0,i3=0,i5=0,i,j,next_2=2,next_3=3,next_5=5,next_ugly=1;
    uglyNum[0]=1;
    for(i=1;i<n;i++){
        next_ugly=min3(next_2,next_3,next_5);
        uglyNum[i]=next_ugly;
        if(next_ugly==next_2){
            i2++;
            next_2=uglyNum[i2]*2;
        }
        if(next_ugly==next_3){
            i3++;
            next_3=uglyNum[i3]*3;
        }
        if(next_ugly==next_5){
            i5++;
            next_5=uglyNum[i5]*5;
        }
    }
    return next_ugly;
}

int main(){
    int N,i;
    scanf("%d",&N);
    printf("%d",nthUglyNum(N));
    return 0;
}
