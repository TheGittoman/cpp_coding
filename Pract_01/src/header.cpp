#include "header.hpp"
#include <iostream>

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
