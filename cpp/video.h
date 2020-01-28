#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include "baseclass.h"

class Video : public BaseClass
{
private :
    int timeLapse = 0;


public:
    Video(std::string name, std::string path);
    Video(std::string name, std::string path, int _timeLapse);

    int getTimeLapse() const;
    void setTimeLapse(int _timeLapse);
    void print(std::ostream & s) const;
    virtual void play() const;
    ~Video();

};

#endif // VIDEO_H
