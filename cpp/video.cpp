#include "video.h"

Video::Video(std::string name, std::string path):BaseClass(name,path)
{
    timeLapse = 0;
}

Video::Video(std::string name, std::string path,int _timeLapse):BaseClass(name, path) //ATTENTION ICI
{
    timeLapse = _timeLapse;
}

Video::~Video(){
    std::cout<< "Video " + getName() + " has been deleted."<< std::endl;
}

int Video::getTimeLapse() const{
    return timeLapse;
}

void Video::setTimeLapse(int _timeLapse){
    timeLapse = _timeLapse;
}

void Video::print(std::ostream & s) const{
    s << "Name : " << getName() << ", "
      <<"Path : " << getPath() << ", "
      <<"TimeLapse :" << timeLapse<< std::endl;
}

void Video::play() const{ //méthode est const, donc tout ce qui est dans la fonction doit être appeké
   system(("mpv " + getPath()+ " &").c_str());
}


