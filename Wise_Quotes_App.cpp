// Wise_Quotes_App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>



void display_quotes(std::ifstream& in_file);
void add_quotes(std::ofstream& out_file, std::ifstream& in_file);
void display_menu(std::ofstream& out_file, std::ifstream& in_file);
void edit_quote(std::ofstream& out_file, std::ifstream& in_file);
void delete_quote(std::ofstream& out_file, std::ifstream& in_file);
void delete_quote(std::ofstream& out_file, std::ifstream& in_file);
void quit();
char option;

int main()
{
    std::cout << "\t\t***************************Welcome to The Wise Quotes App***************************************\n";
    std::ofstream out_file;
    std::ifstream in_file;
       display_menu(out_file, in_file);
    return 0;
}

void display_quotes(std::ifstream &in_file) {
    system("CLS");
    
    int quote_no{0};
    std::string quote;
    std::string author;
    std::string date;
    std::string word;

    in_file.open("quotes.txt");

    if (!in_file) {
        std::cout << "You have no quotes available yet!\n" << std::endl << std::endl;
    }

        std::cout << "\t\t\tThese are your available quotes\n";
        while (in_file>>word) {

           
            getline(in_file, quote);
            std::cout << "\nQuote-"<<quote_no<<": " << word << quote << std::endl;
            quote_no++;
            getline(in_file, author);
            std::cout << "By: " << author << std::endl;
            getline(in_file, date);
            std::cout << "Date: " << date << std::endl;
        }
    in_file.close();
}

void add_quotes(std::ofstream &out_file, std::ifstream &in_file) {

    system("CLS");
    out_file.open("quotes.txt", std::ios::app);
    

    if (out_file.is_open()) {
        std::string date;
        std::string quote;
        std::string author;
        bool done = false;
        std::string quote_no{  };
        int quote_no_value{};
        int count{ 0 };

        //Data Validation---------------->
        while(!done){
            std::cout << "\nHow many quotes would you like to add?: ";
            std::cin >> quote_no;
            std::istringstream validator{ quote_no };

            if (validator >> quote_no_value) {
                done = true;
            }

            else {
                std::cout << "Kindly enter an integer";
                std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
            } 
        }
        

        for (int i{ 0 }; i < quote_no_value; i++) {
            std::cout << std::endl << "Quote " << i + 1 << std::endl;
           
            if (i==0) 
            std::cin.ignore(1, '\n');
        

            std::cout << "Quote: ";
            std::getline(std::cin, quote);
            out_file << quote << std::endl;


            std::cout << "Author: ";
            std::getline(std::cin, author);
            out_file << author << std::endl;


            std::cout << "Date: ";
            std::getline(std::cin, date);
            out_file << date << std::endl;



            std::cout << "Quote successfully added! " << std::endl;
        }
    }
    out_file.close();

}

void display_menu(std::ofstream &out_file, std::ifstream &in_file) {
    if (option != '0') {
        std::cout << "\n\n1 - Add Quotes\n2 - View all Quotes\n3 - Edit A Quote\n4 - Delete a Quote\n0 - Quit the app\n===============================================================================================\nChoice: ";
        std::cin >> option;

        switch (option) {
        case '1':
        {
            add_quotes(out_file,in_file);
            display_menu(out_file, in_file);
        }
        break;
        case '2':
        {
            display_quotes(in_file);
            display_menu(out_file, in_file);
        }
        break;
        case '3':
        {
            edit_quote(out_file,in_file);
            display_menu(out_file, in_file);
        }
        break;
        case '4':
        {
            delete_quote(out_file, in_file);
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

void edit_quote(std::ofstream& out_file, std::ifstream& in_file) {
    system("CLS");
    int quote_no{};
    int count{ 0 };
    std::string quote_temp;
    std::string author_temp;
    std::string date_temp;
    std::string quote;
    std::string author;
    std::string date;
    std::string word;
    std::string entry{};
    bool done = false;

    display_quotes(in_file);

    in_file.open("quotes.txt");
    //Data Validation-------->
    do {
        std::cout << "What quote do you want to edit?\nOption: " << std::endl;
        std::cin >> entry;
        std::istringstream validator{ entry };
        if (validator >> quote_no) {
            done = true;
        }
        else {
            std::cout << "Kindly enter an integer" << std::endl;
            std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
        }
    } while (!done);

    out_file.open("temp.txt");
    while (in_file>>word) {
        if (count != quote_no) {
            getline(in_file, quote);
            out_file<<" " << word << quote << std::endl;

            getline(in_file, author);
            out_file << author<< std::endl;

            getline(in_file, date);
            out_file << date<< std::endl;
        }
        else {
            std::cout << "Quote to be edited: " << std::endl;
            getline(in_file, quote);
            getline(in_file, author);
            getline(in_file, date);
            
            std::cout << "Quote: " <<word<< quote << std::endl;
            std::cout << "Author: " << author << std::endl;
            std::cout << "Date: " << date << std::endl;



            std::cin.ignore(1, '\n');
            std::cout <<std::endl<<std::endl<< "New Quote: ";
            getline(std::cin, quote_temp);
            out_file << quote_temp<<std::endl;

            std::cout << "New Author: ";
            getline(std::cin, author_temp);
            out_file << author_temp<<std::endl;

            std::cout << "New Date: ";
            getline(std::cin, date_temp);
            out_file << date_temp << std::endl;
        }
        count++;
    }
    std::cout << "Quote successfully edited!" << std::endl;
    in_file.close();
    out_file.close();
    remove("quotes.txt");
    rename("temp.txt", "quotes.txt");
    
}

void delete_quote(std::ofstream& out_file, std::ifstream& in_file) {
    system("CLS");
    int quote_no{};
    int count{ 0 };

    std::string quote_temp;
    std::string author_temp;
    std::string date_temp;

    std::string quote;
    std::string author;
    std::string date;
    std::string word;
    std::string entry{};
    bool done = false;

    display_quotes(in_file);

    in_file.open("quotes.txt");

    do {
        std::cout << "What quote do you want to delete?\nOption: " << std::endl;
        std::cin >> entry;

        std::istringstream validator{ entry };
        if (validator >> quote_no) {
            done = true;
        }
        else {
            std::cout << "Kindly enter an integer" << std::endl;
            std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
        }
    } while (!done);

    out_file.open("temp.txt");
    while (in_file >> word) {
        if (count != quote_no) {
            getline(in_file, quote);
            out_file << " " << word << quote << std::endl;

            getline(in_file, author);
            out_file << author << std::endl;

            getline(in_file, date);
            out_file << date << std::endl;
        }
        else {
            getline(in_file, quote);
            getline(in_file, author);
            getline(in_file, date);
        }
        count++;
    }
    std::cout << "Quote successfully deleted!" << std::endl;
    in_file.close();
    out_file.close();
    remove("quotes.txt");
    rename("temp.txt", "quotes.txt");
}

void quit() {
    system("CLS");
    std::cout << "Good-Bye\t\tYour quotes are save with us\n\n\n";
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
