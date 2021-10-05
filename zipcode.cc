
/**
 *   @file: zipcode.cc
 * @author: Brody Reynolds
 *   @date: 9/27/2021
 *  @brief: This is a zipcode to barcode program that provides barcode value with a check digit value.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

/**
 * getDigitcode - finds and returns the char value for a certain case
 * @param digit - the value to be one of the barcode cases
 * @return - barcode value based on case
 */
string getDigitcode(char digit);

/**
 * getCheckDigitValue - finds and returns the check digit value
 * @param sum - the value to be %
 * @return - returns digit value after running through (10 - sum%10)
 */
int getCheckDigitValue(int sum);

int main(int argc, char const *argv[])
{
    int sum = 0; //sum starts at 0 and resets
    string zipcode; //Inserted zipcode from user
    string result; // Total barcode value
    char answer = 'y', data; // Answer will stay as y = true. Data is the found char value
    bool T = true;

    while (answer == 'y') // Loop will start while answer equals 'y'
    {
        cout << "Enter a zip code: ";
        cin >> zipcode;

        while (zipcode.length() == 5) // Loop will start when 5 characters are inputed
        {
            result = ""; // Restarts result to ""
            sum = 0; // Restarts sum to 0
            for (size_t i = 0; i < zipcode.length(); i++) // This loop will find barcode value and will return it as a char for getDigitCode
            {
                if (getDigitcode(zipcode.at(i)) == "ERROR") // When input is not a number, break.
                {
                    cout << "Error: Code is invalid"<<endl;
                    T = false;
                    break;
                }

                string totalBarcode = getDigitcode(zipcode.at(i));
                data = zipcode.at(i) - '0';
                sum = sum + data;
                result += totalBarcode + ' ';
            }

            if (T == true) // bool value 'T' for true
            {
                int CheckDigitInt = getCheckDigitValue(sum);
                char CheckDigit = '0' + CheckDigitInt;

                result = result + getDigitcode(CheckDigit);

                cout << "Code: | " << result << " |" << endl;

                cout << "More codes (y/n)? ";
                cin >> answer;

                if (answer == 'n') // The for loop will break for when 'n' is inputed
                {
                    break;
                }
                cout << "Enter a zip code: ";
                cin >> zipcode;
            }

            else
            {
                break;
            }
        }

        if (zipcode.length() != 5) // If the zipcode value does not equal 5
        {
            cout << "Error: zip code must be 5 digits" << endl;
        }

        if (answer == 'y') // If answer char value is 'y' ask if user wants to insert more codes
        {
            cout << "More codes (y/n)? ";
            cin >> answer;
            T = true; //Resetting conditional bool
        }
    }
}

string getDigitcode(char digit)
{

    switch (digit)
    {
    case '1':
        return ":::||";

    case '2':
        return "::|:|";

    case '3':
        return "::||:";

    case '4':
        return ":|::|";

    case '5':
        return ":|:|:";

    case '6':
        return ":||::";
        
    case '7':
        return "|:::|";

    case '8':
        return "|::|:";

    case '9':
        return "|:|::";

    case '0':
        return "||:::";

    default:
        return "ERROR";
    }
}

int getCheckDigitValue(int sum)
{
    int digit = (10 - (sum % 10));
    if (digit == 10)
    {
        return (0);
    }
    else
    {
        return digit;
    }
    
}
