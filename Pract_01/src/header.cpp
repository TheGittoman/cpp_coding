#include "header.hpp"
#include <iostream>
#include <vector>

void test_Func()
{
    std::cout << "Hello World!" << std::endl;
}

std::string Account::getUser() const{
    return m_user;
}
int Account::getID() const{
    return m_ID;
}

void list_accounts(std::vector<Account> &accounts){
    for(auto &element : accounts)
        std::cout << element;
}