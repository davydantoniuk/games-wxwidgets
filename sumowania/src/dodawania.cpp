#include "dodawania.h"
#include <fstream>
#include <string>
#include <sstream>
dodawania::dodawania(string path,bool skip_first_row,bool skip_first_col)
{
    if(path=="jeszce nie wybrany...")
    {
        __OK=false;
    }
    else
    {
        ifstream inputFile(path);
        if (!inputFile.is_open())
        {
            __OK=false;
            return;
        }

        sum = 0;
        string number;

        int row = 0;
        int col = 0;
        string line;
        while (getline(inputFile, line))
        {
            if (!skip_first_row || (row > 0))
            {
                stringstream lineStream(line);
                col = 0;
                while (lineStream >> number)
                {
                    if (!skip_first_col || (col > 0))
                    {
                        try {
                        sum += stod(number);
                        } catch(...) {};
                    }
                    col++;
                }
            }

        row++;
        }
        inputFile.close();
        __OK=true;
    }
}

int dodawania::wynik(){
    return sum;
}

dodawania::~dodawania()
{
    //dtor
}

bool dodawania::OK(){
    return __OK;
}

