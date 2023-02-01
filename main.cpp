// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT14L
// Names: ANG ZHE JIE | TAM LI XUAN|
// IDs: 1211101851 | 1211101186 |
// Emails: 1211101851@student.mmu.edu.my | 1211101186@student.mmu.edu.my |
// Phones: 0167099970 | 0176682752 |
// *********************************************************

#include <string>
#include <cctype>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>

using namespace ::std;

#define HEIGHT 3;
#define WIDTH 3;

int x = 3;
int y = 3;
class Character
{
public:
    class Alien
    {
    private:
        int alienLife[1] = {70};  // Original life of the alien.
        int alienAttack[6] = {100, 20, 20, 20, 20, 20};
        int alienLifeSize = 1;
        int alienAttackSize = 6;

    public:
        void setLife(int life)
        {
            alienLife[alienLifeSize] = life;
            alienLifeSize++;
        }

        void clearLife()
        {
            alienLifeSize = 0;
        }

        int getLife(int index)
        {
            return alienLife[index];
        }

        int sizeLife()
        {
            return alienLifeSize;
        }

        void setAttack(int attack)
        {
            alienAttack[alienAttackSize] = attack;
            alienAttackSize++;
        }

        int getAttack(int index)
        {
            return alienAttack[index];
        }

        int sizeAttack()
        {
            return alienAttackSize;
        }

        int accumulateAttack()
        {
            int sum = 0;
            for (int i = 0; i < alienAttackSize; i++)
            {
                sum += alienAttack[i];
            }
            return sum;
        }

        void clearAttack()
        {
            alienAttackSize = 0;
        }
    };
    class Zombie
    {
    private:
        int zombieNo[0];     
        int zombieLife[0];   
        int zombieAttack[2] = {10, 15}; 
        int zombieRange[5] = {1, 2, 3, 4, 5}; 
        int zombieNoSize = 0;
        int zombieLifeSize = 0;
        int zombieAttackSize = 2;
        int zombieRangeSize = 5;

    public:
        void setZombie(int zombieID)
        {
            zombieNo[zombieNoSize] = zombieID;
            zombieNoSize++;
        }

        int getZombie(int index)
        {
            return zombieNo[index];
        }

        int sizeZombie()
        {
            return zombieNoSize;
        }

        void setLife(int life)
        {
            zombieLife[zombieLifeSize] = life;
            zombieLifeSize++;
        }

        int getLife(int index)
        {
            return zombieLife[index];
        }

        void insertLife(int newLife, int position)
        {
            for (int i = zombieLifeSize; i > position; i--)
            {
                zombieLife[i] = zombieLife[i - 1];
            }
            zombieLife[position] = newLife;
            zombieLifeSize++;
        }

};
};

void savegame()
{
    fstream FileName;
    FileName.open("save.txt", ios::out);
    if (!FileName)
    {
        cout << " Error while creating the file ";
    }
    else
    {
        cout << "File created and data got written to file";
        FileName << "Alien vs zombie";
        FileName.close();
    }
}

void command(int cmd)
{
    cout << "Please enter Your command";
    cin >> cmd;
}

void help()
{
    cout << "Arrow(^ , < , > , v) ——> Changes Alienâ€™s direction of movement and add 20 damage to alien." << endl
         << "h ——> Adds 20 life to Alien." << endl
         << "p ——> instantly inflicts 10 damage to Zombie when hit by Alien." << endl
         << "r ——> 1. Hides a game object (except Rock and Trail)beneath it." << endl
         << "      2.Reveals the hidden game object when hit by Alien." << endl
         << "      3. Stops the Alien from moving." << endl
         << "space ——> Just an empty space on the board." << endl
         << "trail ——> 1. Left by Alien when it moves." << endl
         << "          2. Reset to a random game object (except the Trail) after Alien/’s turn ends." << endl
         << endl
         << "Press any key to Continue ";
    getch();
    system("PAUSE");
}

void newgame(int n, int h, int width, int height, int a, int b, int row, int column, int z)
{
    std::system("CLS");
    string obj[11] = {
        " ",
        " ",
        " ",
        " ",
        "r",
        "p",
        "H",
        "^",
        "<",
        ">",
        "v",
    };
    srand(time(NULL));
    int nRow;
    int nColumn;
    cout << "number of Row: ";
    cin >> nRow;
    if(nRow<3 or nRow>9)
    {
        cout<<"please enter a odd number between 3 to 9";
        cin>> nRow ;
    }
    else if (nRow % 2 == 0)
    {
        cout<<"please enter a odd number between 3 to 9";
        cin>> nRow ;
    }

    cout << "number of column: ";
    cin >> nColumn;
    if(nColumn<3 or nColumn>9)
    {
        cout<<"please enter a odd number between 3 to 9";
        cin>> nColumn ;
    }
    else if (nRow % 2 == 0)
    {
        cout<<"please enter a odd number between 3 to 9";
        cin>> nColumn ;
    }

    width = nRow + 1;
    height = nColumn + 1;
    column = nColumn;
    int centerColumn = (nColumn + 1) / 2;
    int centerRow = (nRow + 1) / 2;
    int numZombies;
    cout << "Enter number of zombies: ";
    cin >> numZombies;
    if (numZombies>3 or numZombies<0)
    {
        cout<<"please enter a number between 1-3"<<endl;
        cin >> numZombies;

    }

    string zombies[numZombies];

    a = nRow + 1;
    b = nColumn;

    while (a > 0)
    {
        cout << " ";
        for (int x = 0; x < width; x++)
        {
            cout << "#";
            if (x < height - 1)
            {
                cout << "-";
            }
        }
        a--;

        cout << endl;

        if (b > 0)
        {

            cout << "";
            for (int y = 0; y < width; y++)
            {

                if ((y + 1) == 1)
                {
                    cout << (row + 1);
                    row++;
                }

                cout << "|";
                for (int i = 0; i < numZombies; i++)
                {
                    zombies[i] = "z";
                }

                if (y < width - 1)
                {
                    if (row == centerRow && y == centerColumn - 1)
                    {
                        cout << "A";
                    }
                    else
                    {
                        int randIndex = rand() % (numZombies + 11);
                        if (randIndex >= 11)
                        {
                            cout << zombies[randIndex - 11];
                        }
                        else
                        {
                            cout << obj[randIndex];
                        }
                    }
                }
            }
            b--;
            cout << endl;
        }
        else
        {
            cout << "  ";
            for (int c = 1; c <= column; c++)
            {
                cout << c << " ";
            }
        }
    }
    cout<< endl;
}

void loadgame()
{
    cout << "Alien VS Zombies" << endl;
}

int main()
{
    int n;
    int h;
    int width = 4;
    int height = 4;
    int a = 4; // times (#)
    int b = 3; // times (|)
    int row = 0;
    int column = 3;
    int z = 0;
    int cmd;

    while (true)
    {
        std::system("CLS");
        cout << "Alien VS Zombies" << endl
             << "1. New Game" << endl
             << "2. Load Game" << endl
             << "3. Quit" << endl
             << endl
             << "Type in the options Number to start your adventure" << endl
             << "Your Choice is = " << endl;

        cin >> n;
        if (n == 1)
        {
            newgame(n, h, width, height, a, b, row, column, z);
            system("pause");
    
        }

        else if (n == 2)
        {
            loadgame();
            break;
        }

        else if (n == 3)
        {
            break;
        }

        else
        {
            std::system("CLS");
            cout << endl
                 << "We are very sorry, Your input is unable to detect" << endl
                 << "Please Try Again later......" << endl
                 << endl
                 << "press any key to continue~~~~" << endl;
            getch();
        }
    }
}
