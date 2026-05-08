#include <iostream>
#include <string>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

int main() {
    string name;

    // Step 1: Take user input
    cout << "Enter your name: ";
    getline(cin, name);

    // Step 2: Store roast messages
    string roasts[10] = {
        "{name}, you bring everyone joy… when you leave.",
        "{name}, you are not stupid, just unlucky when thinking.",
        "{name}, if laziness were a sport, you'd come second.",
        "{name}, your brain has too many tabs open… and none working.",
        "{name}, you're like a cloud. When you go away, it's a good day.",
        "{name}, I would explain it… but you wouldn’t get it.",
        "{name}, you are the reason instructions exist.",
        "{name}, you're not useless… you can still be a bad example.",
        "{name}, even Google can’t understand you.",
        "{name}, you have something on your chin… no, the third one."
    };

    // Step 3: Random selection
    srand(time(0));                  // seed random generator
    int index = rand() % 10;         // random index (0–9)

    string result = roasts[index];

    // Step 4: Replace {name} with actual name
    size_t pos = result.find("{name}");
    if (pos != string::npos) {
        result.replace(pos, 6, name);
    }

    // Step 5: Print final message
    cout << "\nFunny Roast:\n";
    cout << result << endl;

    return 0;
}