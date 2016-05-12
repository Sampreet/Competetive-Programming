#define false 0
#define true 1
typedef int bool;

bool palinInt(int A){
    if(A<0){
        return false;
    }
    int rem,div=1;
    while(A/div>=10){
        div*=10;
    }
    while(A!=0){
        if(A/div!=A%10){
            return false;
        }
        A%=div;
        A/=10;
        div/=100;
    }
    return true;
}
