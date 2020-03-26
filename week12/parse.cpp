#include <iostream>    // for CIN, COUT
#include <fstream>     // for reading a file
#include <string>      // for STRING
#include <vector>      // for VECTOR


using namespace std;

struct message {
    string control;
    string user;
    string date;
    string text;
};

vector<message> cases;

int main() {
    ifstream messages ("messages.txt");
    string line;
    if (messages.is_open())
    {
        int last;
        int pos;
        while ( getline (messages,line) )
        {
            last = 0;
            pos = 0;

            message m;
            //Control
            pos = line.find("|");        
            m.control = line.substr(last,pos);
            // cout << last << ":" << pos << " control: " << m.control << "\n";

            //User
            last = pos;
            pos = line.find("|",last+1);
            m.user = line.substr(last+1,pos-last-1);
            // cout << last << ":" << pos << "user: " << m.user << "\n";

            //Date
            last = pos;
            pos = line.find("|",last+1);
            m.date = line.substr(last+1,pos-last-1);
            // cout << last << ":" << pos << "date: " << m.date << "\n";

            //Message Text
            last = pos;
            pos = line.find("|",last+1);
            m.text = line.substr(last+1,pos-last-1);
            // cout << last << ":" << pos << "text: " << m.text << "\n\n\n";
            
            cases.push_back(m);        
        }
        messages.close();
    }

    for (vector<message>::iterator it = cases.begin(); it != cases.end(); it++) {
        cout << (*it).user << " " << (*it).control << "\n";
    }

    return 0;
}