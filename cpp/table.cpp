#include "table.h"
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
typedef std::basic_stringbuf<char> stringbuf;

Table::Table()
{

}

Table::~Table(){

}

Photo_Ptr Table::createPhoto(std::string name, std::string path){
    Photo_Ptr photo(new Photo(name, path));
    objects[name] = photo;
    return photo;
}

Photo_Ptr Table::createPhoto(std::string name, std::string path, float latitude, float longitude){
    Photo_Ptr photo(new Photo(name, path, latitude, longitude));
    objects[name] = photo;
    return photo;
}

Video_Ptr Table::createVideo(std::string name, std::string path){
    Video_Ptr video(new Video(name, path));
    objects[name] = video;
    return video;
}

Video_Ptr Table::createVideo(std::string name, std::string path, int _timeLapse){
    Video_Ptr video(new Video(name,path, _timeLapse));
    objects[name] = video;
    return video;
}


Movie_Ptr Table::createMovie(int _numChapters, int * _chapters, std::string name,std::string path, float _timeLapse){
    Movie_Ptr movie(new Movie(_numChapters,_chapters,name, path, _timeLapse));
    objects[name] = movie;
    return movie;
}

Group_Ptr Table::createGroup(std::string name){
    Group_Ptr group(new Group(name));
    groups[name] = group;
    return group;
}

BaseClass_Ptr Table::getInTableObject(std::string name){
    auto it = objects.find(name);
    if (it == objects.end())
    {
        std::cout<< " [ERROR] The multimedia object associated to : " + name + " doesn't exist."<< std::endl;
        return nullptr;
    }
    else
    {
        BaseClass_Ptr object = objects.at(name);
        object->print(std::cout);
        return object;
    }


}

Group_Ptr Table::getInTableGroup(std::string name){
    auto it1 = groups.find(name);
    if (it1 == groups.end())
    {
        std::cerr<< " [ERROR] The group associated to : " + name + " doesn't exist."<< std::endl;
        return nullptr;
    }
    else
    {
        Group_Ptr group = groups.at(name);
        group->printGroup(std::cerr);
        return group;
    }

}



void Table::playObject(std::string name){
    auto it = objects.find(name);
    if (it != objects.end())
    {
        BaseClass_Ptr object = objects.at(name);
        object->play();
    }
    else
    {
        std::cerr<< " [ERROR] The multimedia object associated to : " + name + " doesn't exist."<< std::endl;
    }
}

bool Table::processRequest(TCPConnection& cnx, const std::string& request, std::string& response)
{

  std::cerr << "\nRequest: '" << request << "'" << std::endl;

  std::stringstream ss(request);

  std::string command;
  std::string name;

  ss >> command;
  std::cerr << "\n ***The commande is*** : '" << command << "'" << std::endl;

  stringbuf stringBuffer = stringbuf();
  std::ostream os(&stringBuffer);


  if (command == "find")
  {
      ss >> name;

      TCPLock lock(cnx);

      BaseClass_Ptr object = getInTableObject(name);
      Group_Ptr group = getInTableGroup(name);

      if(object!=nullptr)
      {
          object->print(os);
          std::string s = stringBuffer.str();
          for (uint i = 0; i< s.length(); i++)
          {
              if (s.at(i) == "\r"[0] or s.at(i) == "\n"[0])
              {
                  s.replace(i, 1, " ");
              }
          }
          response = "Found the  object " + name +" : " + s;
          std::cerr << "response: " << " "
                    << response << std::endl;
      }
      else if (group!=nullptr)
      {
          group->printGroup(os);
          std::string s = stringBuffer.str();
          for (uint i = 0; i< s.length(); i++)
          {
              if (s.at(i) == "\n"[0] or s.at(i) == "\r"[0])
              {
                  s.replace(i, 1, " ");
              }
          }
          response = "The group " + name + " was found and exists : " + s;
          std::cerr << "Response: " << " "
                    << response << std::endl;
      }
      else if ((group == nullptr) and (object ==nullptr))
      {
          response = "[ERROR] The multimedia object or group : " + name + " doesn't exist in the table. ";
          std::cerr << response << std::endl;

      }

  }

  else if (command == "play")
  {
      ss >> name;

      TCPLock lock(cnx);

      BaseClass_Ptr object = getInTableObject(name);
      Group_Ptr group = getInTableGroup(name);

      if(object!=nullptr)
      {
          object->play();
          response = "Play Multimedia Object " + name + " ";
          std::cerr << "response: " << response << std::endl;
      }
      else if (group!=nullptr)
      {
          group->printGroup(os);
          std::string s = stringBuffer.str();
          for (uint i = 0; i< s.length(); i++)
          {
              if (s.at(i) == "\n"[0] or s.at(i) == "\r"[0])
              {
                  s.replace(i, 1, " ");
              }
          }
          response = "Play Group " + name + " : " + s + " " ;
          std::cerr << "Response: " << response << std::endl;
      }
      else if ((object ==nullptr) and (group==nullptr))
      {
          response = "[ERROR] The multimedia object or group : " + name + " doesn't exist in the table. ";
          std::cerr << response << std::endl;
      }

  }


  else
  {
      response = "Invalid command " + command;
      std::cerr << "Response: " << response << std::endl;

  }



  // 1) pour decouper la requête:
  // on peut par exemple utiliser stringstream et getline()


  // 2) faire le traitement:
  // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
  // - sinon juste: TCPLock lock(cnx);


  // 3) retourner la reponse au client:
  // - pour l'instant ca retourne juste OK suivi de la requête
  // - pour retourner quelque chose de plus utile on peut appeler la methode print()
  //   des objets ou des groupes en lui passant en argument un stringstream
  // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
  //   ils servent à délimiter les messages entre le serveur et le client

  //response = "OK: " + request;
  //std::cerr << "response: " << response << std::endl;

  // renvoyer false si on veut clore la connexion avec le client
  return true;
}


