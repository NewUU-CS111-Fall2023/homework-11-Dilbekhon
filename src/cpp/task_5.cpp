/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <unordered_map>

using namespace std;

string decodeMessage(const string& key, const string& message) {
    unordered_map<char, char> substitutionTable;
    int index = 0;

    for (char ch : key) {
        if (isalpha(ch) && substitutionTable.find(tolower(ch)) == substitutionTable.end()) {
            substitutionTable[tolower(ch)] = 'a' + index++;
        }
    }

    string decodedMessage;

    for (char ch : message) {
        if (isalpha(ch)) {
            char original = islower(ch) ? ch : tolower(ch);
            decodedMessage += substitutionTable[original];
        } else if (ch == ' ') {
            decodedMessage += ' ';
        }
    }

    return decodedMessage;
}

int main() {

    string key1 = "the quick brown fox jumps over the lazy dog";
    string message1 = "vkbs bs t suepuv";

    string key2 = "eljuxhpwnyrdgtqkviszcfmabo";
    string message2 = "zwx hnfx lqantp mnoeius ycgk vcnjrdb";

    string result1 = decodeMessage(key1, message1);
    string result2 = decodeMessage(key2, message2);

    cout << result1 << endl;  // Should print "this is a secret"
    cout << result2 << endl;  // Should print "the five boxing wizards jump quickly"

    return 0;
}
