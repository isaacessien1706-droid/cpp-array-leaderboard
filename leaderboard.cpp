#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_LEADERS = 5;

struct Player {
    string name;
    int score;
};

void displayLeaderboard(const Player board[], int size) {
    cout << "\n=========================================\n";
    cout << "          TOP 5 HIGH SCORES              \n";
    cout << "=========================================\n";
    cout << left << setw(8) << "RANK" << setw(14) << "ARRAY INDEX" << setw(12) << "PLAYER" << "SCORE\n";
    cout << "-----------------------------------------\n";

    for (int i = 0; i < size; ++i) {
        cout << left << "#" << setw(7) << (i + 1)
             << "board[" << i << "]      "
             << setw(12) << board[i].name
             << board[i].score << "\n";
    }

    cout << "=========================================\n";
}

void addNewScore(Player board[], int size, const string& newName, int newScore) {
    if (newScore <= board[size - 1].score) {
        cout << "\n[!] Sorry, " << newScore << " points wasn't enough to beat #5 (" << board[size - 1].score << " pts).\n";
        return;
    }

    int insertIndex = size - 1;
    for (int i = 0; i < size; ++i) {
        if (newScore > board[i].score) {
            insertIndex = i;
            break;
        }
    }

    for (int j = size - 1; j > insertIndex; --j) {
        board[j] = board[j - 1];
    }

    board[insertIndex].name = newName;
    board[insertIndex].score = newScore;

    cout << "\n[+] NEW HIGH SCORE! " << newName << " claimed Rank #"
         << (insertIndex + 1) << " at board[" << insertIndex << "]!\n";
}

void searchPlayer(const Player board[], int size, const string& targetName) {
    for (int i = 0; i < size; ++i) {
        if (board[i].name == targetName) {
            cout << "\nFound! " << targetName << " is currently at Rank #" << (i + 1)
                 << " (Index " << i << ") with " << board[i].score << " points.\n";
            return;
        }
    }
    cout << "\nPlayer '" << targetName << "' is not on the Top 5 Leaderboard.\n";
}

int main() {
    Player leaderboard[MAX_LEADERS] = {
        {"Abena", 2500},
        {"Kwame", 2150},
        {"Joel", 1800},
        {"Kofi", 1450},
        {"Ama", 1100}
    };

    int choice;
    string playerName;
    int playerScore;

    do {
        cout << "\n--- ARCADE LEADERBOARD MENU ---\n";
        cout << "1. View Top 5 Leaderboard\n";
        cout << "2. Submit a New Score\n";
        cout << "3. Search Player Rank\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayLeaderboard(leaderboard, MAX_LEADERS);
                break;
            case 2:
                cout << "Enter player first name: ";
                cin >> playerName;
                cout << "Enter score achieved: ";
                cin >> playerScore;
                addNewScore(leaderboard, MAX_LEADERS, playerName, playerScore);
                displayLeaderboard(leaderboard, MAX_LEADERS);
                break;
            case 3:
                cout << "Enter player name to search: ";
                cin >> playerName;
                searchPlayer(leaderboard, MAX_LEADERS, playerName);
                break;
            case 4:
                cout << "Exiting Leaderboard System. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Please choose between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}