#include <math.h>
#include <stdio.h>

//* THIS PROGRAM GETS THE MISSING VARIABLE OF AN EQUATION FOR CALCULATING REMAINING DEBT, THEN FIND IT. IF THE LAST VARIABLE IS MISSING,
// WE APPLY NEWTON-RAPHSON METHOD, WHICH STARTS BY BASICLY APPROXIMATING THAT VALUE.**//
// the variable l,n,p,r stands for borrowed money loan, month, monthly payment and monthly interest rate
// the equation used for remaining dept calculation is e^n*L −(e^n-1/(e-1))*p=0

int missing;
float n;
double e,l,p,r,a;
double old,nw,fark;

int main()
{   //L,n,p,r

    scanf("%i",&missing);
    if (missing==1){
        scanf(" %f %lf %lf", &n, &p, &r);
        e=1+r;
        l=((pow(e,n)-1)/r)*p/pow(e,n);
        printf("%.16f", l);
    }
    else if (missing==2){
        scanf(" %lf %lf %lf", &l, &p, &r);
        e=1+r;
        a=(double)log(l*(e-1)/(p-l*(e-1))+1)/log(e); // it is allowed thath n may be printed as double
        printf("%.16f", a);
    }
    else if (missing==3){
        scanf(" %lf %f %lf", &l, &n, &r);
        e=1+r;
        p=pow(e,n)*l*(e-1)/(pow(e,n)-1);
        printf("%.16f", p);
    }
    else if (missing==4){
        scanf(" %lf %f %lf", &l, &n, &p);
        old=1.0;
        nw=old-(pow((1+old),n)*l-((pow((1+old),n)-1)*p/old))/(l*n*pow((1+old),(n-1))-(p/pow(old,2))*(n*pow((1+old),(n-1))*old-(pow((1+old),n)-1)));
        fark=abs(nw-old);
        while (fark>=0.00001){ //precision wanted as 10^-5
                old=nw;
                nw=nw-(pow((1+nw),n)*l-((pow((1+nw),n)-1)*p/nw))/(l*n*pow((1+nw),(n-1))-(p/pow(nw,2))*(n*pow((1+nw),(n-1))*nw-(pow((1+nw),n)-1)));
                fark=abs(nw-old);}
        r=nw;
        printf("%.16f\n", r);
    }
    return 0;
}
