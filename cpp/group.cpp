#include "group.h"
#include <list>
#include <iostream>


Group::Group(std::string _name)
{
    name = _name;
}

std::string Group::getGroupName() const
{
    return name;
}

void Group::setGroupName(std::string _name)
{
    name = _name;
}

void Group::printGroup(std::ostream & o) const
{
    for (auto & it : *this)
    {
        it->print(o);
    }

};
