#include <iostream>
#include <string>
using namespace std;
/*
 * Design a class Numbers that can be used to translate whole dollar amounts in
 * the range 0 through 9999 into an english description of the number. For example,
 * the number 713 would be translated into the string "seven hundred thirteen" and
 * 8203 would be translated into eight thousand two hundred three.
 *
 * The class should have a single integer member variable.
 *
 * int number;
 *
 * and a collection of static string members that specify how to translate key dollar
 * amounts into the desired format. For example, you might use static strings such
 * as
 *
 * string lessThan20[ ] =
 *  { "zero", "one", "...", "eighteen", "nineteen" };
 * string hundred = "hundred";
 * string thousand = "thousand";
 *
 * The class should have a constructor that accepts a non-negative integer and uses it
 * to initialize the Numbers object. It should have a member function print() that prints
 * the English description of the Numbers object. Demonstrate the class by writing a main
 * program that asks the user to enter a number in the proper range and then prints out
 * its English description.
 *
 * @author Jay Montoya
 * @version Chapter 11 Project 1
 *
 */
class Numbers {
private :
    int number; // the decimal number
    static string lessThan20[]; // static list of string words for numbers less than 20
    static string tensOver20[]; // static list of tens over 20
    static string hundred; //  statis string of value "hundred"
    static string thousand; // static string of value "thousand"
    static string onesPlace;

public :
    explicit Numbers(int number) { this->number = number; }
    void setNumber(int number) { this->number = number; }
    int getNumber() { return number; }
    string toEnglish() {
        // get the number as a string
        string numberAsString = to_string(getNumber());
        string answer;
        // get the last two digits and veryfy they are less than twenty
        if (numberAsString.length() >= 2) {

            // take care of the last two digits
            int lastTwoDigits = getLastTwoDigits(getNumber());
            if (lastTwoDigits < 20 && (lastTwoDigits != 0))
            {
                answer = lessThan20[lastTwoDigits];
            } else {
                // assert: the last two digits are 20-99

                int tensPlace = lastTwoDigits / 10;
                string onesPlace = lessThan20[(lastTwoDigits % 10)];

                if (onesPlace == "zero")
                    onesPlace = "";

                switch (tensPlace) {
                    case 10:
                        // SPEAICAL CASE
                        answer = tensOver20[0] + onesPlace;
                        break;
                    case 2:
                        answer = tensOver20[0] + onesPlace;
                        break;
                    case 3:
                        answer = tensOver20[1] + onesPlace;
                        break;
                    case 4:
                        answer = tensOver20[2] + onesPlace;
                        break;
                    case 5:
                        answer = tensOver20[3] + onesPlace;
                        break;
                    case 6:
                        answer = tensOver20[4] + onesPlace;
                        break;
                    case 7:
                        answer = tensOver20[5] + onesPlace;
                        break;
                    case 8:
                        answer = tensOver20[6] + onesPlace;
                        break;
                    case 9:
                        answer = tensOver20[7] + onesPlace;
                        break;

                }
            }
            // now add the hundreds
            if (number / 100 > 0) {
                // add "X hundred " to the answer

                int condition = (number % 1000) / 100;
                if (condition != 0) {
                    answer = lessThan20[condition] + hundred + answer;
                }
            }

            // now add the thousands
            if (number / 1000 > 0) {
                // add "X thousand
                answer = lessThan20[number / 1000] + thousand + answer;
            }

        } else { // number is only one digit
            answer = lessThan20[number];
        }
        return answer;
    }

    static int getLastTwoDigits(int number) {
        return number % 100;
    }


};

// definition of static constants
string Numbers::lessThan20[] = {"zero", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten", "eleven",
                                "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighten",
                                "nineteen"};
string Numbers::tensOver20[] = {"twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
string Numbers::hundred = "hundred ";
string Numbers::thousand = "thousand ";



int main() {
    // initialize static members
    cout << "welcome to the demo" << endl;
    cout << "creating object Numbers" << endl;

    // create a numbers object
    Numbers object = Numbers(0);

    int choice;
    cout << "Enter number: ";
    cin >> choice;
    do {

        object.setNumber(choice);
        cout << object.toEnglish() << "\n\n";


        cout << "Enter number: ";
        cin >> choice;
    } while (choice != -1);

    return 0;
}