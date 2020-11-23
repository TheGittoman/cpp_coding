#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <vector>

class Person
{
private:
    std::string m_name;
    std::string m_surName;
    int m_age;

public:
    Person(std::string name = "Jane", std::string surName = "Doe", int age = 0) 
                : m_name{name}, m_surName{surName}, m_age{age} 
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
    void addEmployee();
};

#endif