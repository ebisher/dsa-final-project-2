//main for clara to implement
#include "student_info.cpp"
#include "sortandsearchalgorithms.cpp"
#include <cstdlib>
#include <ctime>
#include <random>


//generation vectors for names, class year, majors, activities

std::vector<std::string> names = {
    "Alex","Jordan","Taylor","Morgan","Riley","Casey","Jamie","Drew","Avery","Parker",
    "Quinn","Rowan","Blake","Cameron","Skyler","Dakota","Emerson","Finley","Hayden","Kendall",
    "Logan","Micah","Noah","Reese","Sawyer","Tatum","Charlie","Elliot","Harper","Jesse",        "Kai","Lane","Marlowe","Nico","Oakley","Phoenix","Remy","Sage","Shawn","Tristan",
    "Val","Winter","Zion","Bailey","Cody","Devon","Eden","Frankie","Gray","Indie"
    };

std::vector<int> years = {2025, 2026, 2027, 2028};

float min_val = 0.0f;
float max_val = 4.0f;
std::uniform_real_distribution<float> dist(min_val, max_val);
std::mt19937 gen(std::random_device{}());

std::vector<std::string> majors = {
    "Computer Science", "Business", "Marketing", "Finance",
    "Graphic Design", "Biology", "Chemistry", "Physics"
    };

std::vector<std::string> activities = {
    "Chess", "Dance", "Soccer", "Debate Team",
    "Art Society", "School Newspaper"
    };


void generateStudents(StudentSystem& system, int count){  //generates random 
    for (int i = 0; i < count; i++){
        Student s;
        s.id = 20262000+i;
        s.name = names[rand() % names.size()];
        s.gpa = dist(gen);
        s.classYear = years[rand() % years.size()];
        s.major = majors[rand() % majors.size()];
        s.activities = activities[rand() % activities.size()];
        system.addStudent(s);
    }
}


int main() {
    StudentSystem system; //create system obj
    generateStudents(system, 20); //generate 100,000 data points/students
    float GPA_avg = system.averageGPA();
   
   
    //welcome heading display

    printHeader("SCHOOL MANAGEMENT SYSTEM");
    std::cout << "Total Students: 100,000"<< std::endl << "Average GPA: " << GPA_avg << std::endl << std::endl;

    //main menu
    printHeader("Main Menu");
    std::cout << "1. Student Records" << std::endl;
    std::cout << "2. Sorting" << std::endl;
    std::cout << "3. View Summary" << std::endl;
    std::cout << "4. Exit" << std::endl;

    //Student records menu
    printHeader("Student Records");
    std::cout << "1. View all students" << std::endl;
    std::cout << "2. Add student" << std::endl;
    std::cout << "3. Update student" << std::endl;
    std::cout << "4. Delete student" << std::endl;
    std::cout << "5. Return to Main Menu" << std::endl;

    // sorting menu
    printHeader("Sorting");
    std::cout << "1. Merge sort by GPA" << std::endl;
    std::cout << "2. Heap sort by GPA" << std::endl;
    std::cout << "3. View honors roll" << std::endl;
    std::cout << "4. Filter by class year" << std::endl;
    std::cout << "5. Return to Main Menu" << std::endl;


    // //summary screen TODO
    // std::cout << "========================================" << std::endl;
    // std::cout << "      Main Menu";
    // std::cout << "1. Student Records";
    // std::cout << "2. Sorting";
    // std::cout << "3. View Summary";
    // std::cout << "4. Exit";

    return 0;
}
