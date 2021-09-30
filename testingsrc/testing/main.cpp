#include <iostream>
#include <string>
#include <vector>
#include "../../src/SzoftMod/calcmodule.h"

int main()
{
    #ifdef _WIN32
    system("chcp 65001");//ékezetek FIX windowson
    system("cls");
    #endif

    std::string str;
    while(std::getline(std::cin, str))
    {
        try {
            std::vector<char> inVectr;
            for(char myChar : str)
            {
                inVectr.push_back(myChar);
            }
            std::cout<<"Eredmény= "<<calculate(inVectr)<<std::endl;
        }
        catch (std::string errorText) {
            std::cout<<std::endl<<"Error: "<<errorText<<std::endl;
        }
        catch (const char* err) {
            std::cout<<std::endl<<"Error: "<<err<<std::endl;
        }
        catch (std::vector<char> errorVect) {
            std::string koztesString(errorVect.begin(), errorVect.end());
            std::cout<<std::endl<<"Error: "<<koztesString<<std::endl;
        }
    }
    return 0;
}
