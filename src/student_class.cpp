#include <iostream>
#include <iomanip>
#include <random>
#include <vector>

/**
 * @class Random
 * @brief A class that generates random numbers.
 */
class Random{
    std::mt19937 rng; //random number generator
public:

    /**
     * @brief Constructor that initializes the random number generator.
     */
    Random(){
        std::random_device rd;
        rng = std::mt19937(rd());
    }

    /**
     * @brief Method to generate random integer between first and last.
     * @param first The first number of the range.
     * @param last The last number of the range.
     * @return Random integer between first and last.
     */
    int getInt(int first, int last){
        std::uniform_int_distribution<int> dist(first, last);
        return dist(rng);
    }

    /**
     * @brief Method to generate random double between first and last.
     * @param first The first number of the range.
     * @param last The last number of the range.
     * @return Random double between first and last.
     */
    double getDouble(double first, double last){
        std::uniform_real_distribution<double> dist(first, last);
        return dist(rng);
    }
};

/**
 * @class Student
 * @brief A class that represents a student.
 * @param name Name of the student.
 * @param age Age of the student.
 * @param grade Grade of the student.
 */
class Student{
private:
    std::string name;
    int age;
    double grade;

    static int totalStudents;

    mutable bool ageAccessed = false;

    void generateStudentInfo(){
        Random random;
        std::string names[] = {"Rodrigo", "Ricardo", "Andres", "Raul"};

        name = names[random.getInt(0, std::size(names)-1)];
        age = random.getInt(18, 25);
        grade = random.getDouble(0.0, 10.0);
    }

public:

    /**
     * @brief Default constructor that initializes student with random values.
     */
    Student() : name(""), age(0), grade(0.0f) {
        generateStudentInfo();
        
        totalStudents ++;
    }

    /**
     * @brief Constructor that initializes student with given values.
     * @param name Name of the student.
     * @param age Age of the student.
     * @param grade Grade of the student.
     */
    Student(std::string name, int age, double grade):
    name(name), age(age), grade(grade){
        if (name.empty()) exit;
        if(age < 0 || age > 120) exit;
        if(grade < 0 || grade > 10) exit;
        
        totalStudents ++;
    }

    /**
     * @brief Getter for the name of the student.
     */
    // Getters
    std::string getName() const{
        return this->name;
    }

    /**
     * @brief Getter for the age of the student.
     */
    int getAge() const{
        ageAccessed = true;
        return this->age;
    }

    /**
     * @brief Getter for the grade of the student.
     */
    double getGrade() const{
        return this->grade;
    }

    /**
     * @brief Setter for the name of the student.
     * @param newName New name of the student.
     */
    // Setters
    void setName(std::string newName){
        if(!newName.empty()){
            this->name = newName;
        } else {
            std::cerr << "Invalid name" << std::endl;
        }
    }

    /**
     * @brief Setter for the age of the student.
     * @param newAge New age of the student.
     */
    void setAge(int newAge){
        if(newAge >= 0 && newAge <= 120){
            this->age = newAge;
        } else {
            std::cerr << "Invalid age" << std::endl;
        }
    }

    /**
     * @brief Setter for the grade of the student.
     * @param newGrade New grade of the student.
     */
    void setGrade(double newGrade){
        if(newGrade >= 0 && newGrade <= 10){
            this->grade = newGrade;
        } else {
            std::cerr << "Invalid grade" << std::endl;
        }
    }

    /**
     * @brief Method to print the student's information.
     */
    void printInfo() const; // Declaring printInfo()

    /**
     * @brief Method to get the total number of students.
     * @return The total number of students.
     */
    static int getTotalStudents() {
        return totalStudents;
    }

    // initializing friend method compareGrade
    /**
     * @brief Method to compare the grade of two students.
     */
    friend bool compareGrade(const Student& a, const Student& b);

    // Course class 
    /**
     * @class Course
     * @brief A class that represents a course.
     * @param courseName Name of the course.
     * @param year Year of the course.
     */
    class Course { 
    public:
        std::string courseName;
        int year;

        Course(std::string courseName, int year): courseName(courseName), year(year){}
    };

    /**
     * @brief Method to enroll a student in a course.
     * @param course Course to enroll the student in.
     */
    void enroll(Course& course){
        courses.push_back(course);
    }

    /**
     * @brief Method to print the courses the student is enrolled in.
     */
    void printCourses(){
        std::cout<< "Enrolled Courses:"<<std::endl;
        for (int i=0; i < courses.size();i++){
            std::cout << "- " << courses[i].courseName << " (Year: " << courses[i].year << ")" << std::endl;
        }
    }

private:
    // vector of Course objects starting empty
    std::vector<class Course> courses;

    // had to declare after Course class because error
};

int Student::totalStudents = 0;

void Student::printInfo() const{ // Defining outside class
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Grade: " << grade << std::endl << std::endl;

    if(Student::ageAccessed){
        std::cout<<"Age has been accessed"<<std::endl<<std::endl;
    }
}

bool compareGrade(const Student& a, const Student& b) {
    if (a.grade > b.grade){
        return true;
    } else {
        return false;
    }
}

int main(){

    Student s1;
    s1.printInfo();

    // s1.setName("Juanito");
    // s1.setAge(999);
    // s1.setGrade(999);
    // s1.printInfo();

    // Creating course objects
    Student::Course course1("Computer Programming 2", 2024);
    Student::Course course2("High Performance Computing", 2024);

    Student s2("Alice", 20, 8.0);
    // Enrolling Alice
    s2.enroll(course1);
    s2.enroll(course2);


    std::cout << s2.getName() << "'s age: " << s2.getAge() << std::endl << std::endl;

    s2.printInfo();
    s2.printCourses();

    std::cout<<"Student count: "<<s1.getTotalStudents()<<std::endl;

    if (compareGrade(s1, s2)){
        std::cout<<"Student 1's grade is greater than student 2's"<< std::endl;
    } else {
        std::cout<<"Student 2's grade is greater than student 1's"<< std::endl;
    }

    return 0;
}