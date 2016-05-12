void reverse(char *begin, char *end, char *t){
  char temp,*te=end,*tb=begin;
  while(begin<end){
    temp=*begin;
    *begin++=*end;
    *end--=temp;
  }
  while(tb<=te){
    *t++=*tb++;
  }
}

void reverseWords(char* s){
    char *temp=s,*word_begin=NULL;
    char *t=s;
    while(*temp){
        if(word_begin==NULL && *temp!=' '){
            word_begin=temp;
        }
        if(word_begin &&(*(temp+1)==' ' || *(temp+1)=='\0')){
            reverse(word_begin,temp,t);
            if(*(temp+1)==' '){
                t+=temp-word_begin+1;
                *t=' ';
                t++;
            }
            else{
                t+=temp-word_begin+1;
                *t='\0';
            }
            word_begin=NULL;
        }
        temp++;
    }
    if(*(t-1)==' '){
        *(t-1)='\0';
        t--;
    }
    reverse(s,t-1,s);
}
