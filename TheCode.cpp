#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> 
#include <climits>

using namespace std;

const int maxRows = 10;
const int cols = 6;

int main() {
    int numRows = 5;

    string employeeTable[maxRows][cols] = {
        {"\0", "SUN", "MON", "TUE", "WED", "THU"},
        {"Noura", "8", "7", "7", "5", "9"},
        {"Aziz", "9", "9", "10", "12", "5"},
        {"Deem", "6", "10", "11", "10", "9"},
        {"Omar", "8", "11", "5", "8", "12"}
    };

   string ModifiedTable[maxRows][cols];
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ModifiedTable[i][j] = employeeTable[i][j];
            cout << setw(4) << ModifiedTable[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
	for (int i = 1; i < numRows; ++i) {
        for (int j = 1; j < cols; ++j) {
            int value = stoi(ModifiedTable[i][j]); // Convert string to integer
            if (value < 6) {
                cout << "The hours for " << ModifiedTable[i][0] << " on " << ModifiedTable[0][j] << " was changed to be 6" << endl;
            }
        }
    }
    cout << endl;

    // Change values under 6 to 6 and track modified employees
    for (int i = 1; i < numRows; ++i) {
        for (int j = 1; j < cols; ++j) {
            int value = stoi(ModifiedTable[i][j]); // Convert string to integer
            if (value < 6) {
                ModifiedTable[i][j] = "6";
            }
        }
    }

    // Print the modified table
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(4) << ModifiedTable[i][j] << "\t";
        }
        cout << endl;
    }
  
    // Find the day with the highest total working hours
    int maxTotalHours = 0;
    string maxDay;

    for (int j = 1; j < cols; ++j) {
        int totalHours = 0;
        for (int i = 1; i < numRows; ++i) {
            totalHours += stoi(employeeTable[i][j]);
        }
        if (totalHours > maxTotalHours) {
            maxTotalHours = totalHours;
            maxDay = employeeTable[0][j];
        }
    }

    // Find the day with the lowest total working hours
    int minTotalHours = INT_MAX;
    string minDay;

    for (int j = 1; j < cols; ++j) {
        int totalHours = 0;
        for (int i = 1; i < numRows; ++i) {
            totalHours += stoi(employeeTable[i][j]);
        }
        if (totalHours < minTotalHours) {
            minTotalHours = totalHours;
            minDay = employeeTable[0][j];
        }
    }

    // Print the results
    cout << "\nThe day with the highest total working hours: " << maxDay << endl;
    cout << "The day with the lowest total working hours: " << minDay << endl;

    int choice = 0;
    while (choice != 3) {
        cout << "------------------------------------------------------" << endl;
        cout << "\nChoose one of the following options:" << endl;
        cout << "1. Add a new Employee." << endl;
        cout << "2. Enquire about an Employee." << endl;
        cout << "3. Exit" << endl << endl;
        cin >> choice;

        if (choice == 1) {
                // Option 1: Add a new Employee
                string newName;
                cout << "\n\nEnter the Employee Name: ";
                cin >> newName;
                ModifiedTable[numRows][0] = newName;

                cout << "Enter the working hours of the week: ";
                for (int j = 1; j < cols; ++j) {
                    cin >> ModifiedTable[numRows][j];
                }

                cout << "\nNew Entry Added." << endl << endl;
                numRows++;
                
				// Print the modified table
                for (int i = 0; i < numRows; ++i) { // Change 'rows' to 'numRows'
                    for (int j = 0; j < cols; ++j) {
                        cout << setw(4) << ModifiedTable[i][j] << "\t";
                    }
                    cout << endl;
                }
        } else if (choice == 2) {
        	
            // Option 2: Enquire about an Employee
            string name;
            cout << "\nEnter the employee name: ";
            cin >> name;

            // Convert name to lowercase using transform function
            transform(name.begin(), name.end(), name.begin(), ::tolower);

            int sum = 0;
            bool found = false;

            for (int i = 1; i < numRows; i++) {
            	
                // Convert employee name to lowercase using transform function
                string employeeName = ModifiedTable[i][0];
                transform(employeeName.begin(), employeeName.end(), employeeName.begin(), ::tolower);

                if (name == employeeName) {
                    found = true;
                    
                    sum = 0;
                    int hours=0;
                    int salary=0;

                    for (int j = 1; j < cols; j++) {
                    	int hours=0;
                        sum += stoi(ModifiedTable[i][j]);
                        if (stoi(ModifiedTable[i][j]) > 9){
                        	hours = stoi(ModifiedTable[i][j]) - 9;
                        	salary += 9*100;
                        	salary += hours*200;
						}else{
                        	salary += (stoi(ModifiedTable[i][j]))*100;							
						}
                    }
                    cout << ModifiedTable[i][0] << "has worked " << sum << " hours in the week."<< endl;

                    int maxHours = 0;
                    string maxDay2;

                    for (int j = 1; j < cols; ++j) {
                        int Hours = stoi(ModifiedTable[i][j]);
                        if (Hours > maxHours) {
                            maxHours = Hours;
                            maxDay2 = ModifiedTable[0][j];
                        }
                    }
                    cout << "The day that " << name << " has the highest working hours is " << maxDay2 << endl;
                    cout << name << " Salary: " << salary << " SAR in the week" << endl;
                    break;
                }
            }
            if (!found) {
                cout << "\nSorry, the employee does not exist." << endl;
            }
        } else if (choice == 3) {
            cout << "\nThank you for using our system." << endl;
        }
    }
    return 0;
}




