#include<stdio.h>
#include<math.h>

int main(){
    const double err=0.000001;
    double x[3],y[3],dx[3],dy[3];
    int i,j,k,n;
    for(i=0;i<3;i++){
        scanf("%lf%lf",&x[i],&y[i]);
    }
    x[1]-=x[0];
    x[2]-=x[0];
    x[0]=0;
    y[1]-=y[0];
    y[2]-=y[0];
    y[0]=0;
    double cx=(y[2]*(x[1]*x[1]+y[1]*y[1])-y[1]*(x[2]*x[2]+y[2]*y[2]))/(x[1]*y[2]-x[2]*y[1])/2;
    double cy=(x[2]*(x[1]*x[1]+y[1]*y[1])-x[1]*(x[2]*x[2]+y[2]*y[2]))/(x[2]*y[1]-x[1]*y[2])/2;
    for(i=0;i<3;i++){
        dx[i]=x[i]-cx;
        dy[i]=y[i]-cy;
    }
    double sin_t1=(dx[0]*dy[1]-dx[1]*dy[0])/(dx[0]*dx[0]+dy[0]*dy[0]);
    double sin_t2=(dx[0]*dy[2]-dx[2]*dy[0])/(dx[0]*dx[0]+dy[0]*dy[0]);
    double cos_t1=(dx[0]*dx[1]+dy[0]*dy[1])/(dx[0]*dx[0]+dy[0]*dy[0]);
    double cos_t2=(dx[0]*dx[2]+dy[0]*dy[2])/(dx[0]*dx[0]+dy[0]*dy[0]);

    for(n=3;n<=100;++n){
        for(i=1;i<n;++i){
            if(fabs(sin_t1-sin(2*M_PI/n*i))>err || fabs(cos_t1-cos(2*M_PI/n*i))>err){
                continue;
            }
            for(j=1;j<n;++j){
                if(fabs(sin_t2-sin(2*M_PI/n*j))>err || fabs(cos_t2-cos(2*M_PI/n*j))>err){
                    continue;
                }
                printf("%lf\n", (dx[0]*dx[0]+dy[0]*dy[0])*sin(2*M_PI/n)*n/2);
                return 0;
            }
        }
    }
    return 0;
}
