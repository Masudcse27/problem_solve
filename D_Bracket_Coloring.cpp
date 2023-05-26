#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int colorBracketSequence(string s) {
    stack<char> st;
    unordered_map<char, char> colors;
    int colorCount = 0;

    for (char c : s) {
        if (c == '(') {
            if (st.empty() || colors[st.top()] != '(') {
                colorCount++;
                colors[c] = colorCount;
            } else {
                colors[c] = colors[st.top()];
                st.pop();
            }
            st.push(c);
        } else {
            if (st.empty() || colors[st.top()] != '(') {
                return -1;  // Impossible
            }
            colors[c] = colors[st.top()];
            st.pop();
        }
    }

    if (!st.empty()) {
        return -1;  // Impossible
    }

    cout << colorCount << endl;
    for (char c : s) {
        cout << colors[c] << " ";
    }
    cout << endl;

    return 0;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        colorBracketSequence(s);
    }

    return 0;
}