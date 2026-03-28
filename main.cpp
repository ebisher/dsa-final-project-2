//main for clara to implement
#include "student_info.cpp"
#include "merge_sort.cpp"
#include "quick_sort.cpp"
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
    std::cout << "Total Students: " << system.size() << std::endl << "Average GPA: " << GPA_avg << std::endl << std::endl;

    while(true){
        //main menu
        printHeader("Main Menu");
        std::cout << "1. Student Records" << std::endl;
        std::cout << "2. Sorting" << std::endl;
        std::cout << "3. View Summary" << std::endl;
        std::cout << "4. Exit" << std::endl;

        int menuSelection;
        std::cin >> menuSelection;

        if (menuSelection == 1){
            //Student records menu
            printHeader("Student Records");
            std::cout << "1. View all students" << std::endl;
            std::cout << "2. Add student" << std::endl;
            std::cout << "3. Update student" << std::endl;
            std::cout << "4. Delete student" << std::endl;
            std::cout << "5. Return to Main Menu" << std::endl;

            int subMenuSelection;
            std::cin >> subMenuSelection;
            
            if (subMenuSelection == 1){ //prints out all students
                system.listAll();

            } else if (subMenuSelection == 2){ //adds student with user input info
                std::cout << "Add student below: ";
                Student newStudent = inputStudent();
                system.addStudent(newStudent);
                std::cout << "  Student '" << newStudent.name << "' added successfully.\n";

            } else if (subMenuSelection == 3){ //updates student info
                std::cout << "Enter ID to update: ";
                int id;
                std::cin >> id;
                Student updatedStudent = inputStudent();
                updatedStudent.id = id;
                system.updateStudent(id, updatedStudent);

            } else if (subMenuSelection == 4){ //delete student
                std::cout << "Enter ID to delete: ";
                int id;
                std::cin >> id;
                system.deleteStudent(id);
                
            } else if (subMenuSelection == 5){ //return to main menu
                continue;

            } else { //invalid selection catch
                std::cout << "Invalid selection." << std::endl;
            }

        } else if (menuSelection == 2)
        {
            // sorting menu
            printHeader("Sorting");
            std::cout << "1. Merge sort by GPA" << std::endl;
            std::cout << "2. Heap sort by GPA" << std::endl;
            std::cout << "3. View honors roll" << std::endl;
            std::cout << "4. Filter by class year" << std::endl;
            std::cout << "5. Return to Main Menu" << std::endl;
      
            int subMenuSelection;
            std::cin >> subMenuSelection;
            
            if (subMenuSelection == 1){ //call merge sort by gpa

            } else if (subMenuSelection == 2){ //call heap sort by gpa


            } else if (subMenuSelection == 3){ // view honor roll
                system.showHonorsRoll();
                
            } else if (subMenuSelection == 4){ // filter by year
                std::cout << "Enter class year to filter by: ";
                int yearFilter;
                std::cin >> yearFilter;
                system.showClassYear(yearFilter);
                
            } else if (subMenuSelection == 5){ //return to main menu
                continue;

            } else { //invalid selection catch
                std::cout << "Invalid selection." << std::endl;
            }            
        
        } else if (menuSelection == 3){
            //summary screen TODO
        } else if (menuSelection == 4){ //exit program
            std::cout << "Thank you for using DK's School Management System. Goodbye!";
            break;
        } else { //invalid selection catch
            std::cout << "Invalid selection." << std::endl;
        }
    }
    return 0;
}
