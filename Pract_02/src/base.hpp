#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>


class Person
{
private:
    std::string m_name;
    std::string m_surName;
    int m_age;

public:
    Person(const std::string &name, const std::string &surName, const int &age) 
                : m_name{name}, m_surName{surName}, m_age{age} {}
    Person() 
    {
		std::cout << "Write Full Name and Age(f + s + a): ";
        // *this means that we get current object and use its variables.
        // pointer * is a variable that stores memory addresses when used
        // like this "int *p = &x" but when used like this "*p"
        // it means that we want the data stored in the address of p which is value of x.
		std::cin >> *this;
		std::cout << std::endl;
    }

    std::string getInfo();

    void setName(const std::string &name)
    {
        m_name = name;
    }
    void setSurname(const std::string &surName)
    {
        m_surName = surName;
    }
    void setAge(const int &age)
    {
        m_age = age;
    }

    friend std::istream &operator>>(std::istream &in, Person &person)
    {
        in >> person.m_name; 
        in >> person.m_surName; 
        in >> person.m_age;
        return in;
    }
    ~Person() 
    {
    }
};

class Company
{
private:
    std::vector<Person> employees{};
public:
    Company() {}
    std::string getEmployee(const int &index);
    void addFromFile(const Person &tempPerson);
    void readEmployees();
    void addEmployee();
    void writeEmployees();
    void printEmployees();
    void setAge()
    {
        int index;
        std::cout << "Set index of employee: ";
        std::cin >> index;
        --index;
        std::cout << std::endl;
        int age;
        std::cout << "Set age of first employee: ";
        std::cin >> age;
        std::cout << std::endl;
        employees[index].setAge(age);
    }
};

#endif