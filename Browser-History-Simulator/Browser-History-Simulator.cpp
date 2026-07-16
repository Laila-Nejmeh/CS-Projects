#include <iostream>
#include <stack>
#include <string>
using namespace std;
// Browser history simulator using two stacks.
// backStack stores previously visited pages.
// forwardStack stores pages available after going back.
class WebNavigator {
private:
    stack<string> backStack;
    stack<string> forwardStack;
    string currentURL;

public:
    WebNavigator(const string& homepage) {
        currentURL = homepage;
        cout << "Opened: " << currentURL << endl;
    }

    void visit(const string& url) {
        backStack.push(currentURL);
        currentURL = url;
        while (!forwardStack.empty()) { forwardStack.pop(); }
        cout << "\nVisited: " << url << endl;
    }

    void back() {
        if (!backStack.empty()) {
            forwardStack.push(currentURL);
            currentURL = backStack.top();
            backStack.pop();
            cout << "\nBack to: " << currentURL << endl;
        }
        else {
            cout << "\nNO previous page available." << endl;
        }
    }

    void forward() {
        if (!forwardStack.empty()) {
            backStack.push(currentURL);
            currentURL = forwardStack.top();
            forwardStack.pop();
            cout << "\nForward to: " << currentURL << endl;
        }
        else {
            cout << "\nNo forward history available." << endl;
        }
    }

    void current() {
        cout << "\nCurrent Page: " << currentURL << endl;
    }
};

int main() {
    WebNavigator browser("google.com");
    int choice;
    string url;

    while (true) {
        cout << "\n===== Browser History =====" << endl;
        cout << "1. Visit" << endl;
        cout << "2. Back" << endl;
        cout << "3. Forward" << endl;
        cout << "4. Current Page" << endl;
        cout << "5. Exit" << endl;
        cout << "\nChoice: ";
        cin >> choice;

        if (choice == 5) {
            cout << "Goodbye!" << endl;
            break;
        }

        switch (choice) {
        case 1:
            cout << "\nEnter URL:" << endl;
            cin >> url;
            browser.visit(url);
            break;
        case 2:
            browser.back();
            break;
        case 3:
            browser.forward();
            break;
        case 4:
            browser.current();
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}