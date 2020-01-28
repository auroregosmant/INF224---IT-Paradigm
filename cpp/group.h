#ifndef GROUP_H
#define GROUP_H
#include <list>
#include "baseclass.h"
#include <memory>

typedef std::list<std::shared_ptr<BaseClass>> Group_ptr;

class Group : public Group_ptr  // std::shared_ptr<BaseClass> equiv à  BaseClass* (mais avec gestion des references)
{
private :
    std::string name;
public:

    Group(std::string _name);
    std::string getGroupName() const;
    void setGroupName(std::string _name);
    void printGroup(std::ostream & o) const;

};

#endif // GROUP_H
