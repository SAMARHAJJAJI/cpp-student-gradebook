#include<iostream>
#include<string>
#include<tuple>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

class GradeBook {
private:

	vector<tuple<string, int, double >> students;
	void printStudent(const tuple<string, int, double>& student) const {
    cout << "\nStudent found:" << endl;
    cout << "Name: " << get<0>(student) << endl;
    cout << "ID: " << get<1>(student) << endl;
    cout << "Score: " << get<2>(student) << endl;
}
	GradeBook() {} // we make a protected  private contructed to prevent the creating other objects 
	GradeBook(const GradeBook&) = delete;//to delete the coppy constructor to prevent coppying again of the object 
	GradeBook& operator = (const GradeBook&) = delete; //to delete the assignment operator to prevent coppying again of the object
	//constant can't change data of object 
public:

	static GradeBook& getInstance() { //return a reference to the one singleton object instance of the class
		static GradeBook instance;// we write static to make the object along the program untill the end , and th other part create the object and return it
		return instance; //return a reference to same object

	};


	void LoadFromFile(const string& First_data) {     //take a students file as it is without coppying or chnaging 
		ifstream file(First_data);                   // to read the file 
		if (!file.is_open()) {                      // to check if the file is open or not
			cout << "Error, cannot open the File . " << First_data << endl;
			return;
		}
		students.clear();// delete or clear all the elements inside students vector , we want te clease the old data to install new data 
		string name;
		int id;
		double score;
		while (file >> name >> id >> score) {     //te read the data line by line 
			students.emplace_back(make_tuple(name, id, score));    //to addd data to students vector as a tuple of data ,
		}
		file.close();
		cout << "Loaded " << students.size() << "students . " << endl;     // to print the number of students loaded from the file
	}

	void print()
	{ 
		if (students.empty()) {
			cout << " No students in the list . " << endl;
			return;
		}
		cout << " \n-------Student List---------- " << endl;

		for (const auto& s : students) {//auto to determine the type of s as a tuple of data 
			cout << "Name : " << get<0>(s) << " Id : " << get<1>(s) << " Score : " << get<2>(s) << endl;
		}
		cout << "\n------------------------------ " << endl;
	}

	void add(const string& name, int id, double score) {
		students.emplace_back(make_tuple(name, id, score)); // to add new student to the students vector as a tuple of data
		cout << " ADDED student : " << name << endl;
	}

	void deleteStudent(int id) {
		for (auto it = students.begin(); it != students.end(); ++it) {//using an iterator to find the student with the given id and delete it
			if (get<1>(*it) == id) {
				cout << "DELETED student : " << get<0>(*it) << endl;
				students.erase(it);
				return;
			}
		}
		cout << "Student with Id " << id << " not found . " << endl;
	}

	void sortByScore() {
		sort(students.begin(), students.end(), [](const tuple<string, int, double>& a, const tuple < string, int, double >& b)
			{
				return get<2>(a) < get<2>(b);
			});// to sort the students vector by score using a lambda function as a custom comparator
		cout << "Student Sorted by score . " << endl;
	}
	void searchById(int id) const {
		auto it = find_if(students.begin(), students.end(),
			[id](const auto& student) {
				return get<1>(student) == id;
			});

		if (it != students.end()) {
    printStudent(*it);
}
		}
		else {
			cout << "\nStudent with ID " << id
				<< " was not found." << endl;
		}
	}

    void searchByName(const string& name) const {
        auto it = find_if(students.begin(), students.end(),
             [&name](const auto& student) {
                return get<0>(student) == name;
        });

    if (it != students.end()) {
        printStudent(*it);
    }
    else {
        cout << "\nStudent with name " << name
             << " was not found." << endl;
    }
}
};
int main() {
	GradeBook& gradeBook = GradeBook::getInstance();

	gradeBook.LoadFromFile("Firstdata.txt");
	gradeBook.print();

	gradeBook.add("Mei", 5, 91.0);
	gradeBook.print();

	gradeBook.deleteStudent(2);
	gradeBook.print();

	gradeBook.sortByScore();
	gradeBook.print();

	cout << "\n--- Search Student ---" << endl;
	gradeBook.searchById(3);
    gradeBook.searchByName("Mei");
	return 0;
}
	
		