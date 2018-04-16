//
//  main.cpp
//  pesel_validator
//
//  Created by Adam Stanislawski on 26.02.2018.
//  Copyright © 2018 Adam Stanislawski. All rights reserved.
//

#include <iostream>

#define PESEL_LENGTH 11

int main(int argc, const char * argv[]) {

    int n[4] = {9,7,3,1};
    char pesel[50];
    char rok[5];
    char miesiac[3];
    char dzien[3];
    char plec;
    bool error = 0;
    std::cout << "Podaj PESEL: ";
    std::cin >> pesel;
    
    int suma = 0;
    
    if(strlen(pesel) == PESEL_LENGTH)
    {
        rok[0] = '1';
        rok[1] = '9';
        rok[2] = pesel[0];
        rok[3] = pesel[1];
        
        for(int i = 0; i < PESEL_LENGTH-1; i++)
        {
            suma+=(pesel[i]-'0')*n[i%4];
        }
        if(suma%10 != (pesel[10] - '0'))
        {
            error = 1;
            std::cout << "Błędna cyfra kontrolna! (" << suma%10 << ")\n";
        }
        
        miesiac[0] = pesel[2];
        miesiac[1] = pesel[3];
        
        
        if(std::stoi(miesiac) > 0 && std::stoi(miesiac) <= 12 )
        {
            rok[0] = '1';
            rok[1] = '9';
        }
        else if(std::stoi(miesiac) > 20 && std::stoi(miesiac) <= 32 )
        {
            rok[0] = '2';
            rok[1] = '0';
        }
        else if(std::stoi(miesiac) > 40 && std::stoi(miesiac) <= 52 )
        {
            rok[0] = '2';
            rok[1] = '1';
        }
        else if(std::stoi(miesiac) > 60 && std::stoi(miesiac) <= 72 )
        {
            rok[0] = '2';
            rok[1] = '2';
        }
        else if(std::stoi(miesiac) > 80 && std::stoi(miesiac) <= 92 )
        {
            rok[0] = '1';
            rok[1] = '8';
        }
        else
        {
            error = 1;
            std::cout << "Błędny miesiąc\n";
        }
        
        dzien[0] = pesel[4];
        dzien[1] = pesel[5];
        
        if(std::stoi(dzien) > 31)
        {
            error = 1;
            std::cout << "Błędny dzień\n";
        }
        
        
        if((pesel[9] - '0') % 2 == 0)
        {
            plec = 'k';
        } else plec = 'm';
        
        if(!error)
        {
            std::cout << "Data urodzenia: " << dzien << "." << miesiac << "." << rok << "\n";
            std::cout << "Płeć: " << ((plec == 'k') ? "kobieta" : "mężczyzna") << "\n";
        }
        
    } else std::cout << "Błędna długość PESEL\n";
    
    
    
    return 0;
}
