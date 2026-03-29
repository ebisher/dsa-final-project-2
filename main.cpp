//main for clara to implement
#include "student_info.cpp"
#include "merge_sort.cpp"
#include "quick_sort.cpp"
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>


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
    generateStudents(system, 100000); //generate 100,000 data points/students
    float GPA_avg = system.averageGPA();

    std::vector<Student> originalData = system.getStudents();
   
    //welcome heading display

    printHeader("SCHOOL MANAGEMENT SYSTEM");
    std::cout << "Total Students: " << system.size() << std::endl << "Average GPA: " << GPA_avg << std::endl << std::endl;

    while(true){
        //main menu
        printHeader("Main Menu");
        std::cout << "1. Student Records" << std::endl;
        std::cout << "2. Sorting" << std::endl;
        std::cout << "3. Exit" << std::endl;

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
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                Student newStudent = inputStudent();
                system.addStudent(newStudent);
                std::cout << "  Student '" << newStudent.name << "' added successfully.\n";

            } else if (subMenuSelection == 3){ //updates student info
                std::cout << "Enter ID to update: ";
                int id;
                std::cin >> id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
            std::cout << "2. Quick sort by GPA" << std::endl;
            std::cout << "3. Merge vs Quick sort by GPA comparison analysis" << std::endl;
            std::cout << "4. View honors roll" << std::endl;
            std::cout << "5. Filter by class year" << std::endl;
            std::cout << "6. Return to Main Menu" << std::endl;
      
            int subMenuSelection;
            std::cin >> subMenuSelection;

            if (subMenuSelection == 1){ //call merge sort by gpa
                if (system.gpaSorted()) { //already sorted catch
                    std::cout << "List of students is already sorted by GPA";
                    continue;
                } else {
                    std::vector<Student>& students = system.getStudents();
                    auto start = std::chrono::high_resolution_clock::now();
                    mergeSort(students, 0, students.size() - 1);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
                    std::cout << "Students sorted by GPA using Merge Sort." << std::endl;
                    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;
                }
                
            } else if (subMenuSelection == 2){ //call quick sort by gpa
                if (system.gpaSorted()) { //already sorted catch
                    std::cout << "List of students is already sorted by GPA";
                    continue;
                } else {
                    std::vector<Student>& students = system.getStudents();
                    auto start = std::chrono::high_resolution_clock::now();
                    quickSortByGPA(students, 0, students.size() - 1);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
                    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;
                    std::cout << "Students sorted by GPA using Quick Sort." << std::endl;
                }
                
            } else if (subMenuSelection == 3){ // compare merge vs quick sort 
                std::vector<Student> mergeVec = originalData;
                std::vector<Student> quickVec = originalData;
                auto startMerge = std::chrono::high_resolution_clock::now();
                mergeSort(mergeVec, 0, mergeVec.size() - 1);
                auto endMerge = std::chrono::high_resolution_clock::now();

                auto mergeTime = std::chrono::duration_cast<std::chrono::microseconds>(endMerge - startMerge);

                auto startQuick = std::chrono::high_resolution_clock::now();
                quickSortByGPA(quickVec, 0, quickVec.size() - 1);
                auto endQuick = std::chrono::high_resolution_clock::now();
                auto quickTime = std::chrono::duration_cast<std::chrono::microseconds>(endQuick - startQuick);


                printHeader("Sorting Performance");
                std::cout << "Dataset size: " << system.size() << " students" << std::endl;
                std::cout << "Merge Sort Time : " << mergeTime.count() << " microseconds" << std::endl;
                std::cout << "Quick Sort Time : " << quickTime.count() << " microseconds" << std::endl;
                
                if (mergeTime == quickTime){
                    std::cout << "Merge sort took an equal amount of time as quick sort." <<std::endl;
                } else if (mergeTime > quickTime) {
                    auto timeDiff = mergeTime - quickTime;
                    std::cout << "Quick sort was " << timeDiff.count() << " microseconds faster than merge sort." << std::endl;
                } else {
                    auto timeDiff = quickTime - mergeTime;
                    std::cout << "Merge sort was " << timeDiff.count() << " microseconds faster than quick sort." << std::endl;
                }
            } else if (subMenuSelection == 4){ // view honor roll
                system.showHonorsRoll();
                
            } else if (subMenuSelection == 5){ // filter by year
                std::cout << "Enter class year to filter by: ";
                int yearFilter;
                std::cin >> yearFilter;
                system.showClassYear(yearFilter);
                
            } else if (subMenuSelection == 6){ //return to main menu
                continue;

            } else { //invalid selection catch
                std::cout << "Invalid selection." << std::endl;
            }            
        } else if (menuSelection == 3){ //exit program
            std::cout << "Thank you for using DK's School Management System. Goodbye!";
            break;
        } else { //invalid selection catch
            std::cout << "Invalid selection." << std::endl;
        }
    }
    return 0;
}
