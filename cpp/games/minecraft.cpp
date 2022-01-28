#include <iostream>
#include <cstdlib>
#include <ctime>


char block = char(219);
char weakblock = char(176);
char gradientblock = char(177);
char lineblock = char(178);
char blade = char(205);
char handle = char(206);
std::string cEquip = "";

char blocks[5] = {block, weakblock, gradientblock, lineblock};

int blockcount[5] = {0, 0, 0, 0};

std::string blocknames[5] = {"Stone", "Iron", "Copper", "Gold"};

std::string enemies[3] = {"Creeper", "Skeleton"};

int player(std::string equip = "Pickaxe")
{

    std::string indent = " ";

    for (int i = 0; i < rand() % 50; i++)
    {
        indent += " ";
    }

    std::cout << indent << "  " << blocks[0] << blocks[0] << std::endl
         << indent << "  " << blocks[3] << blocks[3] << std::endl
         << indent
         << blocks[0] << blocks[0] << blocks[0] << blocks[0] << std::endl
         << indent
         << blocks[0] << blocks[2] << blocks[2] << blocks[0] << std::endl
         << indent << blocks[3] << blocks[2] << blocks[2] << blocks[3];

    if (equip == "Sword")
    {
        std::cout << handle << blade << blade;
    }
    else if (equip == "Pickaxe")
    {
        std::cout << blade << blade << ")";
    }
    else if (equip == "Gold Wand")
    {
        std::cout << blade << blade << blade << "*";
    }

    std::cout << std::endl
         << indent << " " << blocks[2] << " " << blocks[2] << std::endl
         << indent << " " << blocks[0] << " " << blocks[0];
}

int enemy(std::string eType = "Creeper", std::string weapon = "")
{

    if (eType == "Creeper")
    {
        std::cout << std::endl
             << std::endl
             << "A Creeper appeared!" << std::endl
             << std::endl;

        std::cout << " " << char(223) << std::endl
             << char(221) << " " << char(221) << std::endl
             << " " << char(223) << " " << std::endl
             << " " << char(223) << std::endl
             << char(223) << char(223);
        if (weapon == "Gold Wand" || weapon == "Sword")
        {
            std::cout << std::endl
                 << "You beat the Creeper and got gunpowder!";
        }

        else
        {
            std::cout << std::endl
                 << "You were defeated by the Creeper!"
                 << " I guess a " << weapon << " isnt good enough!";
        }
    }

    if (eType == "Skeleton")
    {
        std::cout << std::endl
             << std::endl
             << "A Skeleton appeared!" << std::endl
             << std::endl;

        std::cout << "  " << char(219) << std::endl
             << char(221) << char(223) << " " << char(221) << std::endl
             << "  " << char(223) << "  " << std::endl
             << "  " << char(223) << std::endl
             << " " << char(221) << char(221) << std::endl;
        if (weapon == "Gold Wand")
        {
            std::cout << std::endl
                 << "You beat the Skeleton and got a bone!";
        }

        else
        {
            std::cout << std::endl
                 << "You were defeated by the Skeleton!"
                 << " I guess a " << weapon << " isnt good enough!";
        }
    }
}

int createWorld(bool create = false)
{
    std::cout << std::endl;
    for (int i = i; i < 300; i++)
    {
        int a = rand() % 8;

        if (a > 4)
        {
            std::cout << " ";
            continue;
        }
        else if (a == 0)
        {
            blockcount[0]++;
        }
        else if (a == 1)
        {
            blockcount[1]++;
        }
        else if (a == 2)
        {
            blockcount[2]++;
        }
        else if (a == 3)
        {
            blockcount[3]++;
        }

        std::cout << blocks[a];

        if (blockcount[0] >= 20)
        {
        }

        else if (blockcount[1] >= 30)
        {
        }

        else if (blockcount[2] >= 35)
        {
        }

        else if (blockcount[3] >= 40)
        {
        }
    }

    std::cout << std::endl;
}

int main()
{
    srand(time(NULL));

    std::cout << "MINECRAFT - SOLOLEARN EDITION" << std::endl
         << std::endl;

    int myplayer = player(cEquip);
    int world = createWorld(true);

    std::cout << std::endl
         << "In this world:" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        std::cout << blockcount[i] << " " << blocknames[i] << " " << blocks[i] << std::endl;
    }

    std::cout << std::endl
         << "Log: " << std::endl
         << std::endl;

    if (blockcount[0] >= 20)
    {
        std::cout << "You crafted a Stone Sword with " << 20 << " Stone!";
        cEquip = "Sword";
    }
    else
    {
        std::cout << "You dont have enough Stone in this world to craft a Stone Sword! You need 20.";
    }

    std::cout << std::endl
         << std::endl;

    if (blockcount[1] >= 30)
    {
        std::cout << "You crafted a Iron Pickaxe with " << 30 << " Iron!";
        cEquip = "Pickaxe";
    }
    else
    {
        std::cout << "You dont have enough Iron in this world to craft a Iron Pickaxe! You need 30.";
    }

    std::cout << std::endl
         << std::endl;

    if (blockcount[2] >= 35)
    {
        std::cout << "You crafted a Copper Sword with " << 35 << " Copper!";
        cEquip = "Sword";
    }
    else
    {
        std::cout << "You dont have enough Copper in this world to craft a Copper Sword! You need 35.";
    }

    std::cout << std::endl
         << std::endl;

    if (blockcount[3] >= 40)
    {
        std::cout << "You crafted a Gold Wand with " << 40 << " Gold!";
        cEquip = "Gold Wand";
    }
    else
    {
        std::cout << "You dont have enough Gold in this world to craft a Gold Wand! You need 40.";
    }

    std::cout << std::endl
         << std::endl;

    int newPlyr = player(cEquip);

    std::cout << std::endl
         << "Time to battle!";

    int creeper = enemy(enemies[(rand() % 2)], cEquip);

    std::cout << std::endl
         << "" << std::endl
         << std::endl
         << "Make sure to run again for another result!!!";

    return 0;
}