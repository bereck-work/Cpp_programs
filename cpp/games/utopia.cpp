#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int score;

class PlanetGeneration
// A class that generates a random planet

{
public:
    void temperatureGen()
    {
        std::srand((long)time(NULL));
        std::string usingTemp;
        std::string tempHazard;
        float currentTemperature = (rand() % 100 - 30);
        std::cout << std::endl
             << "Current Temperature: " << currentTemperature << "C (Celsius)" << std::endl;
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
        std::cout << "Points: " << score << std::endl;
    }
    void planetNameGen()
    {
        std::srand((long)time(NULL));
        int x = 0 + (rand() % 11);
        int z = 0 + (rand() % 11);
        int a = 0 + (rand() % 11);
        std::string prefix[] = {"Co", "Si", "P", "Ri", "Do", "Mhe", "Pah", "Ly", "Fre", "Dol", "Met"};
        std::string core[] = {"uni", "opu", "anu", "uyaa", "eqiu", "asa", "mo", "nu", "k", "p", "ti"};
        std::string suffix[] = {"ium", "ova", "suk", "nus", "lax", "zar", "ru", "lop", "ea", "on", "ka"};
        if ((rand() % 8) == (rand() % 8))
        {
            int y = 0 + (rand() % 13);
            std::string ext[] = {" Delta", " V", " III", " IV", " II", " I", " VI", " Delta-V", " Delta-III", " Delta-IV", " Delta-II", " Delta-I", " Delta-VI"};
            std::string randomPlanetName = prefix[x] + core[z] + suffix[a] + ext[y];
            std::cout << randomPlanetName;
        }
        else
        {
            std::string randomPlanetName = prefix[x] + core[z] + suffix[a];
            std::cout << randomPlanetName;
        }
    }

    void waterContent()
    {
        std::srand((long)time(NULL));
        float randomNumber = (rand() % 101) * 1.011;
        std::cout << "Surface water content: ";
        if (randomNumber < 10)
        {
            std::cout << "Planet has very scarce amounts of water, either in ice caps or water pockets that are beneath the surface. (" << randomNumber << "% Surface water content).";
            score += (rand() % 101);
        }
        else if (randomNumber >= 40 && randomNumber <= 80)
        {
            std::cout << randomNumber << "%";
            score += (rand() % 801);
        }
        else
        {
            std::cout << randomNumber << "%";
            score += (rand() % 201);
        }
        std::cout << std::endl
             << "Points: " << score;
        float number = 100;
        std::cout << std::endl
             << std::endl
             << "Surface landmass: " << number - randomNumber << "% compared to water content.";
        if (number - randomNumber >= 40 && number - randomNumber <= 60)
        {
            score += (rand() % 501);
        }
        else
        {
            score += (rand() % 201);
        }
        std::cout << std::endl
             << "Points: " << score;
    }
    void beauty()
    {
        std::srand((long)time(NULL));
        std::cout << "Planetary beauty: ";
        int randomNumber = (rand() % 5);
        if (randomNumber == 1)
        {
            std::cout << "Very pleasing to they eye.";
            score += (rand() % 250);
        }
        if (randomNumber == 2)
        {
            std::cout << "Pleasing to the eye.";
            score += (rand() % 150);
        }
        if (randomNumber == 3)
        {
            std::cout << "Displeasing to the eye.";
            score -= (rand() % 150);
        }
        if (randomNumber == 4)
        {
            std::cout << "Very displeasing to the eye.";
            score -= (rand() % 250);
        }
        std::cout << std::endl
             << "Points: " << score;
    }
    void moons()
    {
        std::srand((long)time(NULL));
        int randomNumber = (rand() % 11);
        std::cout << "Orbiting bodies: " << randomNumber;
    }
    void hawking()
    {
        std::srand((long)time(NULL));
        int randomNumber = (rand() % 20) + 1;
        std::cout << "Hawking Radiation (20 LY radius): ";
        if (randomNumber == 5)
        {
            std::cout << "Detected! " << std::endl;
            score -= 700 + (rand() % 500);
        }
        else
        {
            std::cout << "Null" << std::endl;
        }
        std::cout << "Points: " << score << std::endl;
    }
    void planetVege()
    {
        int x = (rand() % 6);
        int randomNumber = (rand() % 6) + 1;
        std::string vegeType;
        if (randomNumber == 1)
        {
            vegeType = " Planet is mainly covered in alien plants, some of which are edible.";
            std::cout << "Planetary Vegetation: " << vegeType << std::endl;
            score += 350;
        }
        if (randomNumber == 2)
        {
            vegeType = " Planet is barren from any kind of vegetation, cultivation is likely near impossible.";
            std::cout << "Planetary Vegetation: " << vegeType << std::endl;
            score -= 500;
        }
        if (randomNumber == 3)
        {
            vegeType = " Planet thrives in many kinds of vegetation, alien fruits and vegetables enable this planet to be a perfect candidate for humans.";
            std::cout << "Planetary vegetation: " << vegeType << std::endl;
            score += 1000;
        }
        if (randomNumber == 4)
        {
            vegeType = " Planet contains vegetation which is extremely toxic to humans.";
            std::cout << "Planetary Vegetation: " << vegeType << std::endl;
            score -= 200;
        }
        if (randomNumber == 5)
        {
            vegeType = " Planet is barren of vegetation, but cultivation is possible.";
            std::cout << "Planetary Vegetation: " << vegeType << std::endl;
            score += 250;
        }
        if (randomNumber == 6)
        {
            std::srand((long)time(NULL));
            vegeType = " Planet has strange growing vegetation that is unknown to human taxonomy.";
            std::cout << "Planetary Vegetation: " << vegeType << std::endl;
            score += (rand() % 200);
        }
        std::cout << "Points: " << score << std::endl;
    }

    void planetAtmos()
    {

        std::string planetAtmosType;
        int randomNumber = (rand() % 5) + 1;
        if (randomNumber == 1)
        {
            planetAtmosType = " Perfectly breathable to humans.";
            std::cout << "Atmospheric Severity: " << planetAtmosType << std::endl;
            std::srand((long)time(NULL));
            score += (rand() % 1000);
        }
        if (randomNumber == 2)
        {
            planetAtmosType = " Unbreathable to humans.";
            std::cout << "Atmospheric Severity: " << planetAtmosType << std::endl;
            std::srand((long)time(NULL));
            score -= (rand() % 1000);
        }
        if (randomNumber == 3)
        {
            planetAtmosType = " Slightly breathable to humans.";
            std::cout << "Atmospheric Severity: " << planetAtmosType << std::endl;
            std::srand((long)time(NULL));
            score += (rand() % 100);
        }
        if (randomNumber == 4)
        {
            planetAtmosType = " Moderatley breathable.";
            std::cout << "Atmospheric Severity: " << planetAtmosType << std::endl;
            std::srand((long)time(NULL));
            score += (rand() % 200);
        }
        if (randomNumber == 5)
        {
            planetAtmosType = "Barely breathable... Dangerous.";
            std::cout << "Atmospheric Serverity: " << planetAtmosType << std::endl;
            std::srand((long)time(NULL));
            score -= (rand() % 500);
        }
        std::cout << "Points: " << score << std::endl;
    }
    void habitatedByAliens()
    {
        std::string habitated;
        int randomNumber = (rand() % 5) + 1;
        if (randomNumber == (rand() % 5) + 1)
        {
            if (randomNumber == 1)
            {
                std::string habitated = " An ancient alien civilization resides here, with a technological level that is extremely low. ";
                std::cout << "Fauna: " << habitated << std::endl;
                std::srand((long)time(NULL));
                score += (rand() % 200);
            }
            if (randomNumber == 2 && randomNumber == (rand() % 2) + 1)
            {
                std::string habitated = " This is a homeworld to a technologically advanced civilization. ";
                std::cout << "Fauna: " << habitated << std::endl;
                std::srand((long)time(NULL));
                score -= (rand() % 200);
            }
            if (randomNumber == 3)
            {
                std::string habitated = " Multiple different forms of bacteria and fungi exist here, we could learn from this.";
                std::cout << "Fauna: " << habitated << std::endl;
                std::srand((long)time(NULL));
                score += (rand() % 300);
            }
            if (randomNumber == 4)
            {
                std::string habitated = " Multiple different forms of walking, breathing and communicating species of alien animals live here, food source.";
                std::cout << "Fauna: " << habitated << std::endl;
                std::srand((long)time(NULL));
                score += (rand() % 500);
            }
            if (randomNumber == 5)
            {
                std::string habitated = " Unknown electromagnetic signal: ERROR*UNKNOWN*UNKNOWN*UNKNOWN*ERROR ";
                std::cout << "Fauna: " << habitated << std::endl;
                std::srand((long)time(NULL));
                score -= (rand() % 500);
            }
        }
        else
        {
            std::cout << "Fauna: Uninhabitated by any form of fauna." << std::endl;
        }
        std::cout << "Points: " << score << std::endl;
    }
};

int main()
{
    std::cout << std::endl
         << "Scanning for planets with suspected water content... " << std::endl
         << std::endl;
    char yn;
    std::cout << "A planet named: ";
    PlanetGeneration planetNameGenOBJ;
    planetNameGenOBJ.planetNameGen();
    std::cout << std::endl;
    PlanetGeneration temperatureGenOBJ;
    temperatureGenOBJ.temperatureGen();
    std::cout << std::endl;
    PlanetGeneration moonsOBJ;
    moonsOBJ.moons();
    std::cout << std::endl
         << std::endl;
    PlanetGeneration waterContentOBJ;
    waterContentOBJ.waterContent();
    std::cout << std::endl
         << std::endl;
    PlanetGeneration beautyOBJ;
    beautyOBJ.beauty();
    std::cout << std::endl
         << std::endl;
    PlanetGeneration planetVegeOBJ;
    planetVegeOBJ.planetVege();
    std::cout << std::endl;
    PlanetGeneration planetAtmosOBJ;
    planetAtmosOBJ.planetAtmos();
    std::cout << std::endl;
    PlanetGeneration planetHawkingOBJ;
    planetHawkingOBJ.hawking();
    std::cout << std::endl;
    PlanetGeneration habitatedByAliensOBJ;
    habitatedByAliensOBJ.habitatedByAliens();
    std::cout << std::endl;
    if (score <= 500 && score >= -499)
    {
        std::cout << "Score: " << score << ","
             << " It is dangerous for humans on ";
        PlanetGeneration planetNameGenOBJ;
        planetNameGenOBJ.planetNameGen();
        std::cout << "." << std::endl
             << std::endl
             << "deez nutz in yo mouth" << std::endl;
    }
    if (score <= -500)
    {
        std::cout << "Score: " << score << ","
             << " It is extremely dangerous for humans on ";
        PlanetGeneration planetNameGenOBJ;
        planetNameGenOBJ.planetNameGen();
        std::cout << "." << std::endl
             << std::endl
             << "SUS" << std::endl;
    }
    if (score >= 1000)
    {
        std::cout << "Score: " << score << ","
             << " Human life has the potential to thrive on ";
        PlanetGeneration planetNameGenOBJ;
        planetNameGenOBJ.planetNameGen();
        std::cout << "!" << std::endl
             << std::endl
             << "big balls" << std::endl;
    }
    else
    {
        std::cout << "Score: " << score << std::endl;
    }
    std::cout << std::endl;

    std::cin.get();
    return 0;
}