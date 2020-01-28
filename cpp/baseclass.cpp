#include "baseclass.h"

BaseClass::BaseClass()
{
    name="null";
    path="null";
}

BaseClass::BaseClass(std::string _name, std::string _path)
{
    name = _name;
    path = _path;
}

BaseClass::~BaseClass(){

}

void BaseClass::setName(std::string _name){
    name = _name;
}

void BaseClass::setPath(std::string _path){
    path = _path;
}

std::string BaseClass::getName() const{
    return name;
}

std::string BaseClass::getPath() const{
    return path;
}

void BaseClass::print(std::ostream & s) const{
    s << "Name : " << name << "Path : " << path<< std::endl;
}

