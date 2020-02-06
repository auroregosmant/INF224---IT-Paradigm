# INF224---IT-Paradigm
Client/Server Java C++ January 2020
Student : Aurore GOSMANT

STEP 1 :  
//

STEP 2:
//

STEP 3: 
By creating a Baseclass object baseClass, we cannot get access to its name baseClass→ name, since it is private. Encapsulation principle is verified.

STEP 4 :
Print is a virtual function. Creating photo and video object derived from the Baseclass, we had to declare some functions of the Baseclass as virtual, and intialize them to 0, as the function print.
			virtual void print(std::ostream & s) const = 0 ;
The objects from the class Baseclass cannot be instantiated anymore sinec it is an abstract class. Its print method isn’t defined.

STEP 5 :
Polymorphism is used here : Both Photo and Video are multimedia objects from Baseclass. Here, we use a table of pointers to Baseclass objects. Polymorphisme is necessary in order to call the function associated to each type of Baseclass object. The polymorphic methods of the Photo and the Video were declared in Baseclass, and the implemented again in Photo and Video. Polymorphism is necesssary since objects aren’t all from same size. The same method is used in Java.

STEP 6 :
The table needs to be copied when the object is instanciated, thus, nobody has access to it and only the object itself can have access to it.
Then, for the getter method to acccess the table of chapters, we need to copy the table of chapters again. However, we should’nt forget to add a  delete method so that a nullpointer doesn’t remain ; to avoid mémory leaks.


STEP 7 :
The class Movie dynamically creates a table in its constructor. Therefore, it needs to be deleted in its destrucor. 
While copying this object, there can be problems if ever there are pointers towards other objects. If only a superficial copy is done, two pointers could link to the same object, which could raise problems whenever the object is deleted or modified. Pointed objects should also be pointed.

STEP 8 :
If a list of Baseclass objects was created, then it can contain various Baseclass objects. However, since Movies, Videos and Photos are from different sizes, we cannot directly store the objetcs themselves in the groups. Pointers are therefore necessary, and should be usedd in the group. Effectiveley, each pointers have the same size. 
It is the same in Java.

STEP 9 :
Smart pointers are used to ensure that objects are effectively deleted once no pointers points towards them anymore. It enables to avoid the usage of the delete function.
A smart pointer is defined for each sub-class of Baseclass objects : Video_Ptr for a video, Photo-Ptr for a photo… and we also use smart pointers for groups : Group_ptr. Videos are Photos are automatically deleted as long as their do not belong to any group.

STEP 10 :
In order to only be able to create a multimedia object when it is created by the table Class, we can declare the constructeurs as protected, so that subclasses still have access to it, and declare the class Table as friend.

STEP 11 :
The following methods were implemented : 
find <name> ---------- > Searches a multimedia object or group in the table.
play <name>---------- > Plays the multimedia object.
createPhoto <name> -------→ Creates a photo, adds it to the table and sets it path by default to « ./name.png ».
createVideo <name> --------→ Creates a video, adds it to the table and sets by default path « ./video.mp4 ».
createGroup <name> ------→ Creates a group, and adds it to the table.
printObjects ---------------→ Prints all objects contained in the table
printGroups ------------→ Print all groups contained in the table, and the multimedia objects it contains.

STEP 12 :
The objects can be directly created by reading the text file « table_saved.txt ». Then, before exiting, the objects and groups that were created are saved in the textFile. 

ANNEXE : 
    • Real photos and videos were added to the project. You can play them by entering their name :
          - Lydia.mp4
          - TelecomParis.png
          - paysage.png
          - paisible.png (this one wasn’t added to the textFile, but you can still create by entering « paisible.png » when clicking on «Create a Photo » of the Java User Interface.
          
    • I commented and documented the code using Doxygen. The documentation is at « index.html » and was generated from the Doxyfile. I commented only the Java part, since I believe the code is enough explicit in the Java class, and that is brought less clarity to the document.
