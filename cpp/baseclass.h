#ifndef BASECLASS_H
#define BASECLASS_H

#include <string>
#include <iostream>

class BaseClass
{
private :
    std::string name;
    std::string path;

public:
    BaseClass();
    BaseClass(std::string name, std::string path);
    ~BaseClass(); //destructeur

    void setName(std::string name);
    void setPath(std::string path);
    std::string getName() const;
    std::string getPath() const;
    virtual void print(std::ostream & s) const;
    virtual void play() const =0;
};

#endif // BASECLASS_H
