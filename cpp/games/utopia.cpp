#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using std::srand, std::endl, std::cout, std::cin, std::string;



auto score = new int();

class PlanetGeneration
// A class that generates a random planet

{
public:
    void temperatureGen()
    {
        srand((long)time(NULL));
        string usingTemp;
        string tempHazard;
        float currentTemperature = (rand() % 100 - 30);
        cout << endl
             << "Current Temperature: " << currentTemperature << "C (Celsius)" << endl;
        if (currentTemperature >= 10 && currentTemperature <= 25)
        {
            score += 500;
        }
        if (currentTemperature >= 60)
        {
            score -= (rand() % 1001);
        }
        else
        {
            score -= (rand() % 500);
        }
        cout << "Points: " << score << endl;
    }
    void planetNameGen()
    {
        srand((long)time(NULL));
        int x = 0 + (rand() % 11);
        int z = 0 + (rand() % 11);
        int a = 0 + (rand() % 11);
        string prefix[] = {"Co", "Si", "P", "Ri", "Do", "Mhe", "Pah", "Ly", "Fre", "Dol", "Met"};
        string core[] = {"uni", "opu", "anu", "uyaa", "eqiu", "asa", "mo", "nu", "k", "p", "ti"};
        string suffix[] = {"ium", "ova", "suk", "nus", "lax", "zar", "ru", "lop", "ea", "on", "ka"};
        if ((rand() % 8) == (rand() % 8))
        {
            int y = 0 + (rand() % 13);
            string ext[] = {" Delta", " V", " III", " IV", " II", " I", " VI", " Delta-V", " Delta-III", " Delta-IV", " Delta-II", " Delta-I", " Delta-VI"};
            string randomPlanetName = prefix[x] + core[z] + suffix[a] + ext[y];
            cout << randomPlanetName;
        }
        else
        {
            string randomPlanetName = prefix[x] + core[z] + suffix[a];
            cout << randomPlanetName;
        }
    }

    void waterContent()
    {
        srand((long)time(NULL));
        float randomNumber = (rand() % 101) * 1.011;
        cout << "Surface water content: ";
        if (randomNumber < 10)
        {
            cout << "Planet has very scarce amounts of water, either in ice caps or water pockets that are beneath the surface. (" << randomNumber << "% Surface water content).";
            score += (rand() % 101);
        }
        else if (randomNumber >= 40 && randomNumber <= 80)
        {
            cout << randomNumber << "%";
            score += (rand() % 801);
        }
        else
        {
            cout << randomNumber << "%";
            score += (rand() % 201);
        }
        cout << endl
             << "Points: " << score;
        float number = 100;
        cout << endl
             << endl
             << "Surface landmass: " << number - randomNumber << "% compared to water content.";
        if (number - randomNumber >= 40 && number - randomNumber <= 60)
        {
            score += (rand() % 501);
        }
        else
        {
            score += (rand() % 201);
        }
        cout << endl
             << "Points: " << score;
    }
    void beauty()
    {
        std::srand((long)time(NULL));
        cout << "Planetary beauty: ";
        int randomNumber = (rand() % 5);
        if (randomNumber == 1)
        {
            cout << "Very pleasing to they eye.";
            score += (rand() % 250);
        }
        if (randomNumber == 2)
        {
            cout << "Pleasing to the eye.";
            score += (rand() % 150);
        }
        if (randomNumber == 3)
        {
            cout << "Displeasing to the eye.";
            score -= (rand() % 150);
        }
        if (randomNumber == 4)
        {
            cout << "Very displeasing to the eye.";
            score -= (rand() % 250);
        }
        cout << endl
             << "Points: " << score;
    }
    void moons()
    {   
        srand((long)time(NULL));
        int randomNumber = (rand() % 11);
        cout << "Orbiting bodies: " << randomNumber;
    }
    void hawking()
    {
        srand((long)time(NULL));
        int randomNumber = (rand() % 20) + 1;
        cout << "Hawking Radiation (20 LY radius): ";
        if (randomNumber == 5)
        {
            cout << "Detected! " << endl;
            score -= 700 + (rand() % 500);
        }
        else
        {
            cout << "Null" << endl;
        }
        cout << "Points: " << score << endl;
    }
    void planetVege()
    {
        int x = (rand() % 6);
        int randomNumber = (rand() % 6) + 1;
        string vegeType;
        if (randomNumber == 1)
        {
            vegeType = " Planet is mainly covered in alien plants, some of which are edible.";
            cout << "Planetary Vegetation: " << vegeType << endl;
            score += 350;
        }
        if (randomNumber == 2)
        {
            vegeType = " Planet is barren from any kind of vegetation, cultivation is likely near impossible.";
            cout << "Planetary Vegetation: " << vegeType << endl;
            score -= 500;
        }
        if (randomNumber == 3)
        {
            vegeType = " Planet thrives in many kinds of vegetation, alien fruits and vegetables enable this planet to be a perfect candidate for humans.";
            cout << "Planetary vegetation: " << vegeType << endl;
            score += 1000;
        }
        if (randomNumber == 4)
        {
            vegeType = " Planet contains vegetation which is extremely toxic to humans.";
            cout << "Planetary Vegetation: " << vegeType << endl;
            score -= 200;
        }
        if (randomNumber == 5)
        {
            vegeType = " Planet is barren of vegetation, but cultivation is possible.";
            cout << "Planetary Vegetation: " << vegeType << endl;
            score += 250;
        }
        if (randomNumber == 6)
        {
            srand((long)time(NULL));
            vegeType = " Planet has strange growing vegetation that is unknown to human taxonomy.";
            cout << "Planetary Vegetation: " << vegeType << endl;
            score += (rand() % 200);
        }
        cout << "Points: " << score << endl;
    }

    void planetAtmos()
    {

        string planetAtmosType;
        int randomNumber = (rand() % 5) + 1;
        if (randomNumber == 1)
        {
            planetAtmosType = " Perfectly breathable to humans.";
            cout << "Atmospheric Severity: " << planetAtmosType << endl;
            srand((long)time(NULL));
            score += (rand() % 1000);
        }
        if (randomNumber == 2)
        {
            planetAtmosType = " Unbreathable to humans.";
            cout << "Atmospheric Severity: " << planetAtmosType << endl;
            srand((long)time(NULL));
            score -= (rand() % 1000);
        }
        if (randomNumber == 3)
        {
            planetAtmosType = " Slightly breathable to humans.";
            cout << "Atmospheric Severity: " << planetAtmosType << endl;
            srand((long)time(NULL));
            score += (rand() % 100);
        }
        if (randomNumber == 4)
        {
            planetAtmosType = " Moderatley breathable.";
            cout << "Atmospheric Severity: " << planetAtmosType << endl;
            srand((long)time(NULL));
            score += (rand() % 200);
        }
        if (randomNumber == 5)
        {
            planetAtmosType = "Barely breathable... Dangerous.";
            cout << "Atmospheric Serverity: " << planetAtmosType << endl;
            srand((long)time(NULL));
            score -= (rand() % 500);
        }
        cout << "Points: " << score << endl;
    }
    void habitatedByAliens()
    {
        string habitated;
        int randomNumber = (rand() % 5) + 1;
        if (randomNumber == (rand() % 5) + 1)
        {
            if (randomNumber == 1)
            {
                string habitated = " An ancient alien civilization resides here, with a technological level that is extremely low. ";
                cout << "Fauna: " << habitated << endl;
                srand((long)time(NULL));
                score += (rand() % 200);
            }
            if (randomNumber == 2 && randomNumber == (rand() % 2) + 1)
            {
                string habitated = " This is a homeworld to a technologically advanced civilization. ";
                cout << "Fauna: " << habitated << endl;
                srand((long)time(NULL));
                score -= (rand() % 200);
            }
            if (randomNumber == 3)
            {
                string habitated = " Multiple different forms of bacteria and fungi exist here, we could learn from this.";
                cout << "Fauna: " << habitated << endl;
                srand((long)time(NULL));
                score += (rand() % 300);
            }
            if (randomNumber == 4)
            {
                string habitated = " Multiple different forms of walking, breathing and communicating species of alien animals live here, food source.";
                cout << "Fauna: " << habitated << endl;
                srand((long)time(NULL));
                score += (rand() % 500);
            }
            if (randomNumber == 5)
            {
                string habitated = " Unknown electromagnetic signal: ERROR*UNKNOWN*UNKNOWN*UNKNOWN*ERROR ";
                cout << "Fauna: " << habitated << endl;
                srand((long)time(NULL));
                score -= (rand() % 500);
            }
        }
        else
        {
            cout << "Fauna: Uninhabitated by any form of fauna." << endl;
        }
        cout << "Points: " << score << endl;
    }
};

int main()
{
    cout << endl
         << "Scanning for planets with suspected water content... " << endl
         << endl;
    char yn;
    cout << "A planet named: ";
    PlanetGeneration planetNameGenOBJ;
    planetNameGenOBJ.planetNameGen();
    cout << endl;
    PlanetGeneration temperatureGenOBJ;
    temperatureGenOBJ.temperatureGen();
    cout << endl;
    PlanetGeneration moonsOBJ;
    moonsOBJ.moons();
    cout << endl
         << endl;
    PlanetGeneration waterContentOBJ;
    waterContentOBJ.waterContent();
    cout << endl
         << endl;
    PlanetGeneration beautyOBJ;
    beautyOBJ.beauty();
    cout << endl
         << endl;
    PlanetGeneration planetVegeOBJ;
    planetVegeOBJ.planetVege();
    cout << endl;
    PlanetGeneration planetAtmosOBJ;
    planetAtmosOBJ.planetAtmos();
    cout << endl;
    PlanetGeneration planetHawkingOBJ;
    planetHawkingOBJ.hawking();
    cout << endl;
    PlanetGeneration habitatedByAliensOBJ;
    habitatedByAliensOBJ.habitatedByAliens();
    cout << endl;
    if (score <= 500 && score >= -499)
    {
        cout << "Score: " << score << ","
             << " It is dangerous for humans on ";
        PlanetGeneration planetNameGenOBJ;
        planetNameGenOBJ.planetNameGen();
        cout << "." << endl
             << endl
             << "deez nutz in yo mouth" << endl;
    }
    if (score <= -500)
    {
        cout << "Score: " << score << ","
             << " It is extremely dangerous for humans on ";
        PlanetGeneration planetNameGenOBJ;
        planetNameGenOBJ.planetNameGen();
        cout << "." << endl
             << endl
             << "SUS" << endl;
    }
    if (score >= 1000)
    {
        cout << "Score: " << score << ","
             << " Human life has the potential to thrive on ";
        PlanetGeneration planetNameGenOBJ;
        planetNameGenOBJ.planetNameGen();
        cout << "!" << endl
             << endl
             << "big balls" << endl;
    }
    else
    {
        cout << "Score: " << score << endl;
    }
    cout << endl;

    cin.get();
    return 0;
}
