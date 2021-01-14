#include <iostream>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\nEnter the right code to continue!\n\n";
}

bool PlayGame(int Difficulty)
{

    PrintIntroduction(Difficulty);


    const int CodeA = 1;
    const int CodeB = 2;
    const int CodeC = 3;


    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;


    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to: " << CodeProduct << std::endl;


    int GuessA, GuessB{}, GuessC{};
    std::cin >> GuessA >> GuessB >> GuessC; // this is the fix, literally.


    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;


    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n Well done agent! You extracted a file! ";
        return true;
    }
    else
    {
        std::cout << "\n You entered the wrong code, keep trying before you are caught! ";
        return false;
    }
}

int main()
{

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }

    }

    std::cout << " \n Well done agent! You got all the files, get out of there! \n";
    return 0;
}