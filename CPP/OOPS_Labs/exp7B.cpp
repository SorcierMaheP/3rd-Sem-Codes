#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	string str;
	int words = -2, chars = 0, lines = -2;
	cout << "Enter a string.\n";
	do
	{
		getline(cin, str);
		for (int i = 0; i <= str.length(); i++)
		{
			if (str[i] == '.' || str[i] == '\0')
				lines++;
			if (str[i] == ' ' || str[i] == '\0' || str[i] == '.')
				words++;
			if (str[i] != ' ' && str[i] != '.' && str[i] != '\0')
				chars++;
		}
	} while (str.length());
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(20) << "Number of words" << setw(25) << "Number of characters" << setw(25) << "Number of lines" << endl;
	cout.setf(ios::right, ios::adjustfield);
	cout << setw(15) << words << setw(25) << chars << setw(20) << lines << endl;
	return 0;
}
