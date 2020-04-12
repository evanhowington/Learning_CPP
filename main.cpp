/*
 * Code Created while learning the C++ syntax
 */


//Preprocessor Directives
#include <iostream>
#include <ctime>
void PrintIntroduction(int Difficulty)
{
    std::cout << "You are a secret agent breaking into a Level " << Difficulty; // prints string
    std::cout << std::endl; // new line
    std::cout << "secure server room...Enter the correct code to continue..."; // prints string
    std::cout << std::endl; // line
}

bool PlayGame(int Difficulty) // "void" means this function returns no data
{
    PrintIntroduction(Difficulty);

    // declaring variables "a", "b", and "c" as integers and initializing them with the respective values
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    // performing basic mathematical operations
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // prints the value of the variable "a" on a new line, then inserts a blank line beneath it.
    std::cout << std::endl;
    std::cout << CodeSum << std::endl;
    std::cout << CodeProduct << std::endl;

    // declare variables
    int GuessA, GuessB, GuessC;

    // give hints to the player and ask them to guess what the codes are
    /*
     * NOTE:  the "\n" only works at the beginning of a line when there is a variable used at the
     * end of the line.  If there is a variable at the end of the line one must use the "<< std::endl"
     * convention, or add a string space '<< "\n"'
     * */
    std::cout << "\nThe codes add up to: "<< CodeSum << std::endl;
    std::cout << "\nThe codes multiply to give: "<< CodeProduct << std::endl;
    std::cout << "\nPlease enter three integers each separated by a space, then press the Enter key" << std::endl;

    // assigns the user input to the variables in order
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    // commented out to not use
    // std::cout << "You entered: GuessA = " << GuessA << ", GuessB = "<< GuessB << ", GuessC = "<< GuessC;

    // calculates the player's guess
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // conditionals to check if the player's guesses add up and multiply to the correct values.
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou win, and get to move on to the next level!\n";
        return true;
    }
    else
    {
        std::cout << "\nYou entered the wrong code, please try again!\n";
        return false;
    }
}

int main() // This is the function that runs.  If its not in here it will not execute.
{
    srand(time(NULL)); // create new random sequence based on time of day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop the game until all levels are completed
    {

        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();  // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }

    }

    std::cout << "\n CONGRATULATIONS YOU WIN!";

    return 0;
}
