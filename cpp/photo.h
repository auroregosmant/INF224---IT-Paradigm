#ifndef PHOTO_H
#define PHOTO_H

#include <string>
#include "baseclass.h"

class Photo : public BaseClass
{ 
private :
    float latitude;
    float longitude;

public:
    Photo(std::string name, std::string path);
    Photo(std::string name, std::string path, float latitude, float longitude);
    ~Photo();

    float getLatitude() const;
    float getLongitude() const;
    void setLatitude(float _latitude);
    void setLongitude(float _longitude);
    void print(std::ostream & s) const;
    virtual void play() const;

};

#endif // PHOTO_H
