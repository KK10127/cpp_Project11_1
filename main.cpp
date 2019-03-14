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
 * its English description.err
 *
 * ALGORITHM FOR FUNCTION toEnglish():
 * 1. Get the number into string format using to_string()
 * 2. Initialize a variable for the answer.
 * 3. IF the number is larger than 2 digits, perform the following
 * 4.     DECLARE and store 'lastTwoDigits' which stores the function result of
 *          'getLastTwoDigits(int number).'
 *      IF lastTwoDigits is less than 20 and NON-ZERO
 * 5.         SET the answer to the appropriate less than twenty number based on its position
 *              in the 'lessThanTwenty' array.
 *      ELSE perform the following
 * 6.         DECLARE integer 'tensPlace' which will store the lastTwoDigits divided by 10 to obtain the tens place
 *              value in the number.
 * 7.         DELARE string 'onesPlace' which will store the last digit in the number as a string.
 * 8.         IF onesPlace is "zero" set it to. an empty string.
 *              - This eliminates answers like "twenty zero " and "sixty zero"
 * 9.         CREATE a switch statement on the tens place with the following cases:
 *              CASE 2: SET the answer to the correct string in 'tensOver20' PLUS the onesPlace string.
 *              CASE 3: SET the answer to the correct string in 'tensOver20' PLUS the onesPlace string.
 *              CASE 4: SET the answer to the correct string in 'tensOver20' PLUS the onesPlace string.
 *              CASE 5: SET the answer to the correct string in 'tensOver20' PLUS the onesPlace string.
 *              CASE 6: SET the answer to the correct string in 'tensOver20' PLUS the onesPlace string.
 *              CASE 7: SET the answer to the correct string in 'tensOver20' PLUS the onesPlace string.
 *              CASE 8: SET the answer to the correct string in 'tensOver20' PLUS the onesPlace string.
 *              CASE 9: SET the answer to the correct string in 'tensOver20' PLUS the onesPlace string.
 *              CASE 10: SAME as case 2. Eliminates the possibility of "One hundred zero" and "two hundred zero".
 * 10.         IF the number divided by 100 is greater than zero. Add the lessThan20 position of the hundred's place
 *              to the string "hundred" and attach to the answer string. ONLY do this if there is a valid
 *              hundreths place to begin with.
 * 11.         PERFORM THE SAME TASK AS ABOVE FOR THE THOUSANTHS PLACE
 *     ELSE the number is 1 or two digits long. perform the following
 * 12.     SET the answer to the less than twenty number based on its position in the array 'lessThan20'
 * 13. RETURN the answer.
 *
 *
 * ALGORITHM FOR STATIC FUNCTION getLastTwoDigits(int number)
 * 1. RETURN the number modulo 100.
 * 2. It is asserted that by the time this function is called, the number
 * is more than 2 digits long.
 *
 * ALGORITHM FOR main():
 * 1. Initialize static members outside of main.
 * 2. Create a numbers object and initialize to zero.
 * 3. Prompt the user for a number.
 *    WHILE the number is between 0-9999
 * 4.   OUTPUT the toEnglish() method results. Indicate an
 *          invalid choice if one is detected.
 * 5. Exit the loop if a -1 is detected.
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
    static string onesPlace; //

public :
    // constructor
    explicit Numbers(int number) { this->number = number; }

    // mutator function
    void setNumber(int number) { this->number = number; }

    // accessor function
    int getNumber() { return number; }

    // method to find the english translation
    string toEnglish() {

        // get the number as a string
        string numberAsString = to_string(getNumber());

        // get the answer
        string answer;

        // get the last two digits and veryfy they are less than twenty
        if (numberAsString.length() >= 2) {

            // find the last two digits of the number using a helper static method
            int lastTwoDigits = getLastTwoDigits(getNumber());

            // If the last two digits are less than 20 and NONZERO
            if (lastTwoDigits < 20 && (lastTwoDigits != 0))
            {
                // set the answer to the appropriate less than twenty digit
                answer = lessThan20[lastTwoDigits];
            } else {
                // assert: the last two digits are 20-99
                int tensPlace = lastTwoDigits / 10;
                string onesPlace = lessThan20[(lastTwoDigits % 10)];

                // verify the ones place is not zero. If it is. Do not append a zero.
                // this avoids cases like "twenty zero."
                if (onesPlace == "zero")
                    onesPlace = "";

                // Switch statement on the 10's place
                switch (tensPlace) {
                    case 10:
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
            // now add the hundreds tag
            if (number / 100 > 0) {
                // add "X hundred " to the answer

                int condition = (number % 1000) / 100;
                if (condition != 0) {
                    answer = lessThan20[condition] + hundred + answer;
                }
            }

            // now add the thousands tag
            if (number / 1000 > 0) {
                // add "X thousand
                answer = lessThan20[number / 1000] + thousand + answer;
            }

        } else { // number is only one digit
            answer = lessThan20[number];
        }
        return answer;
    }

    // Static method that returns the last two digits of an integer number.
    // For use with numbers 3 or 4 digits long.
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


// main method
int main() {
    // initialize static members
    cout << "Welcome to the demo of project 11.1!\n" << endl;


    // create a numbers object
    Numbers object = Numbers(0);

    // create a choice variable
    int choice;
    cout << "Enter number: ";
    cin >> choice;
    // allow the user to enter as many values as possible.
    do {

        object.setNumber(choice);

        if (choice >=0 && choice <= 9999) {
            cout << object.toEnglish() << "\n\n";
        } else {
            cout << "Invalid choice! 0-9999 only!" << "\n\n";
        }

        cout << "Enter number: ";
        cin >> choice;
    } while (choice != -1);

    cout << "\nThis concludes the demo!\n\n";

    return 0;
}