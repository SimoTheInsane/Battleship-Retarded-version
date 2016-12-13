#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

bool sprawdzanie(int Statki[11][11], int pion, int poziom)
{
    if ((Statki[pion][poziom] == 0) &&
         ((Statki[pion+1][poziom] == 0) ||
          (pion == 10)) &&
        ((Statki[pion][poziom+1] == 0) ||
         (poziom == 10)) &&
        ((Statki[pion-1][poziom] == 0) ||
         (pion == 1)) &&
        ((Statki[pion][poziom-1] == 0) ||
         (poziom == 1)))
         return true;
         else
            return false;
}

void szyfrowanie(int Statkigracza[11][11], int Statkikomputera[11][11])
{
    ofstream zapis;
    zapis.open("save.txt");
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++)
        {
            if (Statkigracza[i][j]==0)
            {
                zapis << 0 << 0;
            }
            if (Statkigracza[i][j]==1)
            {
                zapis << 0 << 1;
            }
            if (Statkigracza[i][j]==-1)
            {
                zapis << 1 << 1;
            }
            if (Statkigracza[i][j]==-2)
            {
                zapis << 1 << 0;
            }
        }
        for (int j=1;j<=10;j++)
        {
            if (Statkikomputera[i][j]==0)
            {
                zapis << 0 << 0;
            }
            if (Statkikomputera[i][j]==1)
            {
                zapis << 0 << 1;
            }
            if (Statkikomputera[i][j]==-1)
            {
                zapis << 1 << 1;
            }
            if (Statkikomputera[i][j]==-2)
            {
                zapis << 1 << 0;
            }
        }
    }
    zapis.close();
}

void wczytywanie(int Statkigracza[11][11], int Statkikomputera[11][11], int Statkipomoc[11][11])
{
    char szyfr[2];
    ifstream odczyt;
    odczyt.open("save.txt");
    for(int i=1;i<=10;i++)
    {
        for (int j=1;j<=10;j++)
        {
            for (int k=0; k<=1; k++)
            {
                odczyt >> szyfr[k];
            }
            if (szyfr[0]=='0')
            {
                if(szyfr[1] == '0')
                {
                    Statkigracza[i][j]=0;
                }
                if(szyfr[1] == '1')
                {
                    Statkigracza[i][j]=1;
                }
            }
            if (szyfr[0]=='1')
            {
                if(szyfr[1]=='0')
                {
                    Statkigracza[i][j]=-2;
                }
                if(szyfr[1]=='1')
                {
                    Statkigracza[i][j]=-1;
                }
            }
        }
        for (int j=1;j<=10;j++)
        {
            for (int k=1; k<=2; k++)
            {
                odczyt >> szyfr[k];
            }
            if (szyfr[0]=='0')
            {
                if(szyfr[1] == '0')
                {
                    Statkikomputera[i][j]=0;
                }
                if(szyfr[1] == '1')
                {
                    Statkikomputera[i][j]=1;
                }
            }
            if (szyfr[0]=='1')
            {
                if(szyfr[1]=='0')
                {
                    Statkikomputera[i][j]=-2;
                }
                if(szyfr[1]=='1')
                {
                    Statkikomputera[i][j]=-1;
                }
            }
            if (Statkikomputera[i][j] == -1)
            {
                Statkipomoc[i][j]=Statkikomputera[i][j];
            }
            if (Statkikomputera[i][j] == -2)
            {
                Statkipomoc[i][j]=Statkikomputera[i][j];
            }
        }
    }
    odczyt.close();
}

void strzal(int Statki[11][11], int pion, int poziom)
{
    Statki[pion][poziom]=Statki[pion][poziom]-2;
    if (Statki[pion][poziom] == -2)
    {
        cout <<"Pudlo!"<< endl;
    }
    else
    {
        cout <<"Trafienie!"<< endl;
    }
}

bool sprawdzaniestrzalow(int Statki[11][11], int pion, int poziom)
{
    if ((Statki[pion][poziom] == 0) || (Statki[pion][poziom] == 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void wyswietlanie(int Statki1[11][11], int Statki2[11][11], int pion, int poziom)
{
    Statki2[pion][poziom]=Statki1[pion][poziom];
}

void generowanie(int Statki[11][11], int wielkosc, int pion, int poziom, int kierunek)
{
	if (wielkosc == 1)
	{
	    if (sprawdzanie(Statki, pion, poziom) == true)
        {
            Statki[pion][poziom]++;
        }
		else
		{
			do
			{
				pion=rand()%10+1;
				poziom=rand()%10+1;
			}
			while (sprawdzanie(Statki, pion, poziom) == false);
			Statki[pion][poziom]++;
		}
	}
	if (wielkosc == 2)
	{
		if (kierunek == 1)
		{
			if ((sprawdzanie(Statki, pion, poziom) == true) &&
                (sprawdzanie(Statki, pion-1, poziom) == true))
            {
				Statki[pion][poziom]++;
				Statki[pion-1][poziom]++;
            }
			else
            {
                do
                {
                    pion=rand()%10+1;
                    poziom=rand()%10+1;
                }
                while ((sprawdzanie(Statki, pion, poziom) == false) ||
                       (sprawdzanie(Statki, pion-1, poziom) == false));
                Statki[pion][poziom]++;
				Statki[pion-1][poziom]++;
            }
		}
		if (kierunek == 2)
		{
			if ((sprawdzanie(Statki, pion, poziom) == true) &&
                (sprawdzanie(Statki, pion, poziom+1) == true))
			{
				Statki[pion][poziom]++;
				Statki[pion][poziom+1]++;
			}
			else
			{
				do
				{
					pion=rand()%10+1;
					poziom=rand()%10+1;
				}
				while ((sprawdzanie(Statki, pion, poziom) == false) ||
                        (sprawdzanie(Statki, pion, poziom+1) == false));
				Statki[pion][poziom]++;
				Statki[pion][poziom+1]++;
			}
		}
		if (kierunek == 3)
        {
            if ((sprawdzanie(Statki, pion, poziom) == true) &&
                (sprawdzanie(Statki, pion+1, poziom) == true))
            {
				Statki[pion][poziom]++;
				Statki[pion+1][poziom]++;
            }
			else
            {
                do
                {
                    pion=rand()%10+1;
                    poziom=rand()%10+1;
                }
                while ((sprawdzanie(Statki, pion, poziom) == false) ||
                       (sprawdzanie(Statki, pion+1, poziom) == false));
                Statki[pion][poziom]++;
				Statki[pion+1][poziom]++;
            }
        }
        if (kierunek == 4)
        {
            if ((sprawdzanie(Statki, pion, poziom) == true) &&
                (sprawdzanie(Statki, pion, poziom-1) == true))
            {
				Statki[pion][poziom]++;
				Statki[pion][poziom-1]++;
            }
			else
            {
                do
                {
                    pion=rand()%10+1;
                    poziom=rand()%10+1;
                }
                while ((sprawdzanie(Statki, pion, poziom) == false) ||
                       (sprawdzanie(Statki, pion, poziom-1) == false));
                Statki[pion][poziom]++;
				Statki[pion][poziom-1]++;
            }
        }
	}
	if (wielkosc == 3)
    {
        if (kierunek == 1)
		{
			if ((sprawdzanie(Statki, pion, poziom) == true) &&
                (sprawdzanie(Statki, pion-1, poziom) == true) &&
                (sprawdzanie(Statki, pion-2, poziom) == true))
            {
				Statki[pion][poziom]++;
				Statki[pion-1][poziom]++;
				Statki[pion-2][poziom]++;
            }
			else
            {
                do
                {
                    pion=rand()%10+1;
                    poziom=rand()%10+1;
                }
                while ((sprawdzanie(Statki, pion, poziom) == false) ||
                       (sprawdzanie(Statki, pion-1, poziom) == false) ||
                       (sprawdzanie(Statki, pion-2, poziom) == false));
                Statki[pion][poziom]++;
				Statki[pion-1][poziom]++;
				Statki[pion-2][poziom]++;
            }
		}
		if (kierunek == 2)
		{
			if ((sprawdzanie(Statki, pion, poziom) == true) &&
                (sprawdzanie(Statki, pion, poziom+1) == true) &&
                (sprawdzanie(Statki, pion, poziom+2) == true))
			{
				Statki[pion][poziom]++;
				Statki[pion][poziom+1]++;
				Statki[pion][poziom+2]++;
			}
			else
			{
				do
				{
					pion=rand()%10+1;
					poziom=rand()%10+1;
				}
				while ((sprawdzanie(Statki, pion, poziom) == false) ||
                        (sprawdzanie(Statki, pion, poziom+1) == false) ||
                        (sprawdzanie(Statki, pion, poziom+2) == false));
				Statki[pion][poziom]++;
				Statki[pion][poziom+1]++;
				Statki[pion][poziom+2]++;
			}
		}
		if (kierunek == 3)
        {
            if ((sprawdzanie(Statki, pion, poziom) == true) &&
                (sprawdzanie(Statki, pion+1, poziom) == true) &&
                (sprawdzanie(Statki, pion+2, poziom) == true))
            {
				Statki[pion][poziom]++;
				Statki[pion+1][poziom]++;
				Statki[pion+2][poziom]++;
            }
			else
            {
                do
                {
                    pion=rand()%10+1;
                    poziom=rand()%10+1;
                }
                while ((sprawdzanie(Statki, pion, poziom) == false) ||
                       (sprawdzanie(Statki, pion+1, poziom) == false) ||
                       (sprawdzanie(Statki, pion+2, poziom) == false));
                Statki[pion][poziom]++;
				Statki[pion+1][poziom]++;
				Statki[pion+2][poziom]++;
            }
        }
        if (kierunek == 4)
        {
            if ((sprawdzanie(Statki, pion, poziom) == true) &&
                (sprawdzanie(Statki, pion, poziom-1) == true) &&
                (sprawdzanie(Statki, pion, poziom-2) == true))
            {
				Statki[pion][poziom]++;
				Statki[pion][poziom-1]++;
				Statki[pion][poziom-2]++;
            }
			else
            {
                do
                {
                    pion=rand()%10+1;
                    poziom=rand()%10+1;
                }
                while ((sprawdzanie(Statki, pion, poziom) == false) ||
                       (sprawdzanie(Statki, pion, poziom-1) == false) ||
                       (sprawdzanie(Statki, pion, poziom-2) == false));
                Statki[pion][poziom]++;
				Statki[pion][poziom-1]++;
				Statki[pion][poziom-2]++;
            }
        }
    }
    if (wielkosc == 4)
    {
        if (kierunek == 1)
		{
			if ((sprawdzanie(Statki, pion, poziom) == true) &&
                (sprawdzanie(Statki, pion-1, poziom) == true) &&
                (sprawdzanie(Statki, pion-2, poziom) == true) &&
                (sprawdzanie(Statki, pion-3, poziom) == true))
            {
				Statki[pion][poziom]++;
				Statki[pion-1][poziom]++;
				Statki[pion-2][poziom]++;
				Statki[pion-3][poziom]++;
            }
			else
            {
                do
                {
                    pion=rand()%10+1;
                    poziom=rand()%10+1;
                }
                while ((sprawdzanie(Statki, pion, poziom) == false) ||
                       (sprawdzanie(Statki, pion-1, poziom) == false) ||
                       (sprawdzanie(Statki, pion-2, poziom) == false) ||
                       (sprawdzanie(Statki, pion-3, poziom) == false));
                Statki[pion][poziom]++;
				Statki[pion-1][poziom]++;
				Statki[pion-2][poziom]++;
				Statki[pion-3][poziom]++;
            }
		}
		if (kierunek == 2)
		{
			if ((sprawdzanie(Statki, pion, poziom) == true) &&
                (sprawdzanie(Statki, pion, poziom+1) == true) &&
                (sprawdzanie(Statki, pion, poziom+2) == true) &&
                (sprawdzanie(Statki, pion, poziom+3) == true))
			{
				Statki[pion][poziom]++;
				Statki[pion][poziom+1]++;
				Statki[pion][poziom+2]++;
				Statki[pion][poziom+3]++;
			}
			else
			{
				do
				{
					pion=rand()%10+1;
					poziom=rand()%10+1;
				}
				while ((sprawdzanie(Statki, pion, poziom) == false) ||
                        (sprawdzanie(Statki, pion, poziom+1) == false) ||
                        (sprawdzanie(Statki, pion, poziom+2) == false) ||
                        (sprawdzanie(Statki, pion, poziom+3) == false));
				Statki[pion][poziom]++;
				Statki[pion][poziom+1]++;
				Statki[pion][poziom+2]++;
				Statki[pion][poziom+3]++;
			}
		}
		if (kierunek == 3)
        {
            if ((sprawdzanie(Statki, pion, poziom) == true) &&
                (sprawdzanie(Statki, pion+1, poziom) == true) &&
                (sprawdzanie(Statki, pion+2, poziom) == true) &&
                (sprawdzanie(Statki, pion+3, poziom) == true))
            {
				Statki[pion][poziom]++;
				Statki[pion+1][poziom]++;
				Statki[pion+2][poziom]++;
				Statki[pion+3][poziom]++;
            }
			else
            {
                do
                {
                    pion=rand()%10+1;
                    poziom=rand()%10+1;
                }
                while ((sprawdzanie(Statki, pion, poziom) == false) ||
                       (sprawdzanie(Statki, pion+1, poziom) == false) ||
                       (sprawdzanie(Statki, pion+2, poziom) == false) ||
                       (sprawdzanie(Statki, pion+3, poziom) == false));
                Statki[pion][poziom]++;
				Statki[pion+1][poziom]++;
				Statki[pion+2][poziom]++;
				Statki[pion+3][poziom]++;
            }
        }
        if (kierunek == 4)
        {
            if ((sprawdzanie(Statki, pion, poziom) == true) &&
                (sprawdzanie(Statki, pion, poziom-1) == true) &&
                (sprawdzanie(Statki, pion, poziom-2) == true) &&
                (sprawdzanie(Statki, pion, poziom-3) == true))
            {
				Statki[pion][poziom]++;
				Statki[pion][poziom-1]++;
				Statki[pion][poziom-2]++;
				Statki[pion][poziom-3]++;
            }
			else
            {
                do
                {
                    pion=rand()%10+1;
                    poziom=rand()%10+1;
                }
                while ((sprawdzanie(Statki, pion, poziom) == false) ||
                       (sprawdzanie(Statki, pion, poziom-1) == false) ||
                       (sprawdzanie(Statki, pion, poziom-2) == false) ||
                       (sprawdzanie(Statki, pion, poziom-3) == false));
                Statki[pion][poziom]++;
				Statki[pion][poziom-1]++;
				Statki[pion][poziom-2]++;
				Statki[pion][poziom-3]++;
            }
        }
    }
}

int main()
{
int tryb, Statkigracza[11][11], Statkikomputera[11][11], Statkipomoc[11][11], wielkosc, wielkosc1=0;
int wielkosc2=0, wielkosc3=0, wielkosc4=0, liczbastatkow=0, start=0, koniec=0, trafieniakomp=0, trafieniagracz=0, liczbastrzalow=0;
int pion, poziom, pomoc, nowa=1;
for (int i=1; i<=10;i++)
{
	for (int j=1;j<=10;j++)
	{
		Statkigracza[i][j]=0;
		Statkikomputera[i][j]=0;
		Statkipomoc[i][j]=0;
	}
}
do
{
	cout << "MENU"<< endl;
	cout << "1. Nowa gra"<< endl;
	cout << "2. Wczytaj gre"<< endl;
	cout << "3. Zasady gry"<< endl;
	cin >> tryb;
    if (tryb == 3)
    {
        cout << "Legenda:"<<endl;
        cout << "0 - woda"<<endl;
        cout << "1 - statek"<<endl;
        cout << "-1 - trafiony statek"<<endl;
        cout << "-2 - strzal w wode"<<endl;
        cout << endl<< endl<< endl;
        cout << "Zasady:"<<endl;
        cout << "1. Na swojej planyszy gracz ustawia 1 statek o wielkosci 4,"<<endl;
        cout << "2 statki o wielkosci 3, 3 statki o wielkosci 2 i 4 statki o wielkosci 1"<<endl;
        cout << endl;
        cout << "2. Nie mozna ustawiac statkow obok siebie (1 kratka odstepu wymagana)"<<endl;
        cout << endl;
        cout << "3. Nie mozna strzelac 2 razy w to samo miejsce"<<endl;
        cout << endl;
        cout << "4. Wygrywa ten kto jako pierwszy zatopi wszystkie statki przeciwnika"<<endl;
        cout << endl;
        cout << "5. Auto zapis jest wykonywany co ture"<<endl;
        cout << endl;
        cout << "Wybierz 1 aby zaczac nowa gre lub 2, aby wczytac zapis"<<endl;
        cin >> tryb;
    }
    if (tryb == 2)
    {
        wczytywanie(Statkigracza, Statkikomputera, Statkipomoc);
        tryb=1;
        nowa=0;
    }
	if (tryb == 1)
	{
	    if (nowa == 1)
        {
            system("cls");
            srand(time(NULL));
            int pion=rand()%10+1;
            int poziom=rand()%10+1;
            int kierunek=rand()%4+1;
            generowanie(Statkikomputera, 4, pion, poziom, kierunek);
            for(int i=1; i<=2; i++)
            {
                int pion=rand()%10+1;
                int poziom=rand()%10+1;
                int kierunek=rand()%4+1;
                generowanie(Statkikomputera, 3, pion, poziom, kierunek);
            }
            for(int i=1; i<=3; i++)
            {
                int pion=rand()%10+1;
                int poziom=rand()%10+1;
                int kierunek=rand()%4+1;
                generowanie(Statkikomputera, 2, pion, poziom, kierunek);
            }
            for(int i=1; i<=4; i++)
            {
                int pion=rand()%10+1;
                int poziom=rand()%10+1;
                int kierunek=rand()%4+1;
                generowanie(Statkikomputera, 1, pion, poziom, kierunek);
            }
            do
            {
                cout << "Wpisz wielkosc statku jaki chcesz postawic"<< endl;
                cout << "Liczba statkow do postawienia = "<< 10-liczbastatkow << endl;
                do
                {
                    cin >> wielkosc;
                    if ((wielkosc > 4) || (wielkosc < 1))
                    {
                        system("cls");
                        cout << "Blad danych!!! Podaj wielkosc jeszcze raz"<< endl;
                    }
                }
                while((wielkosc > 4) || (wielkosc < 1));
                if (wielkosc == 1)
                {
                    if (wielkosc1 >= 4)
                    {
                        system("cls");
                        cout << "Nie mozesz postawic wiecej statkow tej wielkosci"<< endl;
                    }
                    else
                    {
                        cout << "Podaj wspolrzedne na ktorych mam umiescic statek (plansza 10x10)"<< endl;
                        for (int i=1; i<=10;i++)
                        {
                            for (int j=1;j<=10;j++)
                            {
                                cout << Statkigracza[i][j]<<" ";
                            }
                            cout << endl;
                        }
                        cout << "Pion: "<<endl;
                        cin >> pion;
                        cout << "Poziom: "<<endl;
                        cin >> poziom;
                        if (sprawdzanie(Statkigracza, pion, poziom) == true)
                        {
                            generowanie(Statkigracza, 1, pion, poziom, 1);
                            liczbastatkow++;
                            wielkosc1++;
                            system("cls");
                        }
                        else
                        {
                            do
                            {
                                system("cls");
                                cout << "Blad danych!!! Wpisz wspolrzedne jeszcze raz"<< endl;
                                for (int i=1; i<=10;i++)
                                {
                                    for (int j=1;j<=10;j++)
                                    {
                                        cout << Statkigracza[i][j]<<" ";
                                    }
                                    cout << endl;
                                }
                                cout << "Pion: "<<endl;
                                cin >> pion;
                                cout << "Poziom: "<<endl;
                                cin >> poziom;
                            }
                            while ((sprawdzanie(Statkigracza, pion, poziom) == false));
                            liczbastatkow++;
                            wielkosc1++;
                            system("cls");
                        }
                    }
                }
                if (wielkosc == 2)
                {
                    if (wielkosc2 >= 3)
                    {
                        system("cls");
                        cout << "Nie mozesz postawic wiecej statkow tej wielkosci"<< endl;
                    }
                    else
                    {
                        cout << "Podaj wspolrzedne na ktorych mam umiescic statek (plansza 10x10)"<< endl;
                        for (int i=1; i<=10;i++)
                        {
                            for (int j=1;j<=10;j++)
                            {
                                cout << Statkigracza[i][j]<<" ";
                            }
                            cout << endl;
                        }
                        cout << "Pion: "<<endl;
                        cin >> pion;
                        cout << "Poziom: "<<endl;
                        cin >> poziom;
                        int kierunek;
                        cout << "Podaj kierunek w jaki ma byc zwrocony statek" <<endl
                        <<"Polnoc - 1 , Wschod - 2, Polodnie - 3, Zachod - 4"<<endl;
                        do
                        {
                            cin >> kierunek;
                            if ((kierunek > 4) || (kierunek < 1))
                            {
                                system("cls");
                                cout << "Blad danych, podaj jeszcze raz"<< endl;
                            }
                        }
                        while ((kierunek > 4) || (kierunek < 1));
                        if (kierunek == 1)
                        {
                            if ((sprawdzanie(Statkigracza, pion, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion-1, poziom) == true))
                            {
                                generowanie(Statkigracza, 2, pion, poziom, 1);
                                liczbastatkow++;
                                wielkosc2++;
                                system("cls");
                            }
                            else
                            {
                                do
                                {
                                    system("cls");
                                    cout << "Blad danych!!! Wpisz wspolrzedne jeszcze raz"<< endl;
                                    for (int i=1; i<=10;i++)
                                    {
                                        for (int j=1;j<=10;j++)
                                        {
                                            cout << Statkigracza[i][j]<<" ";
                                        }
                                        cout << endl;
                                    }
                                    cout << "Pion: "<<endl;
                                    cin >> pion;
                                    cout << "Poziom: "<<endl;
                                    cin >> poziom;
                                }
                                while ((sprawdzanie(Statkigracza, pion, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion-1, poziom) == false));
                                generowanie(Statkigracza, 2, pion, poziom, 1);
                                liczbastatkow++;
                                wielkosc2++;
                                system("cls");
                            }
                        }
                        if (kierunek == 2)
                        {
                            if ((sprawdzanie(Statkigracza, pion, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion, poziom+1) == true))
                            {
                                generowanie(Statkigracza, 2, pion, poziom, 2);
                                liczbastatkow++;
                                wielkosc2++;
                                system("cls");
                            }
                            else
                            {
                                do
                                {
                                    system("cls");
                                    cout << "Blad danych!!! Wpisz wspolrzedne jeszcze raz"<< endl;
                                    for (int i=1; i<=10;i++)
                                    {
                                        for (int j=1;j<=10;j++)
                                        {
                                            cout << Statkigracza[i][j]<<" ";
                                        }
                                        cout << endl;
                                    }
                                    cout << "Pion: "<<endl;
                                    cin >> pion;
                                    cout << "Poziom: "<<endl;
                                    cin >> poziom;
                                }
                                while ((sprawdzanie(Statkigracza, pion, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion, poziom+1) == false));
                                generowanie(Statkigracza, 2, pion, poziom, 2);
                                liczbastatkow++;
                                wielkosc2++;
                                system("cls");
                            }
                        }
                        if (kierunek == 3)
                        {
                            if ((sprawdzanie(Statkigracza, pion, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion+1, poziom) == true))
                            {
                                generowanie(Statkigracza, 2, pion, poziom, 3);
                                liczbastatkow++;
                                wielkosc2++;
                                system("cls");
                            }
                            else
                            {
                                do
                                {
                                    system("cls");
                                    cout << "Blad danych!!! Wpisz wspolrzedne jeszcze raz"<< endl;
                                    for (int i=1; i<=10;i++)
                                    {
                                        for (int j=1;j<=10;j++)
                                        {
                                            cout << Statkigracza[i][j]<<" ";
                                        }
                                        cout << endl;
                                    }
                                    cout << "Pion: "<<endl;
                                    cin >> pion;
                                    cout << "Poziom: "<<endl;
                                    cin >> poziom;
                                }
                                while ((sprawdzanie(Statkigracza, pion, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion+1, poziom) == false));
                                generowanie(Statkigracza, 2, pion, poziom, 1);
                                liczbastatkow++;
                                wielkosc2++;
                                system("cls");
                            }
                        }
                        if (kierunek == 4)
                        {
                            if ((sprawdzanie(Statkigracza, pion, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion, poziom-1) == true))
                            {
                                generowanie(Statkigracza, 2, pion, poziom, 4);
                                liczbastatkow++;
                                wielkosc2++;
                                system("cls");
                            }
                            else
                            {
                                do
                                {
                                    system("cls");
                                    cout << "Blad danych!!! Wpisz wspolrzedne jeszcze raz"<< endl;
                                    for (int i=1; i<=10;i++)
                                    {
                                        for (int j=1;j<=10;j++)
                                        {
                                            cout << Statkigracza[i][j]<<" ";
                                        }
                                        cout << endl;
                                    }
                                    cout << "Pion: "<<endl;
                                    cin >> pion;
                                    cout << "Poziom: "<<endl;
                                    cin >> poziom;
                                }
                                while ((sprawdzanie(Statkigracza, pion, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion, poziom-1) == false));
                                generowanie(Statkigracza, 2, pion, poziom, 4);
                                liczbastatkow++;
                                wielkosc2++;
                                system("cls");
                            }
                        }
                    }
                }
                if (wielkosc == 3)
                {
                    if (wielkosc3 >= 2)
                    {
                        system("cls");
                        cout << "Nie mozesz postawic wiecej statkow tej wielkosci"<< endl;
                    }
                    else
                    {
                        cout << "Podaj wspolrzedne na ktorych mam umiescic statek (plansza 10x10)"<< endl;
                        for (int i=1; i<=10;i++)
                        {
                            for (int j=1;j<=10;j++)
                            {
                                cout << Statkigracza[i][j]<<" ";
                            }
                            cout << endl;
                        }
                        cout << "Pion: "<<endl;
                        cin >> pion;
                        cout << "Poziom: "<<endl;
                        cin >> poziom;
                        int kierunek;
                        cout << "Podaj kierunek w jaki ma byc zwrocony statek" <<endl
                        <<"Polnoc - 1 , Wschod - 2, Polodnie - 3, Zachod - 4"<<endl;
                        do
                        {
                            cin >> kierunek;
                            if ((kierunek > 4) || (kierunek < 1))
                            {
                                system("cls");
                                cout << "Blad danych, podaj jeszcze raz"<< endl;
                            }
                        }
                        while ((kierunek > 4) || (kierunek < 1));
                        if (kierunek == 1)
                        {
                            if ((sprawdzanie(Statkigracza, pion, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion-1, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion-2, poziom) == true))
                            {
                                generowanie(Statkigracza, 3, pion, poziom, 1);
                                liczbastatkow++;
                                wielkosc3++;
                                system("cls");
                            }
                            else
                            {
                                do
                                {
                                    system("cls");
                                    cout << "Blad danych!!! Wpisz wspolrzedne jeszcze raz"<< endl;
                                    for (int i=1; i<=10;i++)
                                    {
                                        for (int j=1;j<=10;j++)
                                        {
                                            cout << Statkigracza[i][j]<<" ";
                                        }
                                        cout << endl;
                                    }
                                    cout << "Pion: "<<endl;
                                    cin >> pion;
                                    cout << "Poziom: "<<endl;
                                    cin >> poziom;
                                }
                                while ((sprawdzanie(Statkigracza, pion, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion-1, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion-2, poziom) == false));
                                generowanie(Statkigracza, 2, pion, poziom, 1);
                                liczbastatkow++;
                                wielkosc3++;
                                system("cls");
                            }
                        }
                        if (kierunek == 2)
                        {
                            if ((sprawdzanie(Statkigracza, pion, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion, poziom+1) == true) &&
                                (sprawdzanie(Statkigracza, pion, poziom+2) == true))
                            {
                                generowanie(Statkigracza, 3, pion, poziom, 2);
                                liczbastatkow++;
                                wielkosc3++;
                                system("cls");
                            }
                            else
                            {
                                do
                                {
                                    system("cls");
                                    cout << "Blad danych!!! Wpisz wspolrzedne jeszcze raz"<< endl;
                                    for (int i=1; i<=10;i++)
                                    {
                                        for (int j=1;j<=10;j++)
                                        {
                                            cout << Statkigracza[i][j]<<" ";
                                        }
                                        cout << endl;
                                    }
                                    cout << "Pion: "<<endl;
                                    cin >> pion;
                                    cout << "Poziom: "<<endl;
                                    cin >> poziom;
                                }
                                while ((sprawdzanie(Statkigracza, pion, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion, poziom+1) == false) ||
                                       (sprawdzanie(Statkigracza, pion, poziom+2) == false));
                                generowanie(Statkigracza, 3, pion, poziom, 2);
                                liczbastatkow++;
                                wielkosc3++;
                                system("cls");
                            }
                        }
                        if (kierunek == 3)
                        {
                            if ((sprawdzanie(Statkigracza, pion, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion+1, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion+2, poziom) == true))
                            {
                                generowanie(Statkigracza, 3, pion, poziom, 3);
                                liczbastatkow++;
                                wielkosc3++;
                                system("cls");
                            }
                            else
                            {
                                do
                                {
                                    system("cls");
                                    cout << "Blad danych!!! Wpisz wspolrzedne jeszcze raz"<< endl;
                                    for (int i=1; i<=10;i++)
                                    {
                                        for (int j=1;j<=10;j++)
                                        {
                                            cout << Statkigracza[i][j]<<" ";
                                        }
                                        cout << endl;
                                    }
                                    cout << "Pion: "<<endl;
                                    cin >> pion;
                                    cout << "Poziom: "<<endl;
                                    cin >> poziom;
                                }
                                while ((sprawdzanie(Statkigracza, pion, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion+1, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion+2, poziom) == false));
                                generowanie(Statkigracza, 3, pion, poziom, 3);
                                liczbastatkow++;
                                wielkosc3++;
                                system("cls");
                            }
                        }
                        if (kierunek == 4)
                        {
                            if ((sprawdzanie(Statkigracza, pion, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion, poziom-1) == true) &&
                                (sprawdzanie(Statkigracza, pion, poziom-2) == true))
                            {
                                generowanie(Statkigracza, 3, pion, poziom, 4);
                                liczbastatkow++;
                                wielkosc3++;
                                system("cls");
                            }
                            else
                            {
                                do
                                {
                                    system("cls");
                                    cout << "Blad danych!!! Wpisz wspolrzedne jeszcze raz"<< endl;
                                    for (int i=1; i<=10;i++)
                                    {
                                        for (int j=1;j<=10;j++)
                                        {
                                            cout << Statkigracza[i][j]<<" ";
                                        }
                                        cout << endl;
                                    }
                                    cout << "Pion: "<<endl;
                                    cin >> pion;
                                    cout << "Poziom: "<<endl;
                                    cin >> poziom;
                                }
                                while ((sprawdzanie(Statkigracza, pion, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion, poziom-1) == false) ||
                                       (sprawdzanie(Statkigracza, pion, poziom-2) == false));
                                generowanie(Statkigracza, 3, pion, poziom, 4);
                                liczbastatkow++;
                                wielkosc3++;
                                system("cls");
                            }
                        }
                    }
                }
                if (wielkosc == 4)
                {
                    if (wielkosc4 >= 1)
                    {
                        system("cls");
                        cout << "Nie mozesz postawic wiecej statkow tej wielkosci"<< endl;
                    }
                    else
                    {
                        cout << "Podaj wspolrzedne na ktorych mam umiescic statek (plansza 10x10)"<< endl;
                        for (int i=1; i<=10;i++)
                        {
                            for (int j=1;j<=10;j++)
                            {
                                cout << Statkigracza[i][j]<<" ";
                            }
                            cout << endl;
                        }
                        cout << "Pion: "<<endl;
                        cin >> pion;
                        cout << "Poziom: "<<endl;
                        cin >> poziom;
                        int kierunek;
                        cout << "Podaj kierunek w jaki ma byc zwrocony statek" <<endl
                        <<"Polnoc - 1 , Wschod - 2, Polodnie - 3, Zachod - 4"<<endl;
                        do
                        {
                            cin >> kierunek;
                            if ((kierunek > 4) || (kierunek < 1))
                            {
                                system("cls");
                                cout << "Blad danych, podaj jeszcze raz";
                            }
                        }
                        while ((kierunek > 4) || (kierunek < 1));
                        if (kierunek == 1)
                        {
                            if ((sprawdzanie(Statkigracza, pion, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion-1, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion-2, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion-3, poziom) == true))
                            {
                                generowanie(Statkigracza, 4, pion, poziom, 1);
                                liczbastatkow++;
                                wielkosc4++;
                                system("cls");
                            }
                            else
                            {
                                do
                                {
                                    system("cls");
                                    cout << "Blad danych!!! Wpisz wspolrzedne jeszcze raz"<< endl;
                                    for (int i=1; i<=10;i++)
                                    {
                                        for (int j=1;j<=10;j++)
                                        {
                                            cout << Statkigracza[i][j]<<" ";
                                        }
                                        cout << endl;
                                    }
                                    cout << "Pion: "<<endl;
                                    cin >> pion;
                                    cout << "Poziom: "<<endl;
                                    cin >> poziom;
                                }
                                while ((sprawdzanie(Statkigracza, pion, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion-1, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion-2, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion-3, poziom) == false));
                                generowanie(Statkigracza, 4, pion, poziom, 1);
                                liczbastatkow++;
                                wielkosc4++;
                                system("cls");
                            }
                        }
                        if (kierunek == 2)
                        {
                            if ((sprawdzanie(Statkigracza, pion, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion, poziom+1) == true) &&
                                (sprawdzanie(Statkigracza, pion, poziom+2) == true) &&
                                (sprawdzanie(Statkigracza, pion, poziom+3) == true))
                            {
                                generowanie(Statkigracza, 4, pion, poziom, 2);
                                liczbastatkow++;
                                wielkosc4++;
                                system("cls");
                            }
                            else
                            {
                                do
                                {
                                    system("cls");
                                    cout << "Blad danych!!! Wpisz wspolrzedne jeszcze raz"<< endl;
                                    for (int i=1; i<=10;i++)
                                    {
                                        for (int j=1;j<=10;j++)
                                        {
                                            cout << Statkigracza[i][j]<<" ";
                                        }
                                        cout << endl;
                                    }
                                    cout << "Pion: "<<endl;
                                    cin >> pion;
                                    cout << "Poziom: "<<endl;
                                    cin >> poziom;
                                }
                                while ((sprawdzanie(Statkigracza, pion, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion, poziom+1) == false) ||
                                       (sprawdzanie(Statkigracza, pion, poziom+2) == false) ||
                                       (sprawdzanie(Statkigracza, pion, poziom+3) == false));
                                generowanie(Statkigracza, 4, pion, poziom, 2);
                                liczbastatkow++;
                                wielkosc4++;
                                system("cls");
                            }
                        }
                        if (kierunek == 3)
                        {
                            if ((sprawdzanie(Statkigracza, pion, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion+1, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion+2, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion+3, poziom) == true))
                            {
                                generowanie(Statkigracza, 4, pion, poziom, 3);
                                liczbastatkow++;
                                wielkosc4++;
                                system("cls");
                            }
                            else
                            {
                                do
                                {
                                    system("cls");
                                    cout << "Blad danych!!! Wpisz wspolrzedne jeszcze raz"<< endl;
                                    for (int i=1; i<=10;i++)
                                    {
                                        for (int j=1;j<=10;j++)
                                        {
                                            cout << Statkigracza[i][j]<<" ";
                                        }
                                        cout << endl;
                                    }
                                    cout << "Pion: "<<endl;
                                    cin >> pion;
                                    cout << "Poziom: "<<endl;
                                    cin >> poziom;
                                }
                                while ((sprawdzanie(Statkigracza, pion, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion+1, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion+2, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion+3, poziom) == true));
                                generowanie(Statkigracza, 4, pion, poziom, 3);
                                liczbastatkow++;
                                wielkosc4++;
                                system("cls");
                            }
                        }
                        if (kierunek == 4)
                        {
                            if ((sprawdzanie(Statkigracza, pion, poziom) == true) &&
                                (sprawdzanie(Statkigracza, pion, poziom-1) == true) &&
                                (sprawdzanie(Statkigracza, pion, poziom-2) == true) &&
                                (sprawdzanie(Statkigracza, pion, poziom-3) == true))
                            {
                                generowanie(Statkigracza, 4, pion, poziom, 4);
                                liczbastatkow++;
                                wielkosc4++;
                                system("cls");
                            }
                            else
                            {
                                do
                                {
                                    system("cls");
                                    cout << "Blad danych!!! Wpisz wspolrzedne jeszcze raz"<< endl;
                                    for (int i=1; i<=10;i++)
                                    {
                                        for (int j=1;j<=10;j++)
                                        {
                                            cout << Statkigracza[i][j]<<" ";
                                        }
                                        cout << endl;
                                    }
                                    cout << "Pion: "<<endl;
                                    cin >> pion;
                                    cout << "Poziom: "<<endl;
                                    cin >> poziom;
                                }
                                while ((sprawdzanie(Statkigracza, pion, poziom) == false) ||
                                       (sprawdzanie(Statkigracza, pion, poziom-1) == false) ||
                                       (sprawdzanie(Statkigracza, pion, poziom-2) == false) ||
                                       (sprawdzanie(Statkigracza, pion, poziom-3) == false));
                                generowanie(Statkigracza, 4, pion, poziom, 4);
                                liczbastatkow++;
                                wielkosc4++;
                                system("cls");
                            }
                        }
                    }
                }
            }
            while(liczbastatkow<10);
            nowa = 0;
        }
        if (nowa == 0)
        {
            do
            {
                do
                {
                    system("cls");
                    cout << "Twoja plansza"<< endl;
                    for (int i=1; i<=10;i++)
                    {
                        for (int j=1;j<=10;j++)
                        {
                            cout << Statkigracza[i][j]<<" ";
                        }
                        cout << endl;
                    }
                    cout << endl;
                    cout << "Plansza komputera"<< endl;
                    for (int i=1; i<=10;i++)
                    {
                        for (int j=1;j<=10;j++)
                        {
                            cout << Statkipomoc[i][j]<<" ";
                        }
                        cout << endl;
                    }
                    cout << "Podaj wspolrzedne strzalu"<< endl;
                    cout << "Pion: "<<endl;
                    cin >> pion;
                    if ((pion > 10) || (pion < 1))
                    {
                        cout << "Blad danych, podaj pion jeszcze raz!" <<endl;
                        do
                        {
                            cin >> pion;
                        }
                        while ((pion > 10) || (pion < 1));
                    }
                    cout << "Poziom: "<<endl;
                    cin >> poziom;
                    if ((poziom > 10) || (poziom < 1))
                    {
                        cout << "Blad danych, podaj poziom jeszcze raz!" <<endl;
                        do
                        {
                            cin >> poziom;
                        }
                        while ((poziom > 10) || (poziom < 1));
                    }
                    if (sprawdzaniestrzalow(Statkikomputera, pion, poziom) == false)
                    {
                        do
                        {
                            cout << "Strzal w to samo miejsce!"<<endl;
                            cout << "Podaj wspolrzedne strzalu"<< endl;
                            cout << "Pion: "<<endl;
                            cin >> pion;
                            cout << "Poziom: "<<endl;
                            cin >> poziom;
                        }
                        while(sprawdzaniestrzalow(Statkikomputera, pion, poziom) == false);
                    }
                    strzal(Statkikomputera, pion, poziom);
                    wyswietlanie(Statkikomputera, Statkipomoc, pion, poziom);
                    trafieniagracz++;
                    liczbastrzalow++;
                }
                while(Statkikomputera[pion][poziom] == -1);
                pion=rand()%10+1;
                poziom=rand()%10+1;
                if (sprawdzaniestrzalow(Statkigracza, pion, poziom) == false)
                {
                    do
                    {
                        pion=rand()%10+1;
                        poziom=rand()%10+1;
                    }
                    while (sprawdzaniestrzalow(Statkigracza, pion, poziom) == false);
                }
                strzal(Statkigracza, pion, poziom);
                if (Statkigracza[pion][poziom] == -1)
                {
                    trafieniakomp++;
                    int kierunek=rand()%4+1;
                    do
                    {
                        if (kierunek == 4)
                        {
                            if (Statkigracza[pion][poziom-1] == -2)
                            {
                                kierunek=2;
                            }
                            else
                            {
                                if (sprawdzaniestrzalow(Statkigracza, pion, poziom-1) == true)
                                {
                                    poziom--;
                                    strzal(Statkigracza, pion, poziom);
                                    if (Statkigracza[pion][poziom] == -1)
                                    {
                                        trafieniakomp++;
                                    }
                                }
                                else
                                {
                                    poziom=poziom-2;
                                    strzal(Statkigracza, pion, poziom);
                                    if (Statkigracza[pion][poziom] == -1)
                                    {
                                        trafieniakomp++;
                                    }
                                }
                            }
                        }
                        if (kierunek == 3)
                        {
                            if (Statkigracza[pion+1][poziom] == -2)
                            {
                                kierunek=2;
                            }
                            else
                            {
                                if (sprawdzaniestrzalow(Statkigracza, pion+1, poziom) == true)
                                {
                                    pion++;
                                    strzal(Statkigracza, pion, poziom);
                                    if (Statkigracza[pion][poziom] == -1)
                                    {
                                        trafieniakomp++;
                                    }
                                }
                                else
                                {
                                    pion=pion+2;
                                    strzal(Statkigracza, pion, poziom);
                                    if (Statkigracza[pion][poziom] == -1)
                                    {
                                        trafieniakomp++;
                                    }
                                }
                            }
                        }
                        if (kierunek == 2)
                        {
                            if (Statkigracza[pion][poziom+1] == -2)
                            {
                                kierunek=4;
                            }
                            else
                            {
                                if (sprawdzaniestrzalow(Statkigracza, pion, poziom+1) == true)
                                {
                                    poziom++;
                                    strzal(Statkigracza, pion, poziom);
                                    if (Statkigracza[pion][poziom] == -1)
                                    {
                                        trafieniakomp++;
                                    }
                                }
                                else
                                {
                                    poziom=poziom+2;
                                    strzal(Statkigracza, pion, poziom);
                                    if (Statkigracza[pion][poziom] == -1)
                                    {
                                        trafieniakomp++;
                                    }
                                }
                            }
                        }
                        if (kierunek == 1)
                        {
                            if (Statkigracza[pion-1][poziom] == -2)
                            {
                                kierunek=3;
                            }
                            else
                            {
                                if (sprawdzaniestrzalow(Statkigracza, pion-1, poziom) == true)
                                {
                                    pion--;
                                    strzal(Statkigracza, pion, poziom);
                                    if (Statkigracza[pion][poziom] == -1)
                                    {
                                        trafieniakomp++;
                                    }
                                }
                                else
                                {
                                    pion=pion-2;
                                    strzal(Statkigracza, pion, poziom);
                                    if (Statkigracza[pion][poziom] == -1)
                                    {
                                        trafieniakomp++;
                                    }
                                }
                            }
                        }
                        if ((Statkigracza[pion-1][poziom] == -2) &&
                            (Statkigracza[pion][poziom+1] == -2) &&
                            (Statkigracza[pion+1][poziom] == -2) &&
                            (Statkigracza[pion][poziom-1] == -2))
                        {
                            do
                            {
                                pion=rand()%10+1;
                                poziom=rand()%10+1;
                            }
                            while (sprawdzaniestrzalow(Statkigracza, pion, poziom) == false);
                            strzal(Statkigracza, pion, poziom);
                            if (Statkigracza[pion][poziom] == -1)
                            {
                                trafieniakomp++;
                            }
                        }
                    }
                    while(Statkigracza[pion][poziom] == -1);
                    cout << "Komputer nie trafil! Twoj ruch!"<<endl;
                }
                else
                {
                    cout << "Komputer nie trafil! Twoj ruch!"<<endl;
                }

                if(trafieniagracz == 20)
                {
                    koniec=2;
                }
                if(trafieniakomp == 20)
                {
                    koniec=1;
                }
                system("cls");
                szyfrowanie(Statkigracza,Statkikomputera);
            }
            while (koniec == 0);
        }
        if (koniec==2)
        {
            system("cls");
            cout << "Gratulacje Wygrales! (+25 MMR)"<<endl;
            cout << "Liczba Twoich strzalow to "<<liczbastrzalow<<endl;
        }
        if (koniec==1)
        {
            system("cls");
            cout << "Komputer Wygral, sprobuj jeszcze raz (-25 MMR)"<<endl;
            cout << "Liczba Twoich strzalow to "<<liczbastrzalow<<endl;
        }
        if ((tryb !=1) && (tryb !=2) && (tryb !=3))
        {
            cout << "Blad danych! Wybierz jeszcze raz !"<< endl;
        }
    }
}
while ((tryb != 1) && (tryb != 2) && (tryb !=3));
}
