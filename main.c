#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define S 1.08125000
#define a 1
#define b 2

double f(double x){
    double y;
    y=(1/x/x)+(3/x/x/x/x/x/x);
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
void Romberg(){
    int n;
    double h,T1,s,m,c,k,i,j,x,t,Tj;
    c=log2(16.0);

    n=1; 
    h=b-a;
    T1=h*(f(a)+f(b))/2;//T1=I(n);
    printf("I_1(%2d)=%11.8f\n",n,T1);

    for(k=1;k<=c;k++){
        s=0;
        for(i=1;i<=n;i++){
            x=a+(i-0.5)*h;
            s=s+f(x);
        }
        s=(T1+h*s)/2;//s=I_1(n)
        h=h/2;//幅半分
        n=n*2;//分割数２倍
        printf("I_1(%2d)=%11.8f  ",n,s);

        m=1;
        for(j=1;j<=k;j++){
            t=T1;
            T1=s;
            m=m*4;
            s=(m*s-t)/(m-1);//I_j+1(n);
            printf("I_%1.0f(%2d)=%11.8f  ",j+1,n,s);
        }
        T1=s;
        printf("\n");
    }
    return;
}
int main(int argc, char *argv[]){
    printf("/*daikei*/\n");
    daikei();
    printf("/*sympthon*/\n");
    sympthon();
    printf("/*Romberg*/\n");
    Romberg();
    return 0;
}