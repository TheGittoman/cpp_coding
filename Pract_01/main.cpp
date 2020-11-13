#include "src/header.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

int main(int argc, char *argv[])
{
    std::ofstream outf{ "sample.dat", std::ios::app};
    if (!outf)
    {
        std::cerr << "sample.dat doesn't exist!" << std::endl;
        return 1;
    }
    outf << "this is line 1" << '\n';
    outf << "this is line 2" << '\n';

    outf.close();

    std::ifstream inf{ "sample.dat"};
    if (!inf)
    {
        std::cerr << "sample.dat doesn't open!" << std::endl;
        return 1;
    }
    std::string fileinput{};
    while (inf)
    {
        std::string input{};
        std::getline(inf, input);
        fileinput += input + ' ';
        std::cout << input << '\n';
    }
    std::cout << fileinput << std::endl;

    int account_count{};
    if (argv)
        system(argv[1]);
    std::vector<Account> accounts{};
    std::cout << "How many accounts you want to add? " << std::endl;
    std::cin >> account_count;
    std::cout << std::endl;
    while(account_count > 0)
    {
        --account_count;
        std::cout << "Account name and pass: ";
        std::string name{};
        std::string pass{};
        std::cin >> name >> pass;
        Account temp{name, pass};
        accounts.push_back(temp);
        std::cout << std::endl;
    }
    list_accounts(accounts);
    system("pause");
    return 0;
}