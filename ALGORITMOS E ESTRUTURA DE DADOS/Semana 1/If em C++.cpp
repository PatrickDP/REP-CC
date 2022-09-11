#include <iostream>

using namespace std;

int main()
{
	unsigned grade;

	cin >> grade;
	string status = (grade >= 60) ? "Passou!" : "Nao passou!"; // if & else em C++
	cout << status << endl;
	return 0;
}

/*
  ### EM C ###
if (grade >= 60)
{
	status = "Passou!";
}
else
{
	status = "Nao passou!";
}
cout << status << endl;
*/