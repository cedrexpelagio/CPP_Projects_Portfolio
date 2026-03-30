#include<iostream>
#include<string>
#include<limits>
using namespace std;

int maximumReps (int level) {
    switch (level) {
    case 1:
        return 10;
    case 2:
        return 20;
    case 3:
        return 100;
    }
}

int maximumSets (int level) {
    switch (level) {
    case 1:
        return 3;
    case 2:
        return 5;
    case 3:
        return 10;
    }
}

int userLevel () {
    int level = 0;
    cout << "Level: " << endl;
    cout << "1. Beginner" << endl;
    cout << "2. Intermediate" << endl;
    cout << "3. Expert" << endl;
    do {
        cout << "Enter your level: ";
        cin >> level;
        if (level > 3 || level < 1) {
            cout << "Invalid Level [1 - 3 only]" << endl;
        }
    } while (level > 3 || level < 1);

    switch (level) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    }
}

string restPerSet (int numReps [], int a) {

    if (numReps [a] >= 1 && numReps [a] <= 100) {

        if (numReps [a] >= 1 && numReps [a] <= 10) {
            return "1 min each set";
        } else if (numReps [a] <= 20) {
            return "2 mins each set";
        } else if (numReps [a] <= 50) {
            return "5 mins each set";
        } else if (numReps [a] <= 100) {
            return "15 mins each set";
        }

    }

}

string workoutPPL (int workoutDay) {
    switch (workoutDay) {
    case 1:
    case 4:
        return "Push Day";
    case 2:
    case 5:
        return "Pull Day";
    case 3:
    case 6:
        return "Leg Day";
    case 7:
        return "Rest Day";
    }
}

void displayExercises(string exercises[], int numReps[], int numSets[], int numExercise) {
    cout << "\nYour Workout Routine" << endl;
    cout << "-------------------------------" << endl;
    for (int a = 0; a < numExercise; a++) {
        cout << exercises[a] << " " << numReps[a] << " × " << numSets[a] << endl;
        cout << "Recommend Rest: " << restPerSet (numReps, a) << endl;
    }
    cout << "-------------------------------" << endl;
}


void workoutListing () {
    int level = userLevel ();
    maximumSets (level);
    int numExercise = 0;
    int numReps [10];
    int numSets [10];
    string exercises [10];

    cout << "Number of exercise(s): " ;
    cin >> numExercise;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < numExercise; i++) {
        cout << "-------------------------------" << endl;
        cout << "Exercise " << i + 1 << "   : ";
        getline (cin, exercises [i]);

        do {
            cout << "Repetition(s): ";
            cin >> numReps [i];
            if (numReps [i] > maximumReps (level)) {
                cout << "Invalid. " << maximumReps (level) << " Maximum Reps only." << endl;
            } else if (numReps [i] < 0) {
                cout << "Invalid. Reps are below zero." << endl;
            } else if (numReps [i] == 0)  {
                cout << "Invalid. Zero Rep." << endl;
            }

        } while (numReps [i] > maximumReps (level) || numReps [i] <= 0);

        do {
            cout << "Set(s)       : ";
            cin >> numSets [i];
            if (numSets [i]  > maximumSets (level)) {
                cout << "Invalid. " << maximumSets (level) << " Maximum Sets only." << endl;
            } else if (numSets [i] < 0) {
                cout << "Invalid. Sets are below zero." << endl;
            } else if (numSets [i] == 0) {
                cout << "Invalid. Zero Set." << endl;
            }

        } while (numSets [i] > maximumSets (level) || numSets [i] <= 0);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }
    cout << "-------------------------------" << endl;

    displayExercises(exercises,numReps,numSets, numExercise);
}

void workoutMenu () {
    int workoutDay = 0;

    do {
        cout << "\nEnter Workout Day [1-7]: ";
        cin >> workoutDay;
    } while (workoutDay < 1 || workoutDay > 7);

    cout << "\n----- " << workoutPPL (workoutDay) << " -----" << endl;

    if (workoutDay >= 1 && workoutDay <= 7) {
        workoutListing ();
    }

}

void mainMenuOption (int option) {

    switch (option) {
    case 1:
        workoutMenu ();
        break;
    case 2:
        workoutListing ();
        break;
    case 3:
        cout << "\nThank you Broskie for using the program! "  << endl;
        break;
    }

}


int mainMenu () {

    int option = 0;

    cout << "Main Menu:" << endl;

    cout << "1. Create Routine using PPL" << endl;
    cout << "2. Create a Workout Routine" << endl;
    cout << "3. Exit Workout Planner" << endl;
    do {
        cout << "Select your option [1-3]: ";
        cin >> option;
    } while (option < 1 || option > 3);
    cout << "-------------------------------" << endl;
    mainMenuOption (option);
    if (option == 3) {
        return 0;
    }
}

void secondMenuOption (int option) {

    switch (option) {
    case 1:
        cout << endl;
        mainMenu ();
        break;
    case 2:
        workoutListing ();
        break;
    case 3:

        break;
    case 4:
        cout << "\nThank you Broskie for using the program! "  << endl;
        break;
    }


}


int secondMenu () {

    int option = 0;

    cout << "\nMenu:" << endl;

    cout << "1. Go back to the Main Menu" << endl;
    cout << "2. Create a new Workout Routine" << endl;
    cout << "3. Repeat the Workout Routine" << endl;
    cout << "4. Exit Workout Planner" << endl;
    do {
    cout << "Select your option: ";
    cin >> option;
    } while (option < 1 || option > 4);

    secondMenuOption (option);

    if (option == 4) {
        return 0;
    }

}

int main()
{
    cout << "----- CED WORKOUT PLANNER -----" << endl;

    if (mainMenu () == 0) {
        return 0;
    }
    if (secondMenu () == 0) {
        return 0;
    }

}