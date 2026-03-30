#include<iostream>
using namespace std;

int main()
{
    int num_votes = 0;
    int vote = 0;
    int loop = 0;
    int votes[4] {0,0,0,0};
    int candidate_num = 0;
    string winner = "";

    do {
        cout << "CANDIDATES:" << endl;
        cout << "1. Alice Cruz" << endl;
        cout << "2. Bryan Dela Cruz" << endl;
        cout << "3. Cedie Santos" << endl;
        cout << "4. Dana Lorenzo\n" << endl;

        cout << "How many students will vote? ";
        cin >> num_votes;
        cout << endl;

        for (int i = 0; i < num_votes; i++) {
            cout << "Voter #" << i + 1 << ", enter your vote (1-4): " ;
            cin >> candidate_num;

            if (candidate_num >= 1 && candidate_num <= 4) {
                votes[candidate_num - 1]++;
            } else {
                cout << "Invalid Vote! Skipped." << endl;
            }
        }

        cout << "\n------ VOTING Results ------" << endl;
        cout << "Alice Cruz       :" << votes[0] <<  " votes(s)" << endl;
        cout << "Bryan Dela Cruz  :" << votes[1] << " votes(s)" << endl;
        cout << "Cedie Santos     :" << votes[2] <<  " votes(s)" << endl;
        cout << "Dana Lorenzo     :" << votes[3] <<  " votes(s)" << endl;

        if (votes[0] > votes[1] && votes[0] > votes[2] && votes[0] > votes[3]) {
            winner = "Alice Cruz";
            loop = 0;
        } else if (votes[1] > votes[0] && votes[1] > votes[2] && votes[1] > votes[3]) {
            winner = "Bryan Dela Cruz";
            loop = 0;
        } else if (votes[2] > votes[0] && votes[2] > votes[1] && votes[2] > votes[3]) {
            winner = "Cedie Santos";
            loop = 0;
        } else if (votes[3] > votes[0] && votes[3] > votes[1] && votes[3] > votes[2]) {
            winner = "Dana Lorenzo";
            loop = 0;
        } else {
            cout << "\nIt's a tie! Re-vote required.\n" << endl;
            loop = 1;

            for (int a = 0; a < 4; a++) {
                votes[a] -= votes[a];
            }

        }
        if (loop == 0) {
            cout << "\nWinner: " << winner << endl;
        }

    } while (loop == 1);


    return 0;
}