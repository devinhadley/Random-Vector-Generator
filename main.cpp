#include <iostream>
#include <vector>

using namespace std;


// Render a progress bar.
void renderProgressBar(float progress, int length) {
    int barWidth = 70;

    std::cout << "[";
    int pos = barWidth * progress;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) std::cout << "=";
        else if (i == pos) std::cout << ">";
        else std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << " %\r";
    std::cout.flush();

    progress += 1 / length;

}

// Generates random vector of length and within bounds of maximum value.
vector<int> generateRandomVector(int length, int maximum) {

    vector<int> values;

    for (int i = 0; i < length; i++) {

        renderProgressBar(i / (float) (length), length);

        int randomValue = rand() % maximum + 1;

        values.push_back(randomValue);

    }
    return values;

}


// Print the contents of the supplied vector using its reference.
void printVector(vector<int> &values) {

    if (values.empty()) {
        cout << "[]" << endl;
        return;
    }

    string formattedValues = "[";
    for (int i = 0; i < values.size() - 1; i++) {

        formattedValues += to_string(values.at(i)) + ", ";

    }
    formattedValues += to_string(values.at(values.size() - 1)) + "]";
    cout << formattedValues << endl;
}


int main() {
    // << Stream out.
    // >> Stream in.
    int length;
    int maximum;


    // Get length of vector.
    cout << "Please enter length of random vector." << endl;
    cin >> length;

    // Get maximum of vector values.
    cout << "Please enter the maximum value of random vector." << endl;
    cin >> maximum;


    // Ensure vector length is applicable.
    if (abs(length) == length || length == 0) {
        cout << "Creating random vector of length: " + to_string(length) << endl;
        vector<int> values = generateRandomVector(length, maximum);
        printVector(values);
    } else {
        cout << "Length can not be negative number or 0." << endl;
    }

    return 0;
}

