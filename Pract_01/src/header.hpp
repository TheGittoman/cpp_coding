#ifndef HEADER_HPP
#define HEADER_HPP
#include <iostream>
#include <vector>

void test_Func();

static int ID{};

class Account
{
private:
    std::string m_user{};
    int m_ID{};
    std::string m_pass{};
public:
    Account(std::string user="default_user", std::string pass="default_pass") : m_user{user}, m_pass{pass} {
        std::cout << "User: " << user << " CREATED" << std::endl;
        ++ID;
        m_ID = ID;
    }
    std::string getUser() const;
    int getID() const;

    friend std::ostream &operator<<(std::ostream &out, Account &account){
        out << "User: " << account.getUser() << "\nID: " << account.getID() << std::endl;
        return out;
    }
};

void list_accounts(std::vector<Account> &accounts);

#endif