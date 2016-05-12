int val(char ch){
    int value = 0;
    switch (ch)
    {
        case 'I':
            value = 1;
            break;
        case 'V':
            value = 5;
            break;
        case 'X':
            value = 10;
            break;
        case 'L':
            value = 50;
            break;
        case 'C':
            value = 100;
            break;
        case 'D':
            value = 500;
            break;
        case 'M':
            value = 1000;
            break;
        case '0':
            value = 0;
            break;
        default:
            value = -1;
    }
    return value;
}
int romanToInt(char* A) {
    int number=0,i=0;
    while(A[i])
    {
        if(val(A[i])>=val(A[i+1]))
            number+=val(A[i]);
        else
        {
            number+=(val(A[i+1])-val(A[i]));
            i++;
        }
        i++;
    }
    return number;
}
