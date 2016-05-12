#include<stdio.h>
#include<string.h>

int arr[26];
char str[1005];

void lapin(int i,int j){
    while(i>=0){
        arr[str[i]-'a']++;
        arr[str[j]-'a']--;
        i--;
        j++;
    }
    for(i=0;i<26;i++){
        if(arr[i]!=0){
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    return;
}

int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        for(i=0;i<26;i++){
            arr[i]=0;
        }
        scanf("%s",str);
        j=strlen(str);
        if(j==1){
            printf("NO\n");
            continue;
        }
        if(j%2==0){
            lapin(j/2-1,j/2);
        }
        else{
            lapin(j/2-1,j/2+1);
        }
    }
    return 0;
}
