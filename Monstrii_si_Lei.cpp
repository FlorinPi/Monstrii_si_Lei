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

class Preturi
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
        int c_autocar = 5680;
        int c_2p = 350;
        int c_3p = 420;
        int c_castel = 10000;

    public:
        virtual void CSV() = 0;
};

class Costuri : public Preturi
{
    protected:
        int vamp, var, sir, clar, om;
        int orice, veg, flex;
        int autocar, machiaj, mancare, cazare, lichide;
        int c30, c45, c60, c100;
    
    public:
        Costuri(){};
        ~Costuri(){};

        void Apetit();
        void Machiaj();
        void Autocare();
        void Cazare();
        void Lichide();
        void Castel();
        void Dolari(float curs);
        void CSV();
        void CSV(int rollnum, int index, string nou);
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
            CSV(rollnum, 2, "Apt sa manance orice");
        }
        else if(random == 1)
        {
            b++;
            CSV(rollnum, 2, "Vegetarian");
        }
        else if(random == 2)
        {
            c++;
            CSV(rollnum, 2, "Flexitarian");
        }
        rollnum++;
    }

    this->orice = a;
    this->veg = b;
    this->flex = c;

    this->mancare = orice*c_orice + veg*c_veg + flex*c_flex;
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
            CSV(rollnum, 3, "Vampir");
        }
        else if(random == 1)
        {
            b++;
            CSV(rollnum, 3, "Varcolac");
        }
        else if(random == 2)
        {
            c++;
            CSV(rollnum, 3, "Sirena");
        }
        else if(random == 3)
        {
            d++;
            CSV(rollnum, 3, "Clarvazator");
        }
        else if(random == 4)
        {
            e++;
            CSV(rollnum, 3, "Om");
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
            CSV(rollnum, 3, "Vampir");
        }
        else if(random == 1)
        {
            b++;
            CSV(rollnum, 3, "Varcolac");
        }
        else if(random == 2)
        {
            c++;
            CSV(rollnum, 3, "Sirena");
        }
        else if(random == 3)
        {
            d++;
            CSV(rollnum, 3, "Clarvazator");
        }
        else if(random == 4)
        {
            e++;
            CSV(rollnum, 3, "Om");
        }
        rollnum++;
    }

    this->vamp = a;
    this->var = b;
    this->sir = c;
    this->clar = d;
    this->om = e;

    this->machiaj = vamp*c_vamp + var*c_var + sir*c_sir + clar*c_clar + om*c_om;
}

void Costuri::Autocare()
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

    this->autocar = autocare * c_autocar * 2;
}

void Costuri::Cazare()
{
    int nr_camere2, camere2, nr_camere3;

    nr_camere2 = NC / 2;
    nr_camere3 = NF / 3;

    try
    {
        if(nr_camere2 < ((float)N/2.0))
        {
            throw nr_camere2;
        }
    }
    catch(int nr_camere2)
    {
        camere2 = nr_camere2 + 1;
    }

    this->cazare = camere2*c_2p + nr_camere3*c_3p;
}

void Costuri::Lichide()
{
    this->lichide = N * (3 + 0.5 * 30 + 0.8 * 4);
}

void Costuri::Castel()
{
    int c10;

    c10 = (c_castel*10)*0.98;

    this->c30 = c10 * 3;
    this->c45 = c10 * 4 + c_castel * 5;
    this->c60 = c10 * 6;
    this->c100 = c10 * 10;
}

void Costuri::Dolari(float curs)
{
    this->autocar = this->autocar * curs;
    this->cazare = this->cazare * curs;
    this->machiaj = this->machiaj * curs;
    this->mancare = this->mancare * curs;
    this->lichide = this->lichide * curs;
    this->c30 = this->c30 * curs;
    this->c45 = this->c45 * curs;
    this->c60 = this->c60 * curs;
    this->c100 = this->c100 * curs;
}

void Costuri::CSV()
{
    fstream fout;

    fout.open("Costuri.csv", ios::out | ios::app);

    fout << "Perioada" << "," << "30 Zile" << "," << "45 Zile" << "," << "60 Zile" << "," << "100 Zile" << "\n";
    fout << "Transport" << "," << autocar << "," << autocar << "," << autocar << "," << autocar << "\n";
    fout << "Cazare" << "," << cazare*30 << "," << cazare*45 << "," << cazare*60 << "," << cazare*100 << "\n";
    fout << "Machiaj" << "," << machiaj*30 << "," << machiaj*45 << "," << machiaj*60 << "," << machiaj*100 << "\n";
    fout << "Mancare si apa" << "," << (mancare+lichide)*30 << "," << (mancare+lichide)*45 << "," << (mancare+lichide)*60 << "," << (mancare+lichide)*100 << "\n";
    fout << "Inchiriere spatiu" << "," << c30 << "," << c45 << "," << c60 << "," << c100 << "\n";

    fout.close();
}

void Costuri::CSV(int rollnum, int index, string nou)
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



int main()
{
    srand (time(NULL));

    addExtra();

    Costuri pret;
    pret.Autocare();
    pret.Cazare();
    pret.Machiaj();
    pret.Apetit();
    pret.Lichide();
    pret.Castel();
    pret.Dolari(0.216);
    pret.CSV();

    return 0;
}