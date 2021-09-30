#include <iostream>
#include <string>
#include <vector>
#include "../../src/SzoftMod/calcmodule.h"

int main(int argc, char** argv)
{
    #ifdef _WIN32
    system("chcp 65001");//ékezetek FIX windowson
    system("cls");
    #endif

    if(argc > 2) std::cout<<"Túl sok a paraméter"<<std::endl;

    else if(argc == 2) //ha 1 darab paraméter van
    {
        try{
            std::vector<char> inVectr;
            std::string myArg = argv[1];
            for(char MyChar : myArg)
            {
                inVectr.push_back(MyChar);
            }
            std::cout<<calculate(inVectr)<<std::endl;
        }
        catch (const char* err) {
            std::cout<<"Error: "<<err<<std::endl;
        }
    }

    else // ha nincs paraméter akkor végtelen olvas
    {
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
    }
    return 0;
}
