#include <iostream>
#include "Check.h"

using namespace std;

int main()
{
	Check obj("2 + [(3 * 6)];");
	obj.Output();
	cout << endl;
	obj.Test();
}