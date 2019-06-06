#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

struct Internet
{
	string name;
	float month;
	int monthsTotal;
	int nextmonths;

};
	void Next(Internet* internet, int k)
	{
		for (size_t i = 0; i < k; i++)
		{
			internet[i].nextmonths = internet[i].monthsTotal - 1;
		}
	}


	void Input(Internet* internet, int k)
	{
		  for (size_t i = 0; i < k; i++)
		  {
			  cout << "Введите ФИО\n";
			  cin >> internet[i].name;
			  int months;
			  cout << "Введите количество месяцев:\n";
			  cin >> months;
			  if (months >= 13 || months == 0)
			  {
				  cout << "Введите месяц от 1 до 12:\n";
				  cin >> internet[i].monthsTotal;
			  }
			  else
			  {
				  internet[i].monthsTotal = months;
			  }
			  cout << "Введите стоимость оплаты:\n";
			  cin >> internet[i].month;
			  cout << "Введите на месяц перед оплаты за услуги:";
			  cin >> internet[i].nextmonths;

			  system("cls");
		  }

	}

	void Check(Internet* internet, int k)
	{
		for (size_t i = 0; i < k; i++)
		{
			if (internet[i].nextmonths > 3)
			{
				internet[i].month -= (internet[i].month / 100) * 7;
			}
		}
	}

	void Output(Internet* internet, int k, ofstream &out)
	{
		for (int i = 0; i < k; i++)
		{
			out << internet[i].name << "\n";
			out << internet[i].month << "\n";
			out << internet[i].monthsTotal << "\n";
			out << internet[i].nextmonths << "\n";
			out << "\n";
		}
	}

	/*void readFile(const char* path)
	{
			ifstream stream(path, ios::binary);
			int nameLength;
			stream.read((char*)& nameLength, sizeof(int));
			char* buffer = new char[nameLength];
			stream.read(buffer, nameLength);
		    name = buffer;
			delete[]buffer;
			stream.read((char*)& month, sizeof(float));
			stream.read((char*)& monthsTotal, sizeof(int));
			stream.read((char*)& nextmonths, sizeof(int));
			stream.close();
	}*/

	void Print(Internet* internet, int k)
	{
		for (size_t i = 0; i < k; i++)
		{
			cout << endl << "ФИО: " << internet[i].name << endl;
			cout << "Cтоимость оплаты: " << internet[i].month << endl;
			cout << "Количество месяцев: " << internet[i].monthsTotal << endl;
			cout << "Количество месяцев на перед оплаты за услуги:" << internet[i].nextmonths << endl;
		}
	}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int k = 0, selection = 0;
	cout << "Введите количество пользователей" << endl;
	cin >> k;
	ofstream out;
	Internet* internet = new Internet[k];

	out.open("6lab.txt", ios::binary);
	Input(internet, k);

	if (!out.is_open())
		cout << "Error!" << endl;
	else
	{
		Output(internet, k, out);
		system("cls");
		cout << "Файл создан и записан" << endl;
		Print(internet, k);
	link:
		cout << "You want to increase grants for every student who doesn’t have triples? (1 - Yes or 2 - Exit)" << endl;
		cin >> selection;
		if (selection == 1)
		{
			Check(internet, k);
			system("cls");
			cout << endl << "Grant increased!" << endl;
			Output(internet, k, out);
			system("cls");
			cout << "Information rewtited" << endl;
			Print(internet, k);
		}
		else if (selection == 2)
		{
			exit(0);
		}
		else
			cout << "Error! Wrong input" << endl;
		goto link;
	}

	out.close();

	/*internet.name = "Владимир Владимирович";
	internet.month = (rand() % 111) + 90;
	internet.monthsTotal = (rand() % 6) + 1;
	internet.Next();

	cout << "Writing to file this info:\n\n";
	internet.Print();

	internet.Output(PATH);

	Internet fromFile;

	fromFile.readFile(PATH);

	if (fromFile.nextmonths > 3)
	{
		fromFile.month -= (fromFile.month / 100) * 7;

		fromFile.Output(PATH);

		fromFile.readFile(PATH);
	}

	cout << "\nInfo from file (if next months paid > 3, subtract 7% from cost):\n\n";
	fromFile.Print();*/
	delete[] internet;
	system("pause");
	return 0;

}