//
// main.cpp
// Created on 21/10/2018

/**
 *  A main class. Enables to test the functions.
 */

#ifdef OLD_VERSION

#include <iostream>
#include "baseclass.h"
#include "video.h"
#include "photo.h"
#include "movie.h"
#include "group.h"
#include "table.h"

using namespace std;



//int main(int argc, const char* argv[])
//{
//    std::cout << "Hello brave new world" << std::endl;

    //BaseClass * baseClass = new BaseClass("myName","TP1");
    /*Video * video1 = new Video("video","TP1",60);
    Photo * photo1 = new Photo("photo", "TP1", 300, 300);

    //baseClass->printClass(cout);
    video1->print(cout);
    photo1->print(cout);


    BaseClass * tab[3] = {
        new Photo("image1", "/cal/homes/agosmant/inf224/image1.png"),
        new Photo("video2", "TP1", 3, 3), new Video("video3", "TP1", 4)
    };*/


    // tableaux de pointeurs car classe est abstraite

    //for (int j=0; j<3; j++){
      //  tab[j]-> play();
    //}

    /*int * tab2 = new int[3];
    tab2[0] = 1;
    tab2[1] = 2;
    tab2[2] = 3;
    Movie * mov = new Movie(3, tab2, "mov1", "path", 5);

    std::cout << "**********" << std::endl;
    Group * G0 = new Group("G0");
    Photo * photo0 = new Photo("TelecomParis", "/cal/homes/agosmant/Gosmant_Aurore/TelecomParis.png");
    Video * video0 = new Video("Lydia", "/cal/homes/agosmant/Gosmant_Aurore/Lydia.mp4", 5);
    Movie * movie0 = new Movie(3, tab2, "mov0", "/cal/homes/agosmant/Gosmant_Aurore/mov0", 6);
    G0->push_back(photo0); //photo added to the group
    G0->push_back(video0);//video added to the group
    G0->push_back(movie0);//movie added to the group
    G0->push_back(mov);

    G0->printGroup(cout); //prints the elements in the group



    mov->print(cout);

    mov-> deleteMovie();

    return 0;*/


    //***** QUESTION 9 *****

    /*int * tab2 = new int[3];
    tab2[0] = 1;
    tab2[1] = 2;
    tab2[2] = 3;
    std::shared_ptr<Movie> mov1(new Movie(3, tab2, "mov1", "path", 5));

    std::cout << "**********" << std::endl;
    Group * G0 = new Group("G0");
    std::shared_ptr<Photo> photo2(new Photo("TelecomParis", "/cal/homes/agosmant/Gosmant_Aurore/TelecomParis.png"));
    std::shared_ptr<Video> video2(new Video("Lydia", "/cal/homes/agosmant/Gosmant_Aurore/Lydia.mp4", 5));

    G0->push_back(photo2); //photo added to the group
    G0->push_back(video2);//video added to the group

    G0->pop_back();

    // ***** QUESTION 10 *****

    Table * table = new Table();
    table->createPhoto("TelecomParis", "/cal/homes/agosmant/Gosmant_Aurore/TelecomParis.png");
    table->createVideo("julie", "marion", 13);
    table->getInTableGroup("aurore");
    table->getInTableObject("aurore");
    table->getInTableGroup("julie");
    table->getInTableObject("julie");
    table->getInTableGroup("blabla");
    table->getInTableObject("blabla");

}*/

#endif

#define CLIENT_SERVEUR
#ifdef CLIENT_SERVEUR
//       ***** QUESTION 11 Client / Serveur *****

#include <memory>
#include "table.h"
using namespace std;
using namespace cppu;

const int PORT = 3331;

int main()
{
    // creates a new tables and two groups
    shared_ptr<Table> table(new Table());
    Group_Ptr group1 = table-> createGroup("G1");


    std::shared_ptr<Photo> photo2(new Photo("image1", "./image1.png"));
    std::shared_ptr<Video> video2(new Video("video0", "./video0", 5));

    group1 -> push_back(photo2);
    group1 -> push_back(video2);
    table -> createPhoto("TelecomParis", "./TelecomParis.png");
    table -> createVideo("Lydia", "./Lydia.mp4");


  // creates TCP server
  shared_ptr<TCPServer> server(new TCPServer());

  // le serveur appelera cette méthode chaque fois qu'il y a une requête
  server->setCallback(*table, &Table::processRequest);

  // lance la boucle infinie du serveur
  cout << "Starting Server on port " << PORT << endl;
  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    cerr << "Could not start Server on port " << PORT << endl;
    return 1;
  }

  return 0;
}

#endif
