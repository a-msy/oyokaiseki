#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define S 0.693147180
#define a 0
#define b 1

double f(double x){
    double y;
    //y=(1/x/x)+(3/x/x/x/x/x/x);
    y=1/(x+1);
    return y;
}

void daikei(){
    int i,n,m;
    double S1,xi,yi,y0,yn,h;

    for(m=2;m<=16;m*=2){
        n=m;
        y0=f(a);
        yn=f(b);
        h=fabs(b-a)/n;
        S1=(y0+yn)/2.0;//最初と最後の項を計算しとく

        for(i=1;i<n;i++){//残りの項を足していく
            xi=a+h*i;//１つ隣へ
            yi=f(xi);
            S1+=yi;
        }
        S1=S1*h;
        printf("n=%d\nS1=%11.8f\n",m,S1);
        printf("|S1-S|=%11.8f\n\n",fabs(S1-S));

    }
}
void sympthon(){
    int i,n,m;
    double S1,xi,yi,y0,yn,h;

    for(m=2;m<=16;m*=2){
        n=m;
        y0=f(a);
        yn=f(b);
        h=fabs(b-a)/n;
        S1=(y0+yn);

        for(i=1;i<n/2;i++){//繰り返しはn/2まで
            xi=a+h*2*i;//二つ隣まで
            yi=4*f(xi-h)+2*f(xi);//公式4*F_1+2*F_2+4*F_3+...+2*F_n-1
            S1=S1+yi;
        }
        S1=S1+4*f(b-h);//4*F_n-1項目
        S1=h*S1/3;
        printf("n=%d\nS1=%11.8f\n",m,S1);
        printf("|S1-S|=%11.8f\n\n",fabs(S1-S));
    }
}

int main(int argc, char *argv[]){
    printf("/*daikei*/\n");
    daikei();
    printf("/*sympthon*/\n");
    sympthon();
    return 0;
}
