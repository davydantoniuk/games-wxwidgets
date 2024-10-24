#ifndef DODAWANIA_H
#define DODAWANIA_H
#include <iostream>
#include <string>
using namespace std;

class dodawania
{
    public:
        dodawania(string path,bool skip_first_row,bool skip_first_col);
        virtual ~dodawania();
        bool OK();
        int wynik();
    protected:

    private:
        string path;
        int sum;
        bool skip_first_row=false;
        bool skip_first_col=false;
        bool __OK = false;
};

#endif // DODAWANIA_H
