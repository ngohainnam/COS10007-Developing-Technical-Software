#include <iostream>
#include <string>
using namespace std;

class GradeBook
{
    public:
    GradeBook(string cName, string tName)
    {
        setCourseName(cName);
        setTeacherName(tName);
    }

    void setCourseName( string name )
    {
        courseName = name;
    }

    void setTeacherName(string name)
    {
        teacherName=name;
    }

    string getCourseName()
    {
        return courseName; // return object's courseName
    }
    string getTeacherName()
    {
        return teacherName;
    }
    void displayMessage()
    {
    cout << "Welcome to the grade book for " << getCourseName()<< "!" << endl;
    cout<<"The course is presented by "<<getTeacherName()<<"!" <<endl;
    }
    private:
    string courseName, teacherName;
};

int main()
{
    GradeBook gradeBook1( "COS10007 Developing Technical Software", "Peter");
    GradeBook gradeBook2( "COS10008 Foundation of Technical Programming" ,"Alex");

    cout << "GradeBook1 created for course: "<<gradeBook1.getCourseName()<<endl;
    cout << "GradeBook2 created for course: "<< gradeBook2.getCourseName()<< endl;
    gradeBook1.displayMessage();
    gradeBook2.displayMessage();
}
