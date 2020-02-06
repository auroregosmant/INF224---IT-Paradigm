# INF224---IT-Paradigm
Client/Server Java C++ January 2020

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

STEP 9 : 
