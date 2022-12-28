#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>

using namespace std;

string randomName(int length)
{
    char consonents[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
    char vowels[] = {'a','e','i','o','u','y'};

    string name = "";

    
    int random = rand() % 2;
    int count = 0;

    for(int i = 0; i < length; i++)
    {

        if(random < 2 && count < 2)
        {
            name = name + consonents[rand() % 19];
            count++;
        }
        else
        {
            name = name + vowels[rand() % 5];
            count = 0;
        }

        random = rand() % 2;

    }

    return name;
}

void addExtra(string name, string surname)
{
    fstream fout;

    fout.open("wednesdayCast.csv", ios::out | ios::app);

    fout << name << " " << surname << "," << "extra" << "\n";

    fout.close();
}

int main()
{
    int length;
    string name, surname;
    srand (time(NULL));

    for(int i = 1; i <= 132; i++)
    {
        length = 4 + (rand() % 7);
        name = randomName(length);
        name[0] = toupper(name[0]);

        length = 4 + (rand() % 7);
        surname = randomName(length);
        surname[0] = toupper(surname[0]);
        
        addExtra(name,surname);
    }

    return 0;
}