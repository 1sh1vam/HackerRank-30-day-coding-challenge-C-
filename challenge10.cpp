#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student :  public Person{
	private:
		vector<int> testScores;  
        
	public:
        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
        Student(string firstName, string lastName, int identification, vector<int> scores):Person(firstName, lastName, identification){
            this->testScores = scores;
        }
        /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
        char calculate(){
            int sum=0, n=0;
            char grade;
            int avg;
            for(auto i=testScores.begin(); i!=testScores.end(); i++){
                sum = sum + *i;
                n = n+1;
            }
            avg = sum/n;
           if(avg>=90){
                grade = 'O';
            }
            else if(avg>=80){
                grade = 'E';
            }
            else if(avg>=70){
                grade = 'A';
            }
            else if(avg<70 & avg>=55){
                grade = 'P';
            }
            else if(avg>=40 and avg <55){
                grade = 'D';
            }
            else{
                grade = 'T';
            }
            
            return grade;
        }
       
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}