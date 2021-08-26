// Wise_Quotes_App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>


void display_quotes(std::ifstream& in_file);
void add_quotes(std::ofstream& out_file);
void display_menu(std::ofstream& out_file, std::ifstream& in_file);
void quit();
char option;

int main()
{
    std::cout << "***************************Welcome to The Wise Quotes App***************************************\n";
    std::ofstream out_file;
    std::ifstream in_file;
   
    display_menu(out_file, in_file);
    return 0;
}

void display_quotes(std::ifstream &in_file) {
    system("CLS");
    char c;
    in_file.open("quotes.txt");

    if (in_file.is_open()) {
        std::cout << "\t\t\tThese are your available quotes\n";
        while (in_file.get(c)) {
            std::cout << c;
        }
    }
    
    in_file.close();
}

void add_quotes(std::ofstream &out_file) {
    system("CLS");
    out_file.open("quotes.txt", std::ios::app);

    if (out_file.is_open()) {
        std::string date;
        std::string quote;
        std::string author;
        int count{ 0 };

        std::cout << "How many quotes would you like to add today?: ";
        std::cin >> count;

        for (int i{ 1 }; i <= count;i++) {
            std::cout << "Quote " << i << ":" << std::endl;
            std::cin.ignore(1, '\n');
            std::getline(std::cin, quote);
            out_file << "Quote: " << quote << std::endl;

            std::cout << "Author: ";
            std::getline(std::cin, author);
            out_file << "by " << author << std::endl;

            std::cout << "Date: ";
            std::getline(std::cin, date);
            out_file << "Date: " << date << std::endl << std::endl;

            std::cout << "Quote successfully added! " << std::endl;
        }
    }
    out_file.close();

}

void display_menu(std::ofstream &out_file, std::ifstream &in_file) {
    if (option != '0') {
        std::cout << "1 - Add a Quote\n2 - View all Quotes\n0 - Quit the app\nChoice: ";
        std::cin >> option;

        switch (option) {
        case '1':
        {
            add_quotes(out_file);
            display_menu(out_file, in_file);
        }
        break;
        case '2':
        {
            display_quotes(in_file);
            display_menu(out_file, in_file);
        }
        break;
        case'0':
        {
            quit();
            display_menu(out_file, in_file);
        }
        break;

        default:
        {
            std::cout << "Kindly enter a valid option";
            display_menu(out_file, in_file);
        }
        }
    }
}

void quit() {
    system("CLS");
    std::cout << "Good-Bye\t\tYour quotes are save with us";
    option = '0';

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
