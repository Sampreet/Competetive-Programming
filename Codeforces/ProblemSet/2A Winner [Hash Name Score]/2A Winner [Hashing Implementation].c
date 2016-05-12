#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HM 107

struct dict{
    char name[34];
    int points[1000];
    int sum;
    int index[1000];
    int total;
};

struct table{
    struct dict *D;
    int entry;
};

int hash(char *name){
    int i=0;
    int sum=0;
    while(name[i]){
        sum=(sum*13+name[i]-'a')%HM;
        i++;
    }
    return sum%HM;
}

void addEntry(char *name, int a, int ind, struct table *T){
    int hashval=hash(name);
    int i;
    for(i=0;i<T[hashval].entry;i++){
        if(strcmp(name,T[hashval].D[i].name)==0){
            T[hashval].D[i].sum+=a;
            T[hashval].D[i].points[T[hashval].D[i].total]=a;
            T[hashval].D[i].index[T[hashval].D[i].total]=ind;
            T[hashval].D[i].total++;
            return;
        }
    }
    T[hashval].entry++;
    int entry=T[hashval].entry;
    if(entry==1){
        T[hashval].D=(struct dict*)malloc(entry*sizeof(struct dict));
    }
    T[hashval].D=realloc(T[hashval].D,entry*sizeof(struct dict));
    strcpy(T[hashval].D[entry-1].name,name);
    T[hashval].D[entry-1].total=1;
    T[hashval].D[entry-1].index[0]=ind;
    T[hashval].D[entry-1].points[0]=a;
    T[hashval].D[entry-1].sum=a;
}

int main(){
    int t,i,j,k,a;
    char str[34];
    struct table *T=(struct table *)malloc(HM*sizeof(struct table));
    for(i=0;i<HM;i++){
        T[i].entry=0;
    }
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s%d",str,&a);
        addEntry(str,a,i,T);
    }
    int max_p=-1,min_i=t;
    for(i=0;i<HM;i++){
        for(j=0;j<T[i].entry;j++){
            if(max_p<T[i].D[j].sum){
                max_p=T[i].D[j].sum;
            }
        }
    }
    for(i=0;i<HM;i++){
        for(j=0;j<T[i].entry;j++){
            int sum=0;
            for(k=0;k<T[i].D[j].total;k++){
                sum+=T[i].D[j].points[k];
                if(sum>=max_p){
                    if(T[i].D[j].index[k]<min_i && T[i].D[j].sum==max_p){
                        strcpy(str,T[i].D[j].name);
                        min_i=T[i].D[j].index[k];
                    }
                    break;
                }
            }
        }
    }
    printf("%s\n",str);
    return 0;
}
