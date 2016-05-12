#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int long_rec[10001][2];
int filled;

void fillLongRec(int N){
    int sequenceLength=0;
    int num=0,i;
    for(i=2;i<=N;i++){
        sequenceLength=0;
        num=0;
        int foundRemainders[i],j;
        for(j=0;j<i;j++){
            foundRemainders[j]=0;
        }
        int value=1;
        int position=0;

        while(foundRemainders[value]==0 && value!=0){
            foundRemainders[value]=position;
            value*=10;
            value%=i;
            position++;
        }
        if(value!=0){
            num=i;
            sequenceLength = position - foundRemainders[value];
        }
        long_rec[i][0]=i;
        long_rec[i][1]=sequenceLength;
        if(sequenceLength <= long_rec[i-1][1]){
            long_rec[i][0]=long_rec[i-1][0];
            long_rec[i][1]=long_rec[i-1][1];
        }
    }
}
int main() {
    int i,t,N;
    long_rec[0][0]=0;
    long_rec[1][0]=1;
    long_rec[0][1]=0;
    long_rec[1][1]=0;
    fillLongRec(10000);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        printf("%d\n",long_rec[N-1][0]);
    }
    return 0;
}
