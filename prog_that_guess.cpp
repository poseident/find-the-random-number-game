#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

#ifndef COLOR
# define COLOR

# define CLEAR		"\x1B[2J\x1B[H"
# define F_NONE		"\033[0;37m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define CYANE		"\033[1;36m"
# define F_BOLD		"\033[1m"	
# define F_YELLOW	"\033[1;33m"
# define F_BLUE		"\033[34m" 

#endif

void play(std::string minimum, std::string maximum, std::string find_number, std::string attempts);

int main(int argc, char **argv)
{
    std::string minimum;
    std::string maximum;
    std::string find_number;
    std::string attempts;
    std::string menu = "1";
    std::cout << "Welcome in the prog that play the guess number game" << std::endl;
    while (menu == "1")
    {
        std::cout << "Enter 1 to play or 2 to quit : ";
        std::cin >> menu;
        if (menu == "1")
        {
            std::cout << "minimum : "; std::cin >> minimum; std::cout << "\n";
            std::cout << "maximum : "; std::cin >> maximum; std::cout << "\n";
            std::cout << "number to find : "; std::cin >> find_number; std::cout << "\n";
            std::cout << "attempts : "; std::cin >> attempts; std::cout << "\n";
            play(minimum, maximum, find_number, attempts);
        }
        else
            break;
    }
    std::cout << "bye bye" << std::endl;
    return (0);
}

void play(std::string minimum, std::string maximum, std::string find_number, std::string attempts)
{
    int minimum_i = std::stoi(minimum);
    int maximum_i = std::stoi(maximum);
    int find_number_i = std::stoi(find_number);
    int attempts_i = std::stoi(attempts);
    int mini = minimum_i;
    int maxi = maximum_i;
    int try_n = 0;
    int median = 0;
    median = (maxi - mini) / 2;
    while (attempts_i > 0)
    {
        std::cout << "try...:" << median << std::endl;
        if (find_number_i > median)
        {
            attempts_i--;
            try_n++;
            mini = median;
            median = maxi - ((maxi - mini) / 2);
            std::cout << "Too low" << std::endl;

        }
        else if (find_number_i < median)
        {
            attempts_i--;
            try_n++;
            maxi = median;
            median = mini + ((maxi - mini) / 2);
            std::cout << "Too High" << std::endl;
        }
        else if (median == find_number_i)
        {
            std::cout << "the number is : " << median << std::endl;
            std::cout << "attempts :" << try_n << std::endl;
            break;
        }
    }
}