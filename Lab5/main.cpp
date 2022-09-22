#include <iostream>
#include <string>
using namespace std;

string GetUserInput(string& userChoice) {
    cin >> userChoice;
    return userChoice;
}

bool ChangePath(int pathLeft, int pathRight) {
    bool whichPath;

    if (pathLeft == 1) {
        whichPath = true;
    }
    if (pathRight == 1) {
        whichPath = false;
    }
    return whichPath;
}

void DateChoiceText() {
    cout << "\na) You take your shot and ask the cute person in your YSA ward out on a date this weekend." << endl;
    cout << "OR" << endl;
    cout << "b) You push away the sense of urgency and tell yourself that everything will happen in God's timing." << endl;

    cout << "\nPlease input a or b: " << endl;
    return;
}

void DateLocationText() {
    cout << "\na) They're showing the Godfather at International Cinema. (pretending to be knowledgable about classic cinema)." << endl;
    cout << "OR" << endl;
    cout << "b) I heard the view at Squaw Peak was pretty nice." << endl;
    cout << "c) I'm not sure... (Choose a random location)";
    cout << "\nPlease input a, b, or c: " << endl;
}

void gameOver() {
    string userText;
    cout << "\nWould you like to retry this decision? Input y or n";
    cin >> userText;

    if (userText.find('y') != string::npos) {
    }
    else if (userText.find('Y') != string::npos) {
    }
    else if (userText.find('n') != string::npos) {
        cout << "Thank you for playing!";
        exit(0);
    }
    else if (userText.find('N') != string::npos) {
        cout << "Thank you for playing!";
        exit(0);
    }
    else {
        cout << "Input not recognized. Ending game. Please try again.";
        exit(0);
    }
}

void randomPlace() {

    int locationValue;
    locationValue = rand() % 3;

    if (locationValue == 0){
        cout << "\n\"How about Nickel City?\" you suggest.";
    }
    else if (locationValue == 1) {
        cout << "\n\"Let's go to the mall!\" you exclaim.";
    }
    else if (locationValue == 2){
        cout << "\n\"My parents live pretty close by!\" you suggest sheepishly.";
    }
}

void bonusGame() {
    int numKids;

    cout << "\nBonus! Enter your favorite number!";
    cin >> numKids;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Not a valid number. Please reenter: ";
        cin >> numKids;
    }

    srand(time(0));
    cout << "\nThe number of kids you will have together: " << rand() % numKids << "!";
    cout << "\nThank you for playing!";
}

void waitingGame () {
    int minutes;

    srand(time(0));
    minutes = (rand() % 15) + 1;

    for (int i = 1;i <= minutes;++i) {
        cout << i  << ", ";
    }
    cout << " minutes pass." << endl;
}

int main() {
    int pathCorrect = 0;
    int pathIncorrect = 0;
    bool pathChoice;
    bool retry = true;
    string userInput;


    //Starting point

    while (retry == true) {

        cout << "Your Eternal Family professor strongly encourages you to start going on more dates";
        cout << " to find an eternal companion." << endl;

        //Prompt user input

        DateChoiceText();
        GetUserInput(userInput);


        //Decision 1

        if (userInput.find('a') != string::npos) {
            cout << "\nYou find them between classes and ask her out.";
            cout << "They says she needs to think about it and will text you back." << endl;
            cout << "You begin to wait nervously..." << endl;
            waitingGame();

            cout << "\nTo your amazement, they say yes.";
            cout << " Your new date then asks where you are planning to go. You respond with: " << endl;
            retry = false;
        }
        else if (userInput.find('A') != string::npos) {
            cout << "\nYou find them between classes and ask her out.";
            cout << "They says she needs to think about it and will text you back." << endl;
            cout << "You begin to wait nervously..." << endl;
            waitingGame();

            cout << "\nTo you amazement, they say yes";
            cout << " Your new date then asks where you are planning to go. You respond with: " << endl;
            retry = false;
        }
        else if (userInput.find('b') != string::npos) {
            cout << "\nUnlike you imagined, you continue to blow off chance after chance";
            cout << "and go on endlessly wondering if you will ever find the one\nEND" << endl;
            gameOver();
        }
        else if (userInput.find('B') != string::npos) {
            cout << "\nUnlike you imagined, you continue to blow off chance after chance";
            cout << "and go on endlessly wondering if you will ever find the one\nEND" << endl;
            gameOver();
        }
        else {
            cout << "\nPlease change input to either a or b and try again." << endl;
            gameOver();
        }
    }

    //Decision 2

    DateLocationText();
    GetUserInput(userInput);


    if (userInput.find('a') != string::npos) {
        cout << "\nThey are surprised at your sense of culture and agree to go see the movie.";
        cout << " They also reveal they are a film major.";
        cout << " The day of the date arrives." << endl;
        pathCorrect = 1;
        pathIncorrect = 0;
    }
    else if (userInput.find('A') != string::npos) {
        cout << "\nThey are surprised at your sense of culture and agree to go see the movie.";
        cout << " They also reveal they are a film major.";
        cout << " The day of the date arrives." << endl;
        pathCorrect = 1;
        pathIncorrect = 0;
    }
    else if (userInput.find('b') != string::npos) {
        cout << "\nThey agrees and you drive up to everyone's favorite viewpoint.";
        cout << " After actually enjoying the view for 5 minutes, the moment of truth comes." << endl;
        pathCorrect = 0;
        pathIncorrect = 1;
    }
    else if (userInput.find('B') != string::npos) {
        cout << "\nThey agrees and you drive up to everyone's favorite viewpoint.";
        cout << " After actually enjoying the view for 5 minutes, the moment of truth comes." << endl;
        pathCorrect = 0;
        pathIncorrect = 1;
    }
    else if (userInput.find('c') != string::npos) {
        randomPlace();
        cout << "\nShe responds \"On second thought, I think I'll pass\" to which you have no words to respond with.";
        cout << "\nEND";
        exit(0);
    }
    else if (userInput.find('C') != string::npos) {
        randomPlace();
        cout << "\nShe responds \"On second thought, I think I'll pass\" to which you have no words to respond with.";
        cout << "\nEND";
        exit(0);
    }
    else {
        cout << "\nPlease change input to either a, b, or c and try again." << endl;
        exit(0);
    }

    pathChoice = ChangePath(pathCorrect, pathIncorrect);


    if (pathChoice == true) {
        cout << "\na) You keep up your charade that you know all about films and their history." << endl;
        cout << "OR" << endl;
        cout << "b) You come clean and let them know that you were trying to impress them." << endl;
        pathCorrect = 1;
        pathIncorrect = 0;
    }

    if (pathChoice == false) {
        cout << "\na) Kiss them" << endl;
        cout << "OR" << endl;
        cout << "b) Just hold hands" << endl;
        pathCorrect = 0;
        pathIncorrect = 1;
    }

    //Decision 3


    cout << "\n Please input a or b: " << endl;
    GetUserInput(userInput);

    pathChoice = ChangePath(pathCorrect, pathIncorrect);

    if (userInput.find('a') != string::npos && pathChoice == true) {
        cout << "\nAfter the movie, when you inevitably go to the BYU Creamery for ice cream, ";
        cout << "your false knowledge about cinema catches up and your date calls you out for pretending.";
        cout << "\nThere is no second date." << endl;
        cout << "\nEND" << endl;
        exit(0);
    }
    else if (userInput.find('A') != string::npos && pathChoice == true) {
        cout << "\nAfter the movie, when you inevitably go to the BYU Creamery for ice cream, ";
        cout << "your false knowledge about cinema catches up and your date calls you out for pretending.";
        cout << "\nThere is no second date." << endl;
        cout << "\nEND" << endl;
        exit(0);
    }
    else if (userInput.find('b') != string::npos && pathChoice == true) {
        cout << "\nYou come clean and they laugh, saying it was cute that you were so excited to go out. ";
        cout << "You two enjoy the movie, your first successful date of your life. ";
        cout << "\nYou're excited to go again, and want to ask for a second date." << endl;
    }
    else if (userInput.find('B') != string::npos && pathChoice == true) {
        cout << "\nYou come clean and they laugh, saying it was cute that you were so excited to go out. ";
        cout << "You two enjoy the movie, your first successful date of your life. ";
        cout << "\nYou're excited to go again, and want to ask for a second date." << endl;
    }
    else if (userInput.find('a') != string::npos && pathChoice == false) {
        cout << "\nOne awkward kiss and a silent drive home later, you are home in your apartment. ";
        cout << "One week later, after having pains and a cough, you learn you got mono." << endl;
        cout << "\nEND" << endl;
        exit(0);
    }
    else if (userInput.find('A') != string::npos && pathChoice == false) {
        cout << "\nOne awkward kiss and a silent drive home later, you are home in your apartment. ";
        cout << "One week later, after having pains and a cough, you learn you got mono." << endl;
        cout << "\nEND" << endl;
        exit(0);
    }
    else if (userInput.find('b') != string::npos && pathChoice == false) {
        cout << "\nYou just decide hold hands and have a nice time. ";
        cout << "You continue to try a few more dates, but it doesn't really get anywhere, ";
        cout << "but no hard feelings are left." << endl;
        cout << "\nEND" << endl;
        exit(0);
    }
    else if (userInput.find('B') != string::npos && pathChoice == false) {
        cout << "\nYou just decide hold hands and have a nice time. ";
        cout << "You continue to try a few more dates, but it doesn't really get anywhere, ";
        cout << "but no hard feelings are left." << endl;
        cout << "\nEND" << endl;
        exit(0);
    }
    else {
        cout << "\nPlease change input to either a or b and try again." << endl;
        exit(0);
    }


    cout << "\na) Be bold and ask them out on a second date." << endl;
    cout << "OR" << endl;
    cout << "b) Panic, say thanks and go home to play Smash Brothers with your roommates." << endl;

    //Decision 4

    cout << "\nPlease input a or b: " << endl;
    GetUserInput(userInput);


    if (userInput.find('a') != string::npos) {
        cout << "\nThey smile and say of course! ";
        cout << "Time passes, dates continue and next thing you know, ";
        cout << "you are getting married in the City Center Temple." << endl;
        cout << "\nHAPPY END" << endl;
        bonusGame();
        exit(0);
    }
    else if (userInput.find('A') != string::npos) {
        cout << "\nThey smile and say of course! ";
        cout << "Time passes, dates continue and next thing you know, ";
        cout << "you are getting married in the City Center Temple." << endl;
        cout << "\nHAPPY END" << endl;
        bonusGame();
        exit(0);
    }
    else if (userInput.find('b') != string::npos) {
        cout << "\nYou panic and choke, say thanks and head home. ";
        cout << "Frustrated by not being able to ask them out again, ";
        cout <<"you relieve stress with some games, waiting for the courage to come, ";
        cout << "but it never does. You realize weeks later you missed your chance." << endl;
        cout << "\nEND" << endl;
    }
    else if (userInput.find('B') != string::npos) {
        cout << "\nYou panic and choke, say thanks and head home. ";
        cout << "Frustrated by not being able to ask them out again, ";
        cout <<"you relieve stress with some games, waiting for the courage to come, ";
        cout << "but it never does. You realize weeks later you missed your chance." << endl;
        cout << "\nEND" << endl;
    }
    else {
        cout << "\nPlease change input to either a or b and try again." << endl;
        exit(0);
    }

    return 0;
}