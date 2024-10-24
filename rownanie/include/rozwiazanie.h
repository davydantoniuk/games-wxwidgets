#ifndef ROZWIAZANIE_H
#define ROZWIAZANIE_H
#include <string>
using namespace std;

class rozwiazanie
{
    public:
        rozwiazanie(string wzor , string lewy , string prawy);
        bool OK();
        string komunikat();
    private:
        string wzor;
        string lewy;
        string prawy;
        bool __OK = false;
        string __komunikat = "komunikat testowy";

};
double f_wzor(double x);
bool bisekcja(double f(double), double a, double b, double & mz);
#endif // ROZWIAZANIE_H














