#include<stdio.h>
#include<stdlib.h>

int ind[1000001];

int abso(int a){
    return a>0?a:-a;
}

int main(){
    int t,n,m,i,j,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&m);
                ind[m-1]=i*n+j;
            }
        }
        int r=ind[0]/n;
        int c=ind[0]%n;
        int row,col;
        for(i=0;i<n*n/2;i++){
            row=ind[n*n-1-i]/n;
            col=ind[n*n-1-i]%n;
            k-=abso(col-c)+abso(row-r);
            r=row;
            c=col;
            if(n%2==0 && i==n*n/2-1){
                break;
            }
            row=ind[i+1]/n;
            col=ind[i+1]%n;
            k-=abso(col-c)+abso(row-r);
            r=row;
            c=col;
        }
        if(k>=0){
            printf("ALIVE\n");
        }
        else{
            printf("DEAD\n");
        }
    }
    return 0;
}
