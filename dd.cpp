#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Student{
    private:
        int id;
        string name;
        double gpa;
    public:
        Student(int id,string name,double gpa)
        {
            this-> id = id;
            this-> name = name;
            this-> gpa = gpa;
        }
        bool operator < (const Student& second) const {
        return name < second.name;
        }
};

int main() {
    //string FilePath;
    //cin>> FilePath;
    ifstream inputFile("C:\\Users\\hisha\\Desktop\\students.txt"); // e3mel edit hena
    int StudentsNumber;
    inputFile >> StudentsNumber;
    inputFile.ignore();
    
    
    int arr[StudentsNumber];
    
    
    // inputFile.close();
    return 0;
}
