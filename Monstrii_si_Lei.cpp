#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <sstream>

using namespace std;

#define N 867   //nr cast total
#define NA 54   //nr actori
#define NF 132  //nr figuranti
#define NC 735 //nr cast initial

class Costuri
{
    protected:
        int c_vamp = 230;
        int c_var = 555;
        int c_sir =345;
        int c_clar= 157;
        int c_om = 55;
        int c_orice = 40;
        int c_veg = 33;
        int c_flex = 46;

        int vamp, var, sir, clar, om;
        int orice, veg, flex;
    
    public:
        void Apetit();
        void Machiaj();
        void updateCSV(int rollnum, int index, string nou);
};

void Costuri::Apetit()
{
    int a=0,b=0,c=0;
    int random;
    int rollnum=1;

    for(int i = 1; i <= N; i++)
    {
        random = rand() % 3;

        if(random == 0)
        {
            a++;
            updateCSV(rollnum, 2, "Apt sa manance orice");
        }
        else if(random == 1)
        {
            b++;
            updateCSV(rollnum, 2, "Vegetarian");
        }
        else if(random == 2)
        {
            c++;
            updateCSV(rollnum, 2, "Flexitarian");
        }
        rollnum++;
    }

    this->orice = a;
    this->veg = b;
    this->flex = c;

}

void Costuri::Machiaj()
{
    int a=0,b=0,c=0,d=0,e=0;
    int random;
    int rollnum=1;

    for(int i = 1; i <= NA; i++)
    {
        random = rand() % 5;

        if(random == 0)
        {
            a++;
            updateCSV(rollnum, 3, "Vampir");
        }
        else if(random == 1)
        {
            b++;
            updateCSV(rollnum, 3, "Varcolac");
        }
        else if(random == 2)
        {
            c++;
            updateCSV(rollnum, 3, "Sirena");
        }
        else if(random == 3)
        {
            d++;
            updateCSV(rollnum, 3, "Clarvazator");
        }
        else if(random == 4)
        {
            e++;
            updateCSV(rollnum, 3, "Om");
        }
        rollnum++;
    }

    rollnum = 736;

    for(int i = 1; i <= N; i++)
    {
        random = rand() % 5;

        if(random == 0)
        {
            a++;
            updateCSV(rollnum, 3, "Vampir");
        }
        else if(random == 1)
        {
            b++;
            updateCSV(rollnum, 3, "Varcolac");
        }
        else if(random == 2)
        {
            c++;
            updateCSV(rollnum, 3, "Sirena");
        }
        else if(random == 3)
        {
            d++;
            updateCSV(rollnum, 3, "Clarvazator");
        }
        else if(random == 4)
        {
            e++;
            updateCSV(rollnum, 3, "Om");
        }
        rollnum++;
    }

    this->vamp = a;
    this->var = b;
    this->sir = c;
    this->clar = d;
    this->om = e;
}

void Costuri::updateCSV(int rollnum, int index, string nou)
{
	fstream fin, fout;

	fin.open("wednesdayCast.csv", ios::in);

	fout.open("wednesdayCastnew.csv", ios::out);

	int roll1 = 0, count = 0, i;
	string line, word;
	vector<string> row;

	while (!fin.eof())
    {

		row.clear();

		getline(fin, line);
		stringstream s(line);

		while (getline(s, word, ','))
        {
			row.push_back(word);
		}

		roll1++;
		int row_size = row.size();

		if (roll1 == rollnum)
        {
			row[index] = nou;

			if (!fin.eof())
            {
				for (i = 0; i < row_size - 1; i++)
                {
					fout << row[i] << ",";
				}

				fout << row[row_size - 1] << "\n";
			}
		}
		else
        {
			if (!fin.eof())
            {
				for (i = 0; i < row_size - 1; i++)
                {
					fout << row[i] << ",";
				}
				fout << row[row_size - 1] << "\n";
			}
		}
		if (fin.eof())
			break;
	}

	fin.close();
	fout.close();

	remove("wednesdayCast.csv");
	rename("wednesdayCastnew.csv", "wednesdayCast.csv");
}

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

void addToCSV(string name, string surname)
{
    fstream fout;

    fout.open("wednesdayCast.csv", ios::out | ios::app);

    fout << name << " " << surname << "," << "extra" << ", , " << "\n";

    fout.close();
}

void addExtra()
{
    int length;
    string name, surname;

    for(int i = 1; i <= 132; i++)
    {
        length = 4 + (rand() % 7);
        name = randomName(length);
        name[0] = toupper(name[0]);

        length = 4 + (rand() % 7);
        surname = randomName(length);
        surname[0] = toupper(surname[0]);
        
        addToCSV(name,surname);
    }
}

int Autocare()
{
    int nr_autocare, autocare;

    nr_autocare = N / 50;

    try
    {
        if(nr_autocare < ((float)N/50.0))
        {
            throw nr_autocare;
        }
    }
    catch(int nr_autocare)
    {
        autocare = nr_autocare + 1;
    }

    return autocare;
}

int main()
{
    srand (time(NULL));

    addExtra();

    Costuri pret;
    pret.Apetit();
    pret.Machiaj();

    /*int nr_autocare, cost_autocare;
    int cost_machiaj;

    nr_autocare = Autocare();
    cost_autocare = nr_autocare * 5680;
    cout << cost_autocare << endl;

    cost_machiaj = Monstri();
    cout << cost_machiaj << endl;*/

    return 0;
}