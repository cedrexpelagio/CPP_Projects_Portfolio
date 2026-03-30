#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <limits>

using namespace std;

// Declaration of functions
void clearScreen();
void dash();
void title();
void delay(double seSc);
void loading (double sec);
bool maxLength (string word, char category);
void printPlevelAndTime(string pMode, string printL, double time);
string printMode(int mode);
string printpLevel(int pLevel);
int menuValidator(int mini, int maxi, string menu, string topDisplay, bool pTitle);
void printTimeFormat(double time);
int pLevelMenu(string pMode);
double availableHourMenu(string pMode, int pLevel, int mode, string printL);
int timeCoverter(double time);
bool maxHour(int pLevel, double time, int mode);
void exitMode();
string login();
void evaluatioHeader();
int productivityPoints();
// Study Mode Functions
string studyBlockName(int sPur, int studyBlockNo);
string studyBlockTips(int sPur, int studyBlockNo);
int recoStudyMins(int mins, int pLevel);
int recoStudyRest(int studyMins);
void genStudTimeBlock(double time, int pLevel,int sPur, string topic);
void studyMode(int mode);
// Fitness Mode Functions
int recoRepsExercise (int pLevel, int fLevel);
int recoSetsExercise(int fLevel);
double repAndSetMins(int reps, int sets, int fLevel);
double recoRestExercise(double exerciseMins);
string genExerciseName(int exerciseMode, int fLevel, int blockNo);
void genExercises(double time, int pLevel, int fLevel, string exerciseModeCat[], int exerciseMode);
void fitnessMode(int mode);
// Planning Mode Functions
bool isInvalidTaskNum(int taskNum, int pLevel);
double recoImportantTaskBlock(int blockNo, int taskNum, double time);
double recoNormalTask(int taskNum, double time);
void genPlanTimeBlock(string taskName[], double time, int taskNum, int pLevel, bool importantTask);
void planningMode(int mode);
// Menu Functions
void modes(int mode);
int mainMenu();
int secondMenu(int lastMode);
// Main Function
int main()
{
    // Declaration of variables
    int lastMode = 0;
    int mode = 0;
    int pPoints = 0;
    int exitChoice = 0;
    int secMenuChoice = 0;
    char y_n;
    string userName = "";

    userName = login(); // The user login

    do {
        mode = mainMenu();
        // Display the second menu after the mode
        if (mode >= 1 && mode <= 3) {
            modes(mode);
            lastMode = mode; // Store the last mode used
            pPoints += productivityPoints(); // Compute the productivity points
            title();
            cout << "Thank You Using this Mode!" << endl;
            delay(1);
            cout << "Directing to Menu..." << endl;
            delay(5);
            secMenuChoice = secondMenu(lastMode); // Display the second menu
            // Identify the choice in second menu
            if (secMenuChoice == 0) {
                continue;
            } else if (secMenuChoice == 4) {
                mode = 4;
            }
        }
        // Confirm if the user want exit
        if (mode == 4) {
            do {
                title();
                loading(2.5);
                title();
                cout << "Do you really want to exit?[Y]/[N]: ";
                cin >> y_n;
                if (y_n == 'Y' || y_n == 'y') {
                    exitChoice = 1; // Yes
                    title();
                } else if (y_n == 'N' || y_n == 'n') {
                    exitChoice = 0; // No
                    cout << "Returning to Main Menu..." << endl;
                    delay(2.5);
                } else {
                    title();
                    cout << "Invalid Input, Try Again!" << endl;
                    delay(2.5);
                    exitChoice = 2; // Invalid
                }
            } while (exitChoice == 2); // Loop when invalid input
        }
    } while (exitChoice == 0); // Loop when user input N/n
    // Display a thank you message and productivity points of the day
    cout << "Total Productivity Points: " << pPoints << endl;
    cout << "Thank you " << userName << " for using the program!" << endl;
    dash();
    return 0;
}
// Function that clear the screen
void clearScreen()
{
#ifdef _WIN32 // For Window
    system("CLS");
#else // For Android
    cout << "\033[2J\033[1;1H";
#endif
}
// Function that display dashes
void dash()
{
    cout << "----------------------------------------" << endl;
}
// Function that display the project title
void title()
{
    clearScreen();// Clear the screen
    dash(); // Display the title
    cout << "      PALA-Desisyon: Your Personal" << endl;
    cout << "       Planner Assistant in Life " << endl;
    cout << "     Activities: A Decision Fatigue" << endl;
    cout << "           Reducer for Student      " << endl;
    dash();
    cout << endl;
}
// Function that delay the output based in second
void delay(double sec)
{
    int miliSec = sec * 1000; // Compute the milisecond
    std::this_thread::sleep_for(std::chrono::milliseconds(miliSec));
}
// Function that display a loading text with computed delay based in second
void loading(double sec)
{
    cout << "Loading..." << endl;
    delay(sec);
}
// Function that compute max length and validated the length of word
bool maxLength(string word, char category)
{
    int wordLength = 0;
    int maxLengthWord = 0;
    int miniLengthWord = 0;
    wordLength = word.length(); // Identify the length

    switch (category) {
    case 'u': // Max and Minimum character for user name
        maxLengthWord = 20;
        miniLengthWord = 3;
        break;
    case 't': // Max and Minimum character for topic in study mode
        maxLengthWord = 40;
        miniLengthWord = 5;
        break;
    }
    // Check if the length is valid
    if (wordLength > maxLengthWord || wordLength < miniLengthWord) {
        dash();
        cout << "Ideal Character Length " << miniLengthWord << " - " << maxLengthWord << endl;
        dash();
        delay(1);
        cout << "Try again, ";
        delay (1);
        loading(2);
        return true; // Invalid
    } else {
        return false; // Valid
    }
}
// Function that print Productivity Level and Available Time
void printPlevelAndTime(string pMode, string printL, double time)
{
    title (); // Input: User Enter Study Purpose
    cout << pMode << endl;
    cout << "Productivity Level: " << printL << endl;
    cout << "Available Time    : ";
    printTimeFormat(time);
    cout << "hour/s" << endl;
}
// Function that turn the mode into text
string printMode(int mode)
{
    switch(mode) {
    case 1:
        return "Study Mode";
    case 2:
        return "Fitness Mode";
    case 3:
        return "Planning Mode";
    }
    return "";
}
// Function that turn productivity level into text
string printpLevel(int  pLevel)
{
    switch (pLevel) {
    case 1:
        return "Low Productivity";
    case 2:
        return "Medium Productivity";
    case 3:
        return "High Productivity";
    }
    return "";
}
// Function that print menu and validate input
int menuValidator(int mini, int maxi, string menu, string topDisplay, bool pTitle)
{
    int choice = 0;
    do {
        if (pTitle) { // display a title when true
            title ();
        }
        cout << topDisplay << endl;
        cout << menu; // Display the menu
        cin >> choice; // User Enter a choice
        if (choice < mini || choice > maxi) { // Display a warning if invalid
            cout << "Invalid Choice, Try Again!" << endl;
            delay(1);
            loading(2.5);
            if (!pTitle) {
                return -1;//Return a invalid sign for menu with UI summary
            }
        }
    } while (choice < mini || choice > maxi); // Loop if invalid input
    return choice;
}
// Function that display time in a format
void printTimeFormat(double time)
{
    int totalMinutes = time * 60; // Compute hour into minutes
    int hour = totalMinutes / 60; // Compute the total hour without decimal
    int mins = totalMinutes % 60; // Compute the minutes

    cout << hour << ":"; // Display the hour

    if(mins < 10) {
        cout << "0";// Display 0 when the minutes is less than 10
    }
    cout << mins; // Display the minutes
}
// Function that display productivity level menu
int pLevelMenu(string pMode)
{
    int pLevel = 0;
    const int mini = 1;
    const int maxi = 3;
    const string menu = "Productivity Level\n[1] Low\n[2] Medium\n[3] High\nEnter your level : ";
    pLevel = menuValidator(mini,maxi,menu,pMode,true);
    return pLevel;
}
// Function that print available hour menu, validate inputs and check max hour
double availableHourMenu(string pMode, int pLevel, int mode, string printL)
{
    bool maxx;
    double hour = 0;
    double mins = 0;
    double converterHour = 0;
    double converterMins = 0;
    do {
        do {
            title();// Input: User Enter Available Time
            cout << pMode << endl;
            cout << "Productivity Level: " << printL << endl;
            dash();
            cout << "Available Hour for " << pMode << endl;
            cout << "Enter in Hour (ex. 1 space 30): ";
            cin >> hour;
            cin >> mins;

            converterHour = hour;
            mins /= 60;
            converterMins = mins;

            converterHour += converterMins;

            if (converterHour <= 0) {
                title(); // Display Warning
                cout << "Invalid Input, Try Again!" << endl;
                cout << hour << ":" << mins << " Hour is Not Allowed!" << endl;
                loading(4);
            }
        } while (converterHour <= 0); // Loop when decimal hour is less than or equal zero
        maxx = maxHour(pLevel,converterHour, mode);
    } while (!maxx); // Loop when reach the max hour
    return converterHour; // Return the Decimal Time
}
// Function that convert decimal time to integer
int timeCoverter(double time)
{
    const int sixty = 60;
    int coverteredTime = 0;
    coverteredTime = time * sixty; // Compute
    return coverteredTime;
}
// Function that determine if the user reach the max hour and display warning
bool maxHour(int pLevel, double time, int mode)
{
    string printL = printpLevel(pLevel);
    string pMode = printMode(mode);
    double maxH[3];
    double maxH02 = 0;
    double minH = 0;
    // Process: Assign Max Hour based on mode and productivity level
    switch (mode) {
    case 1: // Study Max Hour
        maxH[0]= 2;
        maxH[1]= 4;
        maxH[2]= 8;
        minH = 0.25;
        break;
    case 2: // Fitness Max Hour
        maxH[0]= 0.5;
        maxH[1]= 1;
        maxH[2]= 1.5;
        minH = 0.25;
        break;
    case 3: // Planning Max Hour
        maxH[0]= 6;
        maxH[1]= 10;
        maxH[2]= 16;
        minH = 1;
        break;
    }
    // Check if the user reach the max hour or not
    if (time > maxH[pLevel-1] || time < minH) {
        title();
        cout << "WARNING:" << endl;
        delay(1.5);
        dash();
        maxH02 = maxH[pLevel-1];
        cout << "Hour must be between ";
        printTimeFormat(minH);
        cout << " and ";
        printTimeFormat(maxH02);
        cout << " in" << endl;
        cout << pMode << " " << printL << endl;
        dash();
        delay(2.5);
        cout << "Returning..." << endl;
        delay(5);
        return false; // Max Hour
    } else {
        return true;// Valid
    }
}
// Function for exiting a mode
void exitMode()
{
    int exit = 0;

    cout << "Enter Any Number to Exit: ";
    cin >> exit;
    cout << "Exiting..." << endl;
    delay (5);
}
// Function that display the login
string login()
{
    string userName = "";
    bool userNameLength;

    do {
        title();
        cout << "LOGIN" << endl;
        dash();// User enter name
        cout << "Enter User Name: ";
        getline(cin, userName);
        userNameLength = maxLength (userName,'u');
    } while (userNameLength); // loop when name length reach the max
    dash();

    cout << "Hello " << userName << "!" << endl; // Greet the user
    cout << "Welcome to PALA-Desisyon," << endl;
    cout << "Your Personal Planner" << endl;
    dash();
    delay(2.5);
    loading(2.5);
    return userName; // Return the user name

}
void evaluatioHeader()
{
    title();
    cout << "SELF EVALUATION" << endl;
    dash();
    cout << "Evaluate your performance" << endl;
    cout << "during the activity" << endl;
    dash();
}
// Function that allows the user evaluate there performance
int productivityPoints()
{
    // Declaration of variables
    int prodLevel = 0;   // Productivity level input
    int focusLevel = 0;  // Focus level input
    int moodLevel = 0;   // Mood level input
    int totalPoints = 0;// Total productivity points
    int exitM = 0;      // Exit input holder

    // Menu input limits
    const int mini = 1;
    const int maxi = 3;

    // Productivity evaluation menu
    const string prodMenu = {
        "[1] Low Productivity\n"
        "[2] Medium Productivity\n"
        "[3] High Productivity\n"
        "Enter your productivity level: "
    };

    // Focus evaluation menu
    const string focusMenu = {
        "[1] Low Focus\n"
        "[2] Medium Focus\n"
        "[3] High Focus\n"
        "Enter your focus level: "
    };

    // Mood evaluation menu
    const string moodMenu = {
        "[1] Bad Mood\n"
        "[2] Neutral Mood\n"
        "[3] Good Mood\n"
        "Enter your mood: "
    };

    // Get productivity level from user
    do {
        evaluatioHeader();
        prodLevel = menuValidator(mini, maxi, prodMenu, "Productivity Evaluation:", false);
    } while (prodLevel == -1);

    // Get focus level from user
    do {
        evaluatioHeader();
        focusLevel = menuValidator(mini, maxi, focusMenu, "Focus Evaluation:", false);
    } while (focusLevel == -1);

    // Get mood level from user
    do {
        evaluatioHeader();
        moodLevel = menuValidator(mini, maxi, moodMenu, "Mood Evaluation:", false);
    } while (moodLevel == -1);

    // Compute total productivity points
    totalPoints = prodLevel + focusLevel + moodLevel;

    // Display evaluation result
    evaluatioHeader();
    cout << "Productivity Level : " << prodLevel << endl;
    cout << "Focus Level        : " << focusLevel << endl;
    cout << "Mood               : " << moodLevel << endl;
    cout << "Total Productivity Points: " << totalPoints << " / 9" << endl;
    dash();

    // Pause before exiting evaluation
    cout << "Enter a Number to Continue: ";
    cin >> exitM;

    // Return total productivity score
    return totalPoints;
}
// Study Mode Functions
// Function that generate the study block name
// Function that returns the study block name based on study purpose
string studyBlockName(int sPur, int studyBlockNo)
{
    const int maxNumBlock = 5; // Maximum number of study blocks

    // Validate block number range
    if (studyBlockNo < 0 || studyBlockNo >= maxNumBlock) {
        return "";
    }

    // Block names for review purpose
    string reviewBlock[maxNumBlock] = {
        "Review Notes/Material",
        "Active Recall",
        "Practice Problems",
        "Error Review",
        "Active Recall"
    };

    // Block names for study purpose
    string studyBlock[maxNumBlock] = {
        "Learn the Material",
        "Active Recall",
        "Apply Concept",
        "Error Review",
        "Active Recall"
    };

    // Block names for skill-building purpose
    string skillBlock[maxNumBlock] = {
        "Understand the Skill",
        "Guided Practice",
        "Independent Practice",
        "Reflection & Improvement",
        "Independent Practice"
    };

    // Return block name based on study purpose
    switch (sPur) {
    case 1:
        return reviewBlock[studyBlockNo];
    case 2:
        return studyBlock[studyBlockNo];
    case 3:
        return skillBlock[studyBlockNo];
    default:
        return "";
    }
}

// Function that returns study tips based on study purpose
string studyBlockTips(int sPur, int studyBlockNo)
{
    const int MAX_BLOCK = 5; // Maximum number of tips

    // Validate block number range
    if (studyBlockNo < 0 || studyBlockNo >= MAX_BLOCK) {
        return "";
    }

    // Tips for review mode
    string reviewTips[MAX_BLOCK] = {
        "Read and highlight key ideas",
        "Recall concepts from memory",
        "Answer practice questions",
        "Review and correct mistakes",
        "Recall again without notes"
    };

    // Tips for study mode
    string studyTips[MAX_BLOCK] = {
        "Read and take short notes",
        "Explain ideas from memory",
        "Apply concepts to examples",
        "Fix misunderstandings",
        "Recall without notes"
    };

    // Tips for skill-building mode
    string skillTips[MAX_BLOCK] = {
        "Study the fundamentals",
        "Follow guided practice",
        "Practice independently",
        "Review and improve output",
        "Practice again"
    };

    // Return tips based on study purpose
    switch (sPur) {
    case 1:
        return reviewTips[studyBlockNo];
    case 2:
        return studyTips[studyBlockNo];
    case 3:
        return skillTips[studyBlockNo];
    default:
        return "";
    }
}
// Function that recommend study minutes per block
int recoStudyMins(int mins, int pLevel)
{
    if (mins >= 30) {
        if (mins <= 150 && pLevel <= 2) { // Low to Medium Productivity - 0.5 to 2.5 Hour
            return 25;
        } else if (mins <= 150 && pLevel == 3) { // High Productivity - 0.5 to 2.5 Hour
            return 30;
        } else if (mins <= 200 && pLevel >= 2) { // Medium to High Productivity - 2.6 to 3.3 Hour
            return 35;
        } else if (mins <= 250 && pLevel >= 2) { // Medium to High Productivity - 3.4 to 4.1 Hour
            return 40;
        } else if (mins <= 300 && pLevel == 3) { // High Productivity - 4.2 to 5 Hour
            return 50;
        } else if (mins <= 350 && pLevel == 3) { // High Productivity - 5.1 to 5.8 Hour
            return 60;
        } else if (mins <= 400 && pLevel == 3) { // High Productivity - 5.9 to 6.6 Hour
            return 70;
        } else if (mins <= 450 && pLevel == 3) { // High Productivity - 6.7 to 7.5 Hour
            return 80;
        } else if (mins <= 480 && pLevel == 3) { // High Productivity - 7.6 to 8 Hour
            return 90;
        }
    } else {
        return mins;
    }
    return 25;
}
// Function that recommend rest minutes per block
int recoStudyRest(int studyMins)
{
    if (studyMins >= 25 && studyMins <= 35) {
        return 5;
    } else if (studyMins >= 40 && studyMins <= 50) {
        return 10;
    } else if (studyMins >= 60 && studyMins <= 90) {
        return 15;
    }
    return 5;
}
// Function for Generating Time Blocks
void genStudTimeBlock(double time, int pLevel, int sPur, string topic)
{
    int mins = 0;        // Total available time in minutes
    int rest = 0;        // Rest time per block
    int studyMins = 0;   // Study time per block
    int blockMins = 0;   // Total minutes per block (study + rest)
    const int maxNumBlock = 5; // Maximum number of study blocks
    string tips = "";    // Study tips for each block
    string blockName = ""; // Name of the study block

    // Convert total time from hours to minutes
    mins = timeCoverter(time);
    // Recommend study minutes based on productivity level
    studyMins = recoStudyMins(mins, pLevel);
    // Recommend rest minutes based on study minutes
    rest = recoStudyRest(studyMins);
    // Total minutes consumed per block
    blockMins = studyMins + rest;
    title();
    cout << "Topic: " << topic << endl;
    dash();

    int blockCount = 0; // Counter for study blocks
    // Generate study blocks while time is available and block limit is not reached
    while (mins > 0 && blockCount < maxNumBlock) {

        // Get block name and tips based on study purpose
        blockName = studyBlockName(sPur, blockCount);
        tips = studyBlockTips(sPur, blockCount);

        // Handle last block when remaining time is less than a full block
        if (mins <= blockMins) {

            // If remaining time is only enough for rest
            if (rest > mins) {
                cout << "Rest: + " << mins << " mins" << endl;
                break;
            }
            // If remaining time is used as a final study block
            else {
                cout << "Study Block " << blockCount + 1 << ": " << blockName << endl;
                cout << "Time: " << mins << " mins" << endl;
                cout << "Tips: " << tips << endl;
                dash();
                break;
            }
        }

        // Normal full study block (Block 1–4)
        cout << "Study Block " << blockCount + 1 << ": " << blockName << endl;
        cout << "Time: " << studyMins << " mins" << endl;
        cout << "Rest: " << rest << " mins" << endl;
        cout << "Tips: " << tips << endl;
        dash();

        // Deduct used time and move to next block
        mins -= blockMins;
        blockCount++;
    }
    exitMode();
}
// Function for Study Mode
void studyMode(int mode)
{
    // Declaration of variables
    int pLevel = 0; // Productivity Level
    int sPur = 0; // Study Purpose
    bool topicLength = false;
    double time = 0;
    const int mini = 1;
    const int maxi = 3;
    const string topDisplay = "Study Purpose: ";
    const string SPurmenu = "[1] Review for a Quiz/Exam\n[2] Study a Concept\n[3] Learn a Skill\nEnter your choice: ";
    string printL = "";
    string pMode = "";
    string topic = "";
    string sPurCat[3] = {"Review for a Quiz/Exam", "Study a Concept", "Learn a Skill"}; // Collection of Study Purpose Category

    pMode = printMode(mode);

    pLevel = pLevelMenu(pMode);//Print Productivity Menu and Check Invalid Input
    printL = printpLevel(pLevel);
    time = availableHourMenu(pMode, pLevel, mode, printL);//Print a Menu for Time Input and Check Invalid Input

    do {
        printPlevelAndTime(pMode,printL,time); // Display Productivity and Time
        dash();
        sPur = menuValidator(mini,maxi,SPurmenu,topDisplay,false); // Display the study purpose menu
    } while (sPur == -1);

    do {
    printPlevelAndTime(pMode,printL,time); // Input: User Enter Topic
    cout << "Study Purpose     : " << sPurCat[sPur-1] << endl;
    dash();
    cout << "Enter Topic to Study: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, topic);
    topicLength = maxLength(topic, 't');
    } while (topicLength);

    printPlevelAndTime(pMode,printL,time);
    cout << "Study Purpose     : " << sPurCat[sPur-1] << endl;
    cout << "Topic to Study    : " << topic << endl;
    dash();
    cout << "Generating Study Time Blocks..." << endl;
    delay(5);

    // Output: Display study time blocks
    genStudTimeBlock(time, pLevel, sPur, topic);
}
// Fitness Mode
// Function that Recommend Repetition (reps) of exercises
int recoRepsExercise (int pLevel, int fLevel)
{
    // Nested Switch to Determine the Repetition (reps) of exercises
    switch (pLevel) {
    case 1:// Low Productivity
        switch(fLevel) {// Fitness Level
        case 1:// Beginner
            return 4;// Return Repetition of Exercises
        case 2:// Medium
            return 6;
        case 3:// Expert
            return 10;
        }
    case 2:// Medium Productivity
        switch(fLevel) {
        case 1:
            return 6;
        case 2:
            return 10;
        case 3:
            return 15;
        }
    case 3:// High Productivity
        switch(fLevel) {
        case 1:
            return 8;
        case 2:
            return 14;
        case 3:
            return 20;
        }
    }
    return 0;
}
// Function that Recommends Set per Exercise
int recoSetsExercise(int fLevel)
{
    // Beginner = 2, Medium = 3, Professional = 4
    return fLevel + 1;
}
// Function that converts repetition and sets of exercises to minutes
double repAndSetMins(int reps, int sets, int fLevel)
{
    double exerciseSecReps = 0;
    double const secInMin = 60;
    double exerciseSec = 0;
    double exerciseMins = 0;
    // Beginner = 4, Medium = 3, Expert = 2
    exerciseSecReps += (5 - fLevel);// Exercise Second based on Fitness Level
    exerciseSec = (reps * exerciseSecReps) * sets;// Compute a rep total second
    exerciseMins = exerciseSec / secInMin;// Converts second to minute

    // Round off the minutes
    // Return the estimated minute of each exercise
    if (exerciseMins > 0 && exerciseMins <= 0.5) {
        return 0.5;
    } else if (exerciseMins > 0.5 && exerciseMins <= 1) {
        return 1;
    } else if (exerciseMins > 1 && exerciseMins <= 1.5) {
        return 1.5;
    } else if (exerciseMins > 1.5 && exerciseMins <= 2) {
        return 2;
    } else if (exerciseMins > 2 && exerciseMins <= 2.5) {
        return 2.5;
    } else if (exerciseMins > 2.5 && exerciseMins <= 3) {
        return 3;
    }
    return 0;
}
// Function that recommend rest
double recoRestExercise(double exerciseMins)
{
    if (exerciseMins > 0 && exerciseMins <= 1) {
        return 1;
    } else if (exerciseMins > 1 && exerciseMins <= 2) {
        return 2;
    } else if (exerciseMins > 2 && exerciseMins <= 3) {
        return 3;
    }
    return 0;
}
// Function that Generate Name of Exercise
string genExerciseName(int exerciseMode, int fLevel, int blockNo)
{
    int const maxNumBlock = 10; // Maximum block

    // Push Mode
    string pushflevel_1[maxNumBlock] = { // Exercise based on fitness level
        "Wall Push-Ups", "Incline Push-Ups",
        "Knee Push-Ups", "Wide Knee Push-Ups",
        "Close-Grip Knee Push-Ups", "Bench Dips(Feet Bent)",
        "Isometric Push-Up Hold(Top)", "Shoulder Taps(Knee)",
        "Slow Tempo Knee Push-Ups", "Push-Up Plus(Scapular)"
    };
    string pushflevel_2[maxNumBlock] = {
        "Standard Push-Ups", "Wide Push-Ups",
        "Diamond Push-Ups", "Decline Push-Ups",
        "Archer Push-Ups", "Pike Push-Ups",
        "Pseudo Planche Push-Ups", "Explosive Push-Ups",
        "Ring Push-Ups", "Elevated Pike Push-Ups"
    };
    string pushflevel_3[maxNumBlock] = {
        "Handstand Hold(Wall)", "Handstand Push-Ups(Wall)",
        "Deficit Push-Ups", "Planche Lean Push-Ups",
        "Tiger Bend Push-Ups", "One-Arm Push-Up(Assisted)",
        "90-Degree Push-Ups", "Clap Push-Ups",
        "Korean Dips", "One-Arm Push-Ups"
    };
    // Pull Mode
    string pullflevel_1[maxNumBlock] = {
        "Dead Hang", "Active Hang",
        "Scapular Pull-Ups", "Australian Rows",
        "Assisted Pull-Ups", "Negative Pull-Ups",
        "Flexed Arm Hang", "Chin-Up Negatives",
        "Towel Rows", "Hollow Hang"
    };
    string pullflevel_2[maxNumBlock] = {
        "Chin-Ups", "Pull-Ups",
        "Neutral-Grip Pull-Ups", "Close-Grip Pull-Ups",
        "Wide-Grip Pull-Ups", "Commando Pull-Ups",
        "Archer Pull-Ups(Assisted)", "Explosive Pull-Ups",
        "Chest-to-Bar Pull-Ups", "L-Sit Pull-Ups"
    };
    string pullflevel_3[maxNumBlock] = {
        "Muscle-Up(Strict)", "Archer Pull-Ups(Full)",
        "Typewriter Pull-Ups", "One-Arm Pull-Up(Assisted)",
        "Towel Pull-Ups", "Ice Cream Makers",
        "Front Lever Raises", "Front Lever Pull-Ups",
        "One-Arm Pull-Up", "Muscle-Up to Pull-Up Combo"
    };
    // Lower Mode
    string lowerflevel_1[maxNumBlock] = {
        "Bodyweight Squats", "Box Squats",
        "Reverse Lunges", "Step-Ups",
        "Glute Bridges", "Standing Calf Raises",
        "Wall Sit", "Knee Raises(Lying)",
        "Crunches", "Plank"
    };
    string lowerflevel_2[maxNumBlock] = {
        "Jump Squats", "Walking Lunges",
        "Bulgarian Split Squats", "Single-Leg Romanian Deadlift",
        "Lateral Lunges", "Box Jumps",
        "Seated Calf Raises", "Hanging Knee Raises",
        "Russian Twists", "Side Plank"
    };
    string lowerflevel_3[maxNumBlock] = {
        "Pistol Squats", "Shrimp Squats",
        "Jump Lunges", "Nordic Hamstring Curls",
        "Cossack Squats", "Depth Jumps",
        "Single-Leg Box Jumps", "Hanging Leg Raises",
        "Toes-to-Bar", "Dragon Flags"
    };

    switch (exerciseMode) {
    case 1: // Push Mode
        switch (fLevel) {
        case 1: // Return the exercise based on fitness level
            return pushflevel_1[blockNo];
        case 2:
            return pushflevel_2[blockNo];
        case 3:
            return pushflevel_3[blockNo];
        }
    case 2: // Pull Mode
        switch (fLevel) {
        case 1:
            return pullflevel_1[blockNo];
        case 2:
            return pullflevel_2[blockNo];
        case 3:
            return pullflevel_3[blockNo];
        }
    case 3: // Lower Mode
        switch (fLevel) {
        case 1:
            return lowerflevel_1[blockNo];
        case 2:
            return lowerflevel_2[blockNo];
        case 3:
            return lowerflevel_3[blockNo];
        }
    }
    return "";
}
// Function that Generate Exercises
void genExercises(double time, int pLevel, int fLevel, string exerciseModeCat[], int exerciseMode)
{
    int mins = 0;                // Total available workout time in minutes
    int reps = 0;                // Recommended repetitions per set
    int sets = 0;                // Recommended number of sets
    int exerciseBlockMins = 0;   // Total minutes per exercise block
    double rest = 0;             // Rest time between reps
    double exerciseMins = 0;     // Time required to complete one set
    double blockMins = 0;        // Total time required per block
    const int maxNumBlock = 10;  // Maximum number of exercise blocks
    string tips = "";            // Exercise tips (reserved)
    string exerciseName = "";    // Generated exercise name

    // Convert total workout time from hours to minutes
    mins = timeCoverter(time);
    // Recommend repetitions based on productivity and fitness level
    reps = recoRepsExercise(pLevel, fLevel);
    // Recommend sets based on fitness level
    sets = recoSetsExercise(fLevel);
    // Compute minutes needed per set based on reps and fitness level
    exerciseMins = repAndSetMins(reps, sets, fLevel);
    // Recommend rest time based on exercise duration
    rest = recoRestExercise(exerciseMins);
    // Total time needed per exercise block
    blockMins = (exerciseMins + rest) * sets;

    title();
    cout << "Mode: " << exerciseModeCat[exerciseMode - 1] << endl;
    dash();

    // Warm-up and cool-down allocation
    cout << "Warm Up: 5 mins" << endl;
    mins -= 10; // Reserve time for warm-up and cool-down
    dash();

    int blockCount = 0; // Counter for exercise blocks

    // Generate exercise blocks while time and block limits allow
    while (mins > 0 && blockCount < maxNumBlock && mins >= blockMins) {

        // Generate exercise name based on mode and fitness level
        exerciseName = genExerciseName(exerciseMode, fLevel, blockCount);

        cout << "Exercise Block " << blockCount + 1 << ": " << endl;
        cout << exerciseName << " " << reps << " x " << sets << endl;
        cout << "Rest: " << rest << " mins after each reps" << endl;

        // Insert water break after specific blocks
        if (mins >= blockMins) {
            if (blockCount == 2 || blockCount == 5 || blockCount == 8) {
                cout << "Water Break: 5 mins" << endl;
                mins -= 5;
            }
        }
        // Display total time for the exercise block
        exerciseBlockMins = blockMins;
        cout << "Total Block Time: " << exerciseBlockMins << " mins" << endl;
        dash();
        // Deduct used time and move to next exercise block
        mins -= blockMins;
        blockCount++;
    }
    // Cool-down section
    cout << "Cool Down: 5 mins" << endl;
    dash();

    // Exit exercise mode
    exitMode();
}
// Function for Fitness Mode
void fitnessMode(int mode)
{
    // Declaration of variables
    int pLevel = 0; // Productivity Level
    int fLevel = 0; // Fitness Level
    int exerciseMode = 0;
    const int mini = 1;
    const int maxi = 3;
    double time = 0;
    string printL = "";
    string pMode = "";
    string exerciseName = "";
    string topDisplay = "";
    const string fLevelMenu = "[1] Beginner\n[2] Medium\n[3] Expert\nEnter your level: ";
    const string exerciseModeMenu = "[1] Push Mode\n[2] Pull Mode\n[3] Lower Mode\nEnter your mode: ";
    string fLevelCat[3] = {"Beginner","Medium","Expert"}; // Collection of Fitness Level Category
    string exerciseModeCat[3] = {"Push Mode","Pull Mode","Lower Mode"}; // Collection of Exercise Mode Category
    pMode = printMode(mode);

    pMode = printMode(mode);
    pLevel = pLevelMenu(pMode);//Print Productivity Menu and Check Invalid Input
    printL = printpLevel(pLevel);
    time = availableHourMenu(pMode, pLevel, mode, printL);//Print a Menu for Time Input and Check Invalid Input

    do {
        printPlevelAndTime(pMode,printL,time); // Display Productivity and Time
        dash();
        topDisplay = "Fitness Level: ";
        fLevel = menuValidator(mini,maxi,fLevelMenu,topDisplay,false); // Display the fitness level menu and validate
    } while (fLevel == -1);

    do {
        printPlevelAndTime(pMode,printL,time); // Display Productivity and Time
        cout << "Fitness Level     : " << fLevelCat[fLevel-1] << " Level" << endl; // Display the fitness level
        dash();
        topDisplay = "Exercise Mode: ";
        exerciseMode = menuValidator(mini,maxi,exerciseModeMenu,topDisplay,false); // Display the fitness level menu and validate
    } while (exerciseMode == -1);

    printPlevelAndTime(pMode,printL,time); // Output: Display the Users Input
    cout << "Fitness Level     : " << fLevelCat[fLevel-1] << " Level" << endl;
    cout << "Exercise Mode     : " << exerciseModeCat[exerciseMode-1] << endl;
    dash();
    cout << "Generating Exercises..." << endl;
    delay(5);
    genExercises(time, pLevel,fLevel, exerciseModeCat, exerciseMode);
}
// Planning Mode
// Function that limit number of task based on time
bool isInvalidTaskNum(int taskNum, int pLevel)
{
    int minTask = 0, maxTask = 0;

    if (pLevel == 1) {
        minTask = 3;
        maxTask = 5;
    }
    if (pLevel == 2) {
        minTask = 4;
        maxTask = 8;
    }
    if (pLevel == 3) {
        minTask = 5;
        maxTask = 10;
    }

    if (taskNum < minTask || taskNum > maxTask) {
        cout << "Task number must be between " << minTask << " and " << maxTask << endl;
        delay(1);
        loading(2);
        return true; // invalid
    } else {
        return false; // valid
    }
}

// Function that recommend plan time blocks on important task
double recoImportantTaskBlock (int blockNo,int taskNum, double time)
{
    int minorTasks = 0;
    double remaining = 0;

    if (taskNum == 4) { // Percentage for time division if task number is 4
        switch (blockNo) {
        case 0:
            return time * 0.35;
        case 1:
            return time * 0.30;
        case 2:
            return time * 0.20;
        case 3:
            return time * 0.15;
        }
    } else { // Percentage for time division if task number is greater than 4
        switch (blockNo) {
        case 0:
            return time * 0.30;
        case 1:
            return time * 0.25;
        case 2:
            return time * 0.20;
        }
        minorTasks = taskNum - 3;
        remaining = time * 0.25;
        return remaining / minorTasks;
    }

    return 0;
}
double recoNormalTask(int taskNum, double time)
{
    return time / taskNum; // time division for 3 task
}
// Function that generate plan for task
void genPlanTimeBlock(string taskName[], double time, int taskNum, int pLevel, bool importantTask)
{
    int mins = 0;                // Total available time in minutes
    string blockName = "";       // Name of the task block
    mins = timeCoverter(time);   // Convert total time from hours to minutes
    double restMins = 0;         // Rest time per task block
    int totalBlockMins = 0;      // Total minutes used per task block
    double timeUsed = 0;         // Accumulator for total time used
    double planHours = 0;        // Planned work hours per task

    title();
    cout << "Number of Task: " << taskNum << endl;
    dash();

    // Generate time blocks for each task
    for (int blockNo = 0; blockNo < taskNum; blockNo++) {

        // Determine time allocation based on task importance
        if (importantTask) {
            planHours = recoImportantTaskBlock(blockNo, taskNum, time);
        } else {
            planHours = recoNormalTask(taskNum, time);
        }

        // Compute rest time as 15% of planned work time
        restMins = planHours * 0.15;
        // Adjust work time after subtracting rest time
        planHours -= restMins;
        // Convert total block time and rest time to minutes
        totalBlockMins = timeCoverter(planHours + restMins);
        restMins = timeCoverter(restMins);

        // Display task plan details
        cout << "Plan Block " << blockNo + 1 << " " << taskName[blockNo] << endl;
        cout << "Work: ";
        printTimeFormat(planHours);
        cout << " hour/s" << endl;
        cout << "Rest: " << restMins << " mins " << endl;
        dash();
        // Track total time used
        timeUsed += totalBlockMins;
        // Deduct used time and stop if time runs out
        mins -= totalBlockMins;
        if (mins <= 0) break;
    }
    // Exit planning mode
    exitMode();
}
// Function for Planning Mode
void planningMode(int mode)
{
    // Declaration of variables
    int pLevel = 0; // Productivity Level
    int taskNum = 0 ; // Number of task
    const int MAX_TASKS = 10;
    double time = 0;
    string printL = "";
    string pMode = "";
    bool maxMinTask = false;
    bool importantTask = false;
    pMode = printMode(mode);

    pMode = printMode(mode);
    pLevel = pLevelMenu(pMode);//Print Productivity Menu and Check Invalid Input
    printL = printpLevel(pLevel);
    time = availableHourMenu(pMode, pLevel, mode, printL);//Print a Menu for Time Input and Check Invalid Input

    do {
        printPlevelAndTime(pMode,printL,time); // Input: User Enter Number of Task
        dash();
        cout << "Enter Number of Task: ";
        cin >> taskNum;
        maxMinTask = isInvalidTaskNum(taskNum,pLevel);// Check the maximum task based on time
    } while (maxMinTask);
    string taskName[MAX_TASKS]; // Collection of Task Name
    printPlevelAndTime(pMode,printL,time);
    cout << "Number of Task    : " << taskNum << endl;
    dash();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (taskNum > 3) { // Display when task number is greater than 4
        importantTask = true;
        cout << "Enter 3 Most Important Tasks:" << endl;
    } else {
        importantTask = false;
        cout << "Enter Tasks:" << endl; // Display when task number is 3 below
    }

    for (int i = 0; i < taskNum; i++) {
        if (i == 3) { // Display when task number is greater than 4 after the important task
            cout << "Enter Minor Tasks:" << endl;
        }
        cout << i + 1 << ". ";
        getline(cin, taskName[i]);
    }
    dash();
    cout << "Generating a Plan..." << endl;
    delay(5);
    genPlanTimeBlock(taskName,time,taskNum, pLevel,importantTask);
}
// Function to activate the three main function
void modes(int mode)
{
    switch (mode) {
    case 1:
        studyMode(mode);
        break;
    case 2:
        fitnessMode(mode);
        break;
    case 3:
        planningMode(mode);
        break;
    }
}
// Function for the second menu
int secondMenu(int lastMode)
{
    // Declaration of variables
    int choice = 0; // Choice for the menu
    int mode = 0; // Mode
    string pMode = ""; // Name of the mode
    const int mini = 1;
    const int maxi = 3;
    const string topDisplay = "Menu: ";
    const string menu = "[1] Go back to Main Menu\n[2] Use the Recent Mode\n[3] Exit\nSelect your choice: ";
    pMode = printMode(lastMode); // Add value to the name of the mode

    do {
        choice = menuValidator(mini,maxi,menu,topDisplay,true);// Display the Second Menu

        // Process: Perform task based on choice
        switch (choice) {
        case 1: // Go back to the main menu
            title();
            loading(3);
            return 0;
            break;
        case 2: // Activate the recent mode
            title ();
            cout << "Returning to " << pMode << "..." << endl;
            delay(5);
            mode = lastMode;
            modes(mode);
            break;
        case 3: // Exit the menu
            return 4;
            break;
        }
    } while (mode >= 1 && mode <= 3);

    return 0;
}
// Function: The main menu of the entire program
int mainMenu ()
{
    // Declaration of variables
    int mode = 0;
    const int mini = 1;
    const int maxi = 4;
    const string pMode = "Main Menu: ";
    const string menu = "[1] Study Mode\n[2] Fitness Mode\n[3] Planning Mode\n[4] Exit\nSelect your mode: ";
    mode = menuValidator(mini,maxi,menu,pMode,true); // Display the main menu
    return mode;
}
