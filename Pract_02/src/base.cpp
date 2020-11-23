#include "base.hpp"
#include <iostream>

std::string Person::getInfo()
{
    return(m_name + ", " + m_surName + ", " + std::to_string(m_age));
}