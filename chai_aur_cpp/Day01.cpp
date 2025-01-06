#include <iostream>
#include <string>
using namespace std;
// you just need to implement this function
bool containsGlitchPattern(const string& videoStream, const string& glitchPattern) {
    // your code here
    int n = videoStream.length();
    int m = glitchPattern.length();

    if (m > n) return false;

    for (int i = 0; i <= n - m; ++i) {
        bool matchFound = true;

        for (int j = 0; j < m; ++j) {
            if (videoStream[i + j] != glitchPattern[j]) {
                matchFound = false;
                break;
            }
        }
        // If we find a match, return true
        if (matchFound) {
            return true;
        }
    }
    return false;
}

int main() {
    string videoStream, glitchPattern;
    cin >> videoStream;
    cin >> glitchPattern;

    // please do not change the below code
    if (containsGlitchPattern(videoStream, glitchPattern)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}