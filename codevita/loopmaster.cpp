#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// Struct to represent a loop
struct LoopState {
    int totalIterations; // Total number of iterations the loop should run
    int currentIteration; // Current iteration count
    bool isActive; // Whether the loop is active
};

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Ignore the newline character

    vector<string> commands(N);
    for (int i = 0; i < N; i++) {
        getline(cin, commands[i]);
    }

    stack<LoopState> loopStack; // Stack to handle nested loops

    for (size_t i = 0; i < commands.size(); ++i) {
        string command = commands[i];

        if (command.find("for") == 0) {
            // Parse the number of iterations for the loop
            int loopCount = stoi(command.substr(4, command.find("times") - 4));
            loopStack.push({loopCount, 0, true}); // Initialize a new loop
        } else if (command.find("do") == 0) {
            // Start of a loop body (no action needed)
            continue;
        } else if (command.find("done") == 0) {
            // End of the current loop
            if (!loopStack.empty()) {
                auto& currentLoop = loopStack.top();
                currentLoop.currentIteration++; // Move to the next iteration

                if (currentLoop.currentIteration >= currentLoop.totalIterations) {
                    // If loop completes, pop it from the stack
                    loopStack.pop();
                } else {
                    // Otherwise, repeat the loop body
                    i -= 1; // Go back to the start of the loop body
                }
            }
        } else if (command.find("break") == 0) {
            if (!loopStack.empty()) {
                int breakAt = stoi(command.substr(6));
                auto& currentLoop = loopStack.top();

                if (currentLoop.currentIteration + 1 == breakAt) {
                    loopStack.pop(); // Exit the current loop
                }
            }
        } else if (command.find("continue") == 0) {
            if (!loopStack.empty()) {
                int continueAt = stoi(command.substr(8));
                auto& currentLoop = loopStack.top();

                if (currentLoop.currentIteration + 1 == continueAt) {
                    i -= 1; // Skip to the next iteration
                    currentLoop.currentIteration++;
                    continue;
                }
            }
        } else if (command.find("print") == 0) {
            // Handle print command
            string message = command.substr(6, command.length() - 7); // Extract the message
            cout << message << endl;
        }
    }

    return 0;
}
