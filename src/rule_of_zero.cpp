#include <iostream>
#include <vector>

class Person {
public:
    std::string name;
    int age;
    std::vector<std::string> hobbies;

    Person(std::string name, int age, std::vector <std::string> hobbies) : 
    name(name), age(age), hobbies(hobbies){}

    void printHobbies(){
        std::cout<<"Hobbies:"<<std::endl;
        for(int i=0; i<hobbies.size(); i++){
            std::cout<<"- "<<hobbies[i]<<std::endl;
        }
    }
};

int main(){
    Person p1{"Alice", 30, {"reading", "hiking"}};
    std::cout<<std::endl<<p1.name<<p1.age<<std::endl;
    p1.printHobbies();

    Person p2 = p1; // Compiler-generated copy constructor
    p2.name = "Bob";
    p2.hobbies.push_back("swimming");
    std::cout<<std::endl<<p2.name<<p2.age<<std::endl;
    p2.printHobbies();
}