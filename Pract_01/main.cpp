#include "src/header.hpp"
#include <iostream>
#include <vector>

int main()
{
    int account_count{};
    std::vector<Account> accounts {};
    std::cout << "How many accounts you want to add? " << std::endl;
    std::cin >> account_count;
    std::cout << std::endl;
    while(account_count >= 0)
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