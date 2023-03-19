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

int randRange (int low, int high);
size_t ft_strlen(int num);
void play(std::string number, int attempts);

int main(void)
{
    std::string attempts_s;
    srand( time( NULL ) );
    std::string low;
    std::string high;
    std::string number;
    std::cout << "Welcome in the mini guess game" << std::endl;
    std::cout << "now enter the range of the number to guess" << std::endl;
    std::cout << "the " << F_BLUE << "minimum" << F_NONE << "(included) : ";
    std::cin >> low;
    std::cout << "the " << F_BLUE << "maximum" << F_NONE << "(included) : ";
    std::cin >> high;
    std::cout << "Now I let you choose how much attempts you can have before " << RED << "Game Over : " << F_NONE;
    std::cin >> attempts_s;
    number = std::to_string(randRange(stoi(low), stoi(high)));
    play(number, stoi(attempts_s));
}

void play(std::string number, int attempts)
{
    int i = 0;
    std::string input;
    int number_i = stoi(number);
    int input_i;
    while (input != number && attempts != 0)
    {
        std::cout << "you have " << RED << attempts << F_NONE << " attempts left" << std::endl;
        std::cout << "value you want to test: ";
        std::cin >> input;
        input_i = stoi(input);
        if (number_i > input_i)
        {
            std::cout << "Too " << F_YELLOW << "low" << F_NONE << std::endl;
            attempts--;
            i++;
        }
        else if (number_i < input_i)
        {
            std::cout << "Too " << F_YELLOW << "High" << F_NONE << std::endl;
            attempts--;
            i++;
        }
        else
        {
            i++;
            std::cout << "Congratulation you find the number ! : " << GREEN << number << F_NONE <<std::endl;
            std::cout << "in " << GREEN << i << F_NONE << " attempts !" << std::endl;
            return ;
        }
    }
    std::cout << RED << "Game Over" << std::endl;
}

int randRange (int low, int high)
{
    int a;
    char *tmp;

	// we get a random number, get it to be between 0 and the difference
	// between high and low, then add the lowest possible value 
	a = rand() % ( high - low ) + low;
    return (a);
}

size_t ft_strlen(int num)
{
    size_t n = 0;
    int a = 0;

    if (num < 0)
    {
        n++;
        num = -num;
    }
    while (num != 0)
    {
        n++;
        num /= 10;
    }
    return (n);
}