#include "rozwiazanie.h"
#include "fparser.hh"
#include <cmath>
#include <string>

FunctionParser fp;
double f_wzor(double x){
    double t[]={x};
    double y=fp.Eval(t);
    if(fp.EvalError()==0)
        return y;
    return NAN;
}

rozwiazanie::rozwiazanie(string wzor , string lewy , string prawy)
{
    double xl, xp;
    try{
        xl=stod(lewy);
    }
    catch(...){
        __OK=false;
        __komunikat="zly lewy koniec";
        return;
    }

    try{
        xp=stod(prawy);
    }
    catch(...){
        __OK=false;
        __komunikat="zly prawy koniec";
        return;
    }

    if(fp.Parse(wzor,"x")!=-1){
        __komunikat = "nieprawidlowo wprowadzony wzor funkcji";
        __OK = false;
        return;
    }

    double xodp;
    if (bisekcja(f_wzor, xl, xp, xodp)) {
        __komunikat = "Miejsce zerowe to " + to_string(xodp);
        __OK=true;
    } else {
        __komunikat = "Nieprawidlowy przedzial dla tej funkcji";
    }

}

bool rozwiazanie::OK(){
    return __OK;
}

string rozwiazanie::komunikat(){
    return __komunikat;
}

bool bisekcja(double f(double), double a, double b, double & mz) {
    double fa = f(a);
    if (!isfinite(fa))
        return false;
    double fb = f(b);
    if (!isfinite(fb))
        return false;
    if (fa*fb > 0)
        return false;
    while (fabs(b-a) >= 1e-12) {
        double s = (a+b)/2;
        double fs = f(s);
        if (!isfinite(fs))
            return false;
        if (fa * fs <=0) {
            b = s;
            fb = fs;
        }
        else {
            a=s;
            fa = fs;
        }
    }
    mz = (a+b) / 2;
    return true;
}

