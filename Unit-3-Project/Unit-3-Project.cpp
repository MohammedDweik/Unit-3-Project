#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>   

using namespace std;

int numberofplayers;
int input;
string username;
vector <int> V;
vector <string> A;
int total = 0;
int add = 0;

class PlayerInfo {

public:

    PlayerInfo() {
        cout << "Hello user, this is a program that allows you to enter amount of players, and username and score for each player" << endl;
        cout << endl;
    }
    int Getnumberofuserandscore() {

        cout << "Enter number of players : ";
        cin >> numberofplayers;
        while (numberofplayers > 8 || numberofplayers < 1) {
            cout << numberofplayers << " players is an invalid amount of players" << endl;
            cout << "Enter number of players : " << endl;;
            cin >> numberofplayers;
        }
        if (numberofplayers <= 8 && numberofplayers >= 1)
            cout << numberofplayers << " players have been entered" << endl;
        cout << endl;

        return numberofplayers;

    }

    vector<int> Getscore() {

        for (int i = 0; i < numberofplayers; i++) {
            cout << "Enter score for player: " << i + 1 << endl;
            cin >> input;
            cin.ignore(256, '\n');
            cin.clear();
            while (input < 0) {
                cout << "Invalid score " << endl;
                cout << "Enter score for player: " << i << endl;
                cin >> input;
            }
            if (input >= 0);
            V.push_back(input);
        }
        for (int i = 0; i < V.size(); i++) {
            cout << "Player " << i + 1 << " has a score of " << endl;
            cout << V[i] << endl;
            cout << endl;
        }
        return V;
    }


    vector<string> Getusername() {

        for (int i = 0; i < numberofplayers; i++) {
            cout << "Enter name for player " << i + 1 << endl;
            getline(cin, username);

            while (username.size() >= 40) {
                cout << "Name is too long " << endl;
                cout << "Please enter name for player " << i << " again" << endl;
                getline(cin, username);
            }
            if (username.size() <= 40);

            A.push_back(username);
        }

        for (int i = 0; i < A.size(); i++) {
            cout << "Player " << i + 1 << " has a name of " << A[i] << endl;
        }
        return A;
    }

    int  GetTotalScore() {
        for (int i = 0; i < numberofplayers; i++) {
            total = total + V[i];
        }

        cout << "The total score of all players is: " << total << endl;
        return total;
    }


};


void DisplayScore() {
    int i = 0;
    total = 0;

    for (i = 0; i < numberofplayers + add; i++) {
        cout << "Player " << A[i] << " has a score of " << V[i] << endl;
    }

    for (i = 0; i < numberofplayers + add; i++) {
        total += V[i];
    }
    cout << "The total score of all players is " << total << endl;
}

void SearchName() {

    string searchterm;
    int i = 0;


    cout << "What player are you looking for? " << endl;
    cout << "Please enter player name: " << endl;
    cin >> searchterm;


    for (int i = 0; i < numberofplayers + add; i++) {
        if (A[i] == searchterm)
            cout << "Element " << A[i] << " present at index " << i + 1 << endl;
    }

}


void ResetEntry() {

    int i = 0;
    string str;
    vector<string>::iterator iter = A.begin();
    vector<int>::iterator itr = V.begin();

    cout << "Please enter usename for player you are looking to reset: " << endl;
    cin >> str;


    while (A[i] != str)
    {
        i++;
    }
    if (A[i] == str)
    {
        A.at(i) = " ";
        V.at(i) = 0;

    }

    cout << "Player has now been reset" << endl;
}



void UpdateEntry() {

    int i = 0;
    int newscore = 0;
    string searchterm;
    string newname;

    cout << "What player name are you looking to update? " << endl;
    cout << "Please enter player name: " << endl;
    cin >> searchterm;

    for (i = 0; i < numberofplayers + add; i++)
    {
        if (searchterm == A[i])
        {
            cout << "Please enter new name for player: " << endl;
            cin >> newname;
            cin.ignore(256, '\n');
            cin.clear();

            A.at(i) = newname;

            cout << "Please enter new score for player: " << endl;
            cin >> newscore;

            V.at(i) = newscore;

        }

    }

    cout << "Player has now been updated" << endl;

}

void calculate() {

    vector<int> V_sorted(V.size());
    partial_sort_copy(begin(V), end(V), begin(V_sorted), end(V_sorted));

    if (numberofplayers + add >= 4) {
        cout << "Player lowest score is " << V_sorted[0] << endl;
        cout << "The third highest score is " << V_sorted[numberofplayers + add - 3] << endl;
        cout << "The second highest score is " << V_sorted[numberofplayers + add - 2] << endl;
        cout << "The highest score is " << V_sorted.back() << endl;

        cout << "The average score is: " << total / numberofplayers + add << endl;
    }

    if (numberofplayers + add == 3) {
        cout << "Player lowest score is " << V_sorted[0] << endl;
        cout << "The second highest score is " << V_sorted[numberofplayers + add - 2] << endl;
        cout << "The highest score is " << V_sorted.back() << endl;

        cout << "The average score is: " << total / numberofplayers + add << endl;
    }

    if (numberofplayers + add == 2) {
        cout << "Player lowest score is " << V_sorted[0] << endl;
        cout << "The highest score is " << V_sorted.back() << endl;

        cout << "The average score is: " << total / numberofplayers + add << endl;
    }

    if (numberofplayers + add == 1) {
        cout << "The only and highest score is " << V_sorted.back() << endl;

        cout << "The average score is: " << total / numberofplayers + add << endl;
    }



}

void addplayer() {

    string newname;
    int newnewscore = 0;
    cout << "How many players would you like to add " << endl;
    cin >> add;
    while (numberofplayers + add > 8) {
        cout << "Too many players" << endl;
        cout << "Number of players must be a maximum of 8" << endl;
        cout << "Please enter number of players again" << endl;
        cin >> add;
        if (numberofplayers == 8)
            cout << "You have reached the maximum amount of players" << endl;
    }

    for (int i = 0; i < add; i++) {
        cout << "Please enter player name for added player: " << i + 1 << endl;
        cin >> newname;

        A.emplace_back(newname);

        cout << "Please enter player score for added player: " << i + 1 << endl;
        cin >> newnewscore;

        V.emplace_back(newnewscore);
    }

    if (add > 1)
    {
        cout << "Players have now been added" << endl;

    }
    if (add == 1)
        cout << "Player has now been added " << endl;

}

void SwapPlayer() {

    int i = 0;
    int a = 0;
    string swapname;
    string swapname2;

    cout << "Please enter the first player name you would like to swap scores with: " << endl;
    cin >> swapname;

    while (A[i] != swapname) {
        i++;
    }


    cout << "Please enter the second player name you would like to swap scores with: " << endl;
    cin >> swapname2;

    while (A[a] != swapname2) {
        a++;
    }


    iter_swap(V.begin() + i, V.begin() + a);

    cout << "Players have now been swapped" << endl;
}

int main()
{
    char command;
    char again = 'y';

    PlayerInfo playerinfo1;
    playerinfo1.Getnumberofuserandscore();
    playerinfo1.Getscore();
    playerinfo1.Getusername();
    playerinfo1.GetTotalScore();

    while (again == 'y' || again == 'Y') {
        cout << "What is your command" << endl;
        cout << "Enter d to display score" << endl;
        cout << "Enter s to search name" << endl;
        cout << "Enter r to reset entry" << endl;
        cout << "Enter u to update entry" << endl;
        cout << "Enter c to view player rankings " << endl;
        cout << "Enter a to add player" << endl;
        cout << "Enter p to swap two players" << endl;

        cout << "Or enter q to quit the program" << endl;
        cin >> command;

        switch (command) {
        case ('d'):
            DisplayScore();
            break;
        case ('s'):
            SearchName();
            break;
        case ('r'):
            ResetEntry();
            break;
        case ('u'):
            UpdateEntry();
            break;
        case ('c'):
            calculate();
            break;
        case ('a'):
            addplayer();
            break;
        case('p'):
            SwapPlayer();
            break;
        default:
            cout << "That is an invalid character" << endl;
        }
        cout << "Would you like to access menu again y/n " << endl;
        cin >> again;
    }
}














