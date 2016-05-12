#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	printf("%d %d",t%7==6?2*(t/7)+1:2*(t/7),t%7>2?2*(t/7)+2:2*(t/7)+t%7);
	return 0;
}
