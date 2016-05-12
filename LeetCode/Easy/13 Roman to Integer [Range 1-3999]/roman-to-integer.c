int romanToInt(char* s) {
    int number=0,i=0;
    while(s[i])
    {
        int value = 0;
        switch (s[i])
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
        int value1 = 0;
        switch (s[i+1])
        {
            case 'I':
                value1 = 1;
                break;
            case 'V':
                value1 = 5;
                break;
            case 'X':
                value1 = 10;
                break;
            case 'L':
                value1 = 50;
                break;
            case 'C':
                value1 = 100;
                break;
            case 'D':
                value1 = 500;
                break;
            case 'M':
                value1 = 1000;
                break;
            case '0':
                value1 = 0;
                break;
            default:
                value1 = -1;
        }
        if(value>=value1)
            number+=value;
        else
        {
            number+=(value1-value);
            i++;
        }
        i++;
    }
    return number;
}
