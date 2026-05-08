#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    string studentName;

    // Take student name as input
    cout << "Enter the student's name: ";
    getline(cin, studentName);

    // Store funny excuses
    vector<string> excuses = {
        "{name} forgot the homework at home.",
        "{name}'s dog ate the assignment.",
        "{name} was busy saving the world.",
        "{name}'s laptop suddenly crashed.",
        "{name} thought the homework was optional.",
        "{name} accidentally deleted the file.",
        "{name} had no internet connection.",
        "{name} was abducted by aliens yesterday.",
        "{name}'s notebook mysteriously disappeared.",
        "{name} thought today was a holiday."
    };

    // Generate random index
    srand(time(0));
    int randomIndex = rand() % excuses.size();

    // Select random excuse
    string finalExcuse = excuses[randomIndex];

    // Replace {name} with actual name
    size_t position = finalExcuse.find("{name}");

    if (position != string::npos) {
        finalExcuse.replace(position, 6, studentName);
    }

    // Display final excuse
    cout << "\nGenerated Excuse:\n";
    cout << finalExcuse << endl;

    return 0;
}