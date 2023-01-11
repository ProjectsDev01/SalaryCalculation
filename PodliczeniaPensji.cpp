#include <iostream>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;

int d = 1, dni[31][7];//jezeli mozliwe to czytac date z systemu, jesli nie trzeba zrobic instrukcje czytania dnia dzisiajszego
//*ustawi³em dla sprawdzenia d=1
void godziny();
void rezki();
void miasto();
void kaska();//*
void tablica();//*


int main()
{
    int n, dn = 0;

    time_t to;//*dostawanie dzisiajszego czasu
    struct tm t;
    to = time(NULL);
    t = *localtime(&to);
    d = t.tm_mday;
    //cout << d << "\n";


    fstream plikout, plikin;//*odczytywanie z pliku
    plikin.open("dane.txt", ios::in);
    if (plikin.is_open())
    {
        for (int i = 0;i < 31;i++)
        {
            for (int j = 0;j < 7;j++)
            {
                plikin >> dni[i][j];
            }
        }
        plikin.close();
    }
    else
    {
        plikout.open("dane.txt", ios::out);//*zapisywanie do pliku
        for (int i = 0;i < 31;i++)
        {
            for (int j = 0;j < 7;j++)
            {
                plikout << "0 ";
            }
            plikout << endl;
        }
        plikout.close();

        plikin.open("dane.txt", ios::in);
        for (int i = 0;i < 31;i++)
        {
            for (int j = 0;j < 7;j++)
            {
                plikin >> dni[i][j];
            }
        }
        plikin.close();
    }



    for (int j = d - 1;j < 31;j++)
    {
        for (int i = 0;i < 7;i++)
        {
            dni[j][i] = 0;
        }
    }

    do
    {
        //system("cls");//*po dodawa³em system("cls") w if
        cout << "######_MENU_#####\n";
        cout << "0. EXIT\n";
        cout << "1. Wpisz godziny:\n";
        cout << "2. Wpisz rezki\n";
        cout << "3. Wpisz miasto\n";
        cout << "4. Pokaz kaske B)\n";
        cout << "5. Pokaz tablice\n";
        cout << "##Podaj liczbe## : ";//*ma³a zmiana aby w tej linijce mo¿na by³o wpisywaæ

        cin >> n;
        cout << endl;//* dodana linijka odstêpu
        if (n == 1)
        {
            system("cls");//*
            godziny();
        }
        else if (n == 2)
        {
            system("cls");//*
            rezki();
        }
        else if (n == 3)
        {
            system("cls");//*
            miasto();
        }
        else if (n == 4)
        {
            system("cls");//*
            kaska();//*
        }
        else if (n == 5)
        {
            system("cls");//*
            tablica();//*
        }

    } while (n != 0);

    plikout.open("dane.txt", ios::out);//*zapisywanie do pliku
    for (int i = 0;i < 31;i++)
    {
        for (int j = 0;j < 7;j++)
        {
            plikout << dni[i][j] << " ";
        }
        plikout << endl;
    }
    plikout.close();
}

void godziny()
{
    int h;//, g, p;//#g,p
    system("cls");
    cout << "Podaj godziny:\n";// dni[20][]
    cin >> h;
    dni[d - 1][0] = h;
    //g = h * 19, 7;//#
    //p = h * 15;//#
}

void rezki()
{
    int nr, x;
    system("cls");
    cout << "1/2/3?: ";
    cin >> nr;
    cout << "Ilosc: ";
    cin >> x;
    if (nr >= 1 && nr <= 3)
    {
        dni[d - 1][nr + 3] = x;
    }
    //dni[d-1][nr] wtedy trzeba zabezpieczyc, zeby nie wpisac zlej liczby
    /*switch (nr)
    {
        case 1:
        cout << "Podaj ilosc:";
        cin >> x;
            break;
        case 2:
        cout << "Podaj ilosc:";
        cin >> y;
            break;
        case 3:
            cout << "Podaj ilosc:";
            cin >> y;
            break;
    }*/
}

void miasto()
{
    int nr, x;
    system("cls");
    cout << "1/2/3?: ";
    cin >> nr;
    cout << "Ilosc: ";
    cin >> x;
    if (nr >= 1 && nr <= 3)
    {
        dni[d - 1][nr] = x;// d ogarnac bo to dzien niby B)
    }
}
// zerowanie dni[d-1>>30], zeby te zera podmieniac


//**
void kaska()
{
    int s = 0;
    double summ = 0;
    double sump = 0;
    for (int i = 0;i < 31;i++)
    {
        s += dni[i][0];
    }
    summ += s * 19.7;
    s = 0;

    for (int i = 0;i < 31;i++)
    {
        s += dni[i][1];
    }
    sump += s * 15;
    s = 0;
    for (int i = 0;i < 31;i++)
    {
        s += dni[i][2];
    }
    sump += s * 25;
    s = 0;
    for (int i = 0;i < 31;i++)
    {
        s += dni[i][3];
    }
    sump += s * 35;
    s = 0;

    for (int i = 0;i < 31;i++)
    {
        s += dni[i][4];
    }
    sump += s * 17;
    s = 0;
    for (int i = 0;i < 31;i++)
    {
        s += dni[i][5];
    }
    sump += s * 33;
    s = 0;
    for (int i = 0;i < 31;i++)
    {
        s += dni[i][6];
    }
    sump += s * 50;
    cout << "minimalna:" << summ << endl;
    cout << "prowizjonowana:" << sump << endl;
    if (summ > sump)
    {
        cout << "ostateczna:" << summ << endl;
    }
    else
    {
        cout << "ostateczna:" << sump << endl;
    }
}

void tablica()
{
    cout << "| h|m1|m2|m3|r1|r2|r3|" << endl;
    cout << "|--|--|--|--|--|--|--|" << endl;
    for (int j = 0;j < 31;j++)
    {
        cout << "|";
        for (int i = 0;i < 7;i++)
        {
            if (dni[j][i] < 10)
            {
                cout << " " << dni[j][i];
            }
            else
            {
                cout << dni[j][i];
            }
            cout << "|";
        }
        cout << endl;
    }
}
