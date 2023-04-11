// FileInput.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "Employee.h"

using namespace std;

int main(int argc, char** argv)
{
    //Check for command line error
    if (argc == 1) {
        cout << "You forgot the command line parameter" << endl;
        exit(0);
    }

    //Check for file
    ifstream ifs;
    ifs.open(argv[1], ios::in);
    if (!ifs) {
        cout << "could not find file " << argv[1] << endl;
        exit(0);
    }

    //Get how many lines
    string line;
    getline(ifs, line);
    int n = stoi(line);

    //initializing an array
    Employee** employee = new Employee * [n];

    //loop through file
    for (int i = 0; i < n; i++) {
        int age;
        int id;
        int year;
        string name;
        string job;
        string ids;
        string a;
        string y;
        getline(ifs, name, '|');
        getline(ifs, ids, '|');
        getline(ifs, a, '|');
        getline(ifs, job, '|');
        getline(ifs, y);
        id = stoi(ids);
        age = stoi(a);
        year = stoi(y);
        Employee* emp = new Employee(name, id, age, job, year);

        //Add to array
        employee[i] = emp;
    }

    //Get who to find
    string find;
    getline(ifs, find);
    int f = stoi(find);

    double avg = 0;


    //Loop through each ID to check
    for (int i = 0; i < f; i++) {
        string finds;
        getline(ifs, finds);
        int found = stoi(finds);
        int comparison = 0;


        int low = 0;
        int high = n;
        int mid = 0;
        int index = 0;
        while (low < high) {
            //Get mid value
            mid = ((low + high) / 2);
            comparison++;

            //Check for matching ID
            if (found <= employee[mid]->getID()) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
            //cout << high;
        }

        //Print matched ID
        avg += comparison;
        employee[high]->printState();
        cout << "at index " << high << " after " << comparison << " comparisons." << endl;
    }

    //Print the average comparisons
    cout << "Done! Average amount of work per query: " << avg / f << " comparisons." << endl;

}
