#include <iostream>
using namespace std;

class Check
{
private:
	char* str;
public:
	Check();
	Check(const char* str);
	Check(Check& obj);
	void Test();
	void Output();
	void Input();
	const char* GetStr();
	void SetStr(const char* str);
	~Check();
};

Check::Check()
{
	this->str = nullptr;
}

Check::Check(const char* str)
{
	if (this->str != nullptr)
	{
		delete[]this->str;
	}
	this->str = new char[strlen(str) + 1];
	strcpy_s(this->str, strlen(str) + 1, str);
}

Check::Check(Check& obj)
{
	delete[]this->str;
	this->str = nullptr;
	this->str = new char[strlen(obj.str) + 1];
	strcpy_s(this->str, strlen(obj.str) + 1, obj.str);
}

void Check::Test()
{
	char test[11] = { '(',')','+' ,'-','*','/',';','{','}','[',']' };
	int counter[6]{ 0 };
	for (int i = 0; i < strlen(this->str) + 1; i++)
	{
		if (this->str[i] == test[0])
		{
			counter[0] += 1;
		}
		if (this->str[i] == test[1])
		{
			counter[1] += 1;
		}
		if (this->str[i] == test[10])
		{
			counter[2] += 1;
		}
		if (this->str[i] == test[9])
		{
			counter[3] += 1;
		}
		if (this->str[i] == test[8])
		{
			counter[4] += 1;
		}
		if (this->str[i] == test[7])
		{
			counter[5] += 1;
		}
	}
	if (counter[0] != counter[1] || counter[2] != counter[3] || counter[4] != counter[5])
	{
		cout << "\nError\n";
		return;
	}
	for (int i = 0; i < strlen(this->str) + 1; i++)
	{
		for (int j = 0; j < strlen(this->str) + 1; j++)
		{
			if (this->str[i] == test[0] && this->str[i] == test[1])
			{
				break;
			}
			if (this->str[i] == test[0] && this->str[j] == test[10] || this->str[i] == test[0] && this->str[i] == test[8])
			{
				cout << "\nError\n";
				return;
			}
		}
	}
	if (this->str[strlen(this->str) - 1] != test[6])
	{
		cout << "\nError\n";
		return;
	}
	if (this->str[0] == test[1] || this->str[0] == test[2] || this->str[0] == test[3] || this->str[0] == test[4] ||
		this->str[0] == test[5] || this->str[0] == test[6] || this->str[0] == test[8] || this->str[0] == test[9])
	{
		return;
	}
	for (int i = 0; i < strlen(this->str) - 1; i++)
	{
		if (this->str[i] == test[6])
		{
			return;
		}
	}
	for (int i = 0; i < strlen(this->str); i++)
	{
		if (this->str[i] == test[0])
		{
			for (int j = i + 1; j < strlen(this->str); j++)
			{
				if (this->str[j] == test[1])
				{
					break;
				}
				else if (j == strlen(this->str) - 1 && this->str[j] != test[1])
				{
					for (int j = 0; j <= i; j++)
					{
						cout << this->str[j];
					}
					cout << "<-";
					cout << endl;
					return;
				}
			}
		}
		else if (this->str[i] == test[7])
		{
			for (int j = i + 1; j < strlen(this->str); j++)
			{
				if (this->str[j] == test[8])
				{
					break;
				}
				else if (j == strlen(this->str) - 1 && this->str[j] != test[8])
				{
					for (int j = 0; j <= i; j++)
					{
						cout << this->str[j];
					}
					cout << "<-";
					cout << endl;
					return;
				}
			}
		}
		else if (this->str[i] == test[9])
		{
			for (int j = i + 1; j < strlen(this->str); j++)
			{
				if (this->str[j] == test[10])
				{
					break;
				}
				else if (j == strlen(this->str) - 1 && this->str[j] != test[10])
				{
					for (int j = 0; j <= i; j++)
					{
						cout << this->str[j];
					}
					cout << "<-";
					cout << endl;
					return;
				}
			}
		}
		else if (this->str[i] == test[10])
		{
			for (int j = 0; j < i; j++)
			{
				if (this->str[j] == test[9])
				{
					break;
				}
				else if (j == i - 1 && this->str[j] != test[9])
				{
					for (int j = 0; j <= i; j++)
					{
						cout << this->str[j];
					}
					cout << "<-";
					cout << endl;
					return;
				}
			}
		}
		else if (this->str[i] == test[8])
		{
			for (int j = 0; j < i; j++)
			{
				if (this->str[j] == test[7])
				{
					break;
				}
				else if (j == i - 1 && this->str[j] != test[9])
				{
					for (int j = 0; j <= i; j++)
					{
						cout << this->str[j];
					}
					cout << "<-";
					cout << endl;
					return;
				}
			}
		}
		else if (this->str[i] == test[1])
		{
			for (int j = 0; j < i; j++)
			{
				if (this->str[j] == test[0])
				{
					break;
				}
				else if (j == i - 1 && this->str[j] != test[9])
				{
					for (int j = 0; j <= i; j++)
					{
						cout << this->str[j];
					}
					cout << "<-";
					cout << endl;
					return;
				}
			}
		}
	}
	return;
}

inline void Check::Output()
{
	cout << this->str;
}

inline void Check::Input()
{
	this->str = new char[20];
	cout << "\nEnter string: ";
	cin.getline(this->str, 19);
}

inline const char* Check::GetStr()
{
	return this->str;
}

inline void Check::SetStr(const char* str)
{
	delete[]this->str;
	this->str = nullptr;
	this->str = new char[strlen(str) + 1];
	strcpy_s(this->str, strlen(str) + 1, str);
}

inline Check::~Check()
{
	delete[]this->str;
	this->str = nullptr;
}
