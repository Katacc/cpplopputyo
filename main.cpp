#include <iostream>
#include <stdlib.h>
#include <string>
#include <random>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;


// Globaalit vakiot
const int yhdenHengenHinta { 100 };
const int kahdenHengenHinta { 150 };
const int alennus0 { 0 };
const int alennus10 { 10 };
const int alennus20 { 20 };
const float alennus0pros { 1 };
const float alennus10pros { 0.90 };
const float alennus20pros { 0.80 };

// Syötteen tarkastus
int validInput()
{
    int x;
    std::cin >> x;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Virhe syotteessa. Syota NUMERO: ";
        std::cin >> x;
    }
    return x;
}

// Menubaari
void titleBar() {
    cout << "Hotelli Los Kata's varausjarjestelma" << endl;
    cout << "-------------------------------------" << endl;
    cout << "|1. Aloita varaus|2. Sulje ohjelma|" << "\n" << endl;

}

// Menubaari pohja
void titleBarBare() {
    cout << "Hotelli Los Kata's varausjarjestelma" << endl;
    cout << "-------------------------------------" << endl;
}

// Satunnaisnumerogeneraattori huoneiden määrälle
int randomNumberRooms() {
 std::random_device rd;
    std::default_random_engine rng { rd() };
    std::uniform_int_distribution <int> uni { 40, 300 };

return uni(rng);
}

// Aliohjelma "maksamiselle"
void maksamaan() {
    system("cls");
    titleBarBare();
    string nimi = "";

    cout << "Syota varaukselle nimi: ";
    cin >> nimi;

    cout << "Kiitos varauksesta " << nimi << "!!" << endl;
}

// Ohjelman sielu
int varauksenTeko() {

    srand(time(0));

    bool varausOn { true };
    int prompt1 = { 0 };
    float yhdenHengenMaara { 0 };
    float kahdenHengenMaara { 0 };
    float varattuYhden { 0 };
    float varattuKahden { 0 };
    float oidenMaara { 1 };

    system("cls");
    int randomNmb { 0 };

    // Huonemäärän haku
    do {

        randomNmb = randomNumberRooms();
    } while (randomNmb % 2 != 0);

    // Yhden ja kahden hengen huoneet
    float yhdenHengen = randomNmb / 2;
    float kahdenHengen = yhdenHengen;


    // Looppi huoneiden varauksille
    while (varausOn){   
        titleBarBare();
        cout << "Huoneita vapaana: " << randomNmb << endl;
        cout << "Joista yhden hengen huoneita on: " << yhdenHengen << endl;
        cout << "Kahden hengen huoneita on: " << kahdenHengen << "\n" << endl;
        cout << "Varatut huoneet:" << endl;
        cout << "1-Hengen(" << yhdenHengenHinta << "eur):" << varattuYhden << endl;
        cout << "2-Hengen(" << kahdenHengenHinta << "eur):" << varattuKahden << endl;
        cout << "Oiden maara: " << oidenMaara << " yota." << "\n" << endl;

        cout << "Valitse huone tai lisaa oita!" << endl;
        cout << "|1. Yhden hengen huone| |2. kahden hengen huone| |3. Valitse puolestani| |4. Lisaa yo| |5. Esikatsele varausta|" << endl;
        cout << "|6. Sulje ohjelma     |" << endl;
        cout << ": ";
        prompt1 = validInput();

        // Tästä alkaa syötteen tarkastus ja toteutus
        if (prompt1 == 1){
            if (yhdenHengen < 1){
                cout << "Yhden hengen huoneet loppu..";
                system("pause");
                system("cls");
            }
            else {
                randomNmb--;
                yhdenHengen--;
                varattuYhden++;
                system("cls");
            }
        }
        // Kahden hengen huoneet
        else if (prompt1 == 2){
            if (kahdenHengen < 1){
                cout << "Kahden hengen huoneet loppu..";
                system("pause");
                system("cls");
            }
            else {
                randomNmb--;
                kahdenHengen--;
                varattuKahden++;
                system("cls");
            }
        }
        // Satunnainen huone
        else if (prompt1 == 3){

            int randomNmb2 = rand() % 2;

            if (randomNmb2 == 1) {
                if (yhdenHengen < 1){

                    if (kahdenHengen < 1) {
                        cout << "Huoneet loppu.." << endl;
                        system("pause");
                        system("cls");
                    }
                    else {
                        randomNmb--;
                        kahdenHengen--;
                        varattuKahden++;
                        system("cls");
                    }

                }
                else {
                    randomNmb--;
                    yhdenHengen--;
                    varattuYhden++;
                    system("cls");

                }

            }
            else {
                if (kahdenHengen < 1) {
                    if (yhdenHengen < 1) {
                        cout << "Huoneet loppu.." << endl;
                        system("pause");
                        system("cls");
                    }
                    else {
                        randomNmb--;
                        yhdenHengen--;
                        varattuYhden++;
                        system("cls");
                    }
                }
                else {
                    randomNmb--;
                    kahdenHengen--;
                    varattuKahden++;
                    system("cls");
                }
            }
        }
        // Öiden määrien lisääminen
        else if (prompt1 == 4){
            oidenMaara++;
            system("cls");
        }
        // Varauksen esikatselu
        else if (prompt1 == 5){
            float alennusProsLaskuun { 1 };
            system("cls");
            titleBarBare();
            int alennusPros = rand() % 3;
            switch (alennusPros){
                case 1:
                    alennusPros = alennus0;
                    alennusProsLaskuun = alennus0pros;
                    break;
                case 2:
                    alennusPros = alennus10;
                    alennusProsLaskuun = alennus10pros;
                    break;
                case 3:
                    alennusPros = alennus20;
                    alennusProsLaskuun = alennus20pros;
                    break;
            }
            summary:
            cout << "|1. Takaisin| |2. Siirry maksamaan| |3. Poistu|\n" << endl;

            float yhdenYhtHinta = yhdenHengenHinta * varattuYhden;
            float kahdenYhtHinta = kahdenHengenHinta * varattuKahden;
            cout << "Varauksen yhteenveto:" << endl;
            cout << "Yhden hengen huoneiden maara: " << varattuYhden << " hinta: " << yhdenYhtHinta << endl;
            cout << "Kahden henhen huoneiden maara: " << varattuKahden << " hinta: " << kahdenYhtHinta << endl;
            cout << "Oiden maara: " << oidenMaara << " yota." << endl;
            cout << "Alennusprosentti: " << alennusPros << "%" << endl;

            float yhteishinta = yhdenYhtHinta + kahdenYhtHinta;
            yhteishinta = yhteishinta * oidenMaara;
            float alennettuYhteishinta = yhteishinta * alennusProsLaskuun;
            cout << "Yhteishinta: " << alennettuYhteishinta << " eur" << endl;
            cout << ": ";
            int prompt2 = validInput();

            switch (prompt2){
                case 1:
                    break;
                case 2:
                    system("cls");
                    maksamaan();
                    varausOn = false;
                    break;
                case 3:
                    system("cls");
                    return 0;
                default:
                    cout << "Syotteessa virhe...";
                    system("pause");
                    goto summary;
            }
        }

        else if (prompt1 == 6){
            cout << "Lopetetaan.." << endl;
            sleep_for(1s);
            varausOn = false;
            return 0;
        }
        // Syötteen tarkastus
        else {
            cout << "Virhe syotteessa..";
            sleep_for(2s);
            system("cls");
        }

    }

return 1;
}

// Pääohjelma
int main() {
    int valinta1 { 0 };
    titleBar();
    cout << ": ";
    valinta1 = validInput();

    start:

    // Varauksen teko aliohjelman aloittaminen
    if (valinta1 == 1){
        varauksenTeko();
    }

    else if (valinta1 == 2){

    }

    // Syötteen tarkastus
    else {
        cout << "Virhe syotteessa.. Tarkoititko kenties 1 tai 2?";
        goto start;
    }

    system("pause");

return 0;
}