#include "../include/control.hpp"

double Control::CheckNumber(char * c)
{
    auto i(0);
    string str = c;
    while(str.size() == 0 or str[i] != '\0')
    {
        if (!(c[i] == 46 or (int(c[i]) > 47 and int(c[i]) < 58))){
            i = 0;
            cout << "These 'chars' are out of range for numeric symbols. Try again!" << endl;
            cin.clear();
            cin.getline(c, 300);
            str = c;
        }
        i++;
    }
    return stoi(c);
};

char * Control::CharInput()
{
	char * aux = new char;
	cin.clear();
	cin.getline(aux, 1);
	return aux;
};

string Control::StringInput()
{
	char * aux = new char;
	cin.clear();
	cin.getline(aux, 20);
	string str = static_cast<string>(aux);
	delete[] aux;
	return str;
};

int Control::IntInput()
{
	char * aux = new char;
	cin.clear();
	cin.getline(aux, 20);
	int i =  CheckNumber(aux);
	delete[] aux;
	return i;
};

double Control::DoubleInput()
{
	char * aux = new char;
	cin.clear();
	cin.getline(aux, 20);
	int i =  CheckNumber(aux);
	delete[] aux;
	return i;
};
