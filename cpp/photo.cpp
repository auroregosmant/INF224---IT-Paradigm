#include "photo.h"
#include <iostream>
using namespace std; // equiv a import std.* en java


Photo::Photo(std::string name, std::string path):BaseClass(name, path)
{
    latitude = 0;
    longitude = 0;
}

Photo::Photo(std::string name, std::string path, float _latitude, float _longitude):BaseClass(name, path)
{
    latitude = _latitude;
    longitude = _longitude;
}

Photo::~Photo()
{
    std::cout<< "Photo " + getName() + " has been deleted."<< std::endl;
}

float Photo::getLatitude() const{
    return latitude;
}

float Photo::getLongitude() const{
    return longitude;
}

void Photo::setLatitude(float _latitude){
    latitude = _latitude;
}

void Photo::setLongitude(float _longitude){
    longitude = _longitude;
}

void Photo::print(std::ostream & s) const{
    s << "Name : " << getName() <<  ", "
      << "Path : " << getPath() << ", "
      <<  "Latitude :" << latitude << ", "
      << "Longitude :" << longitude << std::endl;
}

void Photo::play() const{ //méthode est const, donc tout ce qui est dans la fonction doit être appeké
   system(("imagej " + getPath()+ "&").c_str());
   std::cout<< "imagej " + getPath()+ "&"<< std::endl;
}

