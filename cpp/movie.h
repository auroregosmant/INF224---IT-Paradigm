#ifndef MOVIE_H
#define MOVIE_H
#include "video.h"


class Movie : public Video
{
private :
    int numChapters = 0;
    int * chapters = nullptr;


public:
    Movie(int _numChapters, int * _chapters, std::string name,std::string path, float _timeLapse);
    int * getChapters() const;
    void setChapters(int * tab, int numChapters);
    int getNumChapters() const;
    void print(std::ostream & s) const;
    virtual ~Movie();

};


#endif // MOVIE_H
