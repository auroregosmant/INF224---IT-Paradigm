#include "movie.h"
#include <iostream>

Movie::Movie(int _numChapters, int * _chapters, std::string name,std::string path, float _timeLapse):Video(name, path, _timeLapse)
{
    numChapters = _numChapters;
    chapters = _chapters;
}

Movie::~Movie()
{
    delete [] chapters;
    numChapters = 0;
    std::cout<< "Movie " + getName() + " has been deleted."<< std::endl;
}


int * Movie::getChapters() const{
    return chapters;
}

void Movie::setChapters(int * tab, int numChapters){
    int * chapters = new int[numChapters];
    * chapters = * tab;
    for (int j=0; j< numChapters; j++)
    {
        chapters[j] = tab[j];
    }

    delete [] chapters;
}

int Movie::getNumChapters() const{
    return numChapters;
}

void Movie::print(std::ostream & s) const
{
    Video::print(s);
    for (int j =0; j<numChapters; j++){
        s<<"The chapter "<<j<<" lasts: "<<chapters[j]<<" seconds"<<std::endl;
    }
}

