#ifndef TABLE_H
#define TABLE_H

#include <map>
#include "group.h"
#include "video.h"
#include "photo.h"
#include "movie.h"
#include "group.h"
#include "tcpserver.h"
using namespace cppu;

typedef std::shared_ptr<BaseClass> BaseClass_Ptr;
typedef std::shared_ptr<Photo> Photo_Ptr; // creation of a table for photo objects
typedef std::shared_ptr<Video> Video_Ptr;
typedef std::shared_ptr<Movie> Movie_Ptr;
typedef std::shared_ptr<Group> Group_Ptr; // creation of a tale for groups



class Table
{
private:
    std::map<std::string, std::shared_ptr<BaseClass>> objects; //table of multimedia objects
    std::map<std::string, Group_Ptr> groups; // table of groups

public:
    Table();
    ~Table();

    Photo_Ptr createPhoto(std::string name, std::string path);
    Photo_Ptr createPhoto(std::string name, std::string path, float latitude, float longitude);

    Video_Ptr createVideo(std::string name, std::string path);
    Video_Ptr createVideo(std::string name, std::string path, int _timeLapse);

    Movie_Ptr createMovie(int _numChapters, int * _chapters, std::string name,std::string path, float _timeLapse);

    Group_Ptr createGroup(std::string name);

    BaseClass_Ptr getInTableObject(std::string name);

    Group_Ptr getInTableGroup(std::string name);

    void playObject(std::string name);

    bool processRequest(cppu::TCPConnection& cnx, const std::string& request, std::string& response);

};

#endif // TABLE_H
