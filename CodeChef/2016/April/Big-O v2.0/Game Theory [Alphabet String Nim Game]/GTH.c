#include<stdio.h>

int main(){
	int t,i;
	char names[2][12]={"Tarun","Varun"};
	char name[12],str[102];
	scanf("%d",&t);
	while(t--){
		scanf("%s%s",name,str);
		int arr[26]={},sum=0;
		for(i=0;str[i];i++){
			arr[str[i]-'a']++;
		}
		for(i=0;i<26;i++){
			sum^=arr[i];
		}
		int mark=0;
		if(name[0]=='V'){
			mark=1;
		}
		if(sum==0){
			printf("%s\n",names[(mark+1)%2]);
		}
		else{
			printf("%s\n",names[mark]);
		}
	}
	return 0;
}