#include "logic.h"


string convert_to_string(int n1, int n2, int n3, bool choose) {
	string msg = "";
	if (choose){
		msg = to_string(n1) + " + " + to_string(n2) + " - " + to_string(n3) + " = ";
	}
	else {
		msg = to_string(n1) + " - " + to_string(n2) + " + " + to_string(n3) + " = ";
	}

	return msg;
}


int create_example(int n1, int n2, int n3, bool choose) {

	if (n1 < n2)
	{
		int t = n1;
		n1 = n2;
		n2 = t;
	}

	int answer = choose ? n1 + n2 - n3 : n1 - n2 + n3;

	if (answer < 0){
		int t = n2;
		n2 = n3;
		n3 = t;
	}

	answer = choose ? n1 + n2 - n3 : n1 - n2 + n3;

	cout << convert_to_string(n1, n2, n3, choose);

	return answer;
}

string output_time(int time) {
	int hour = time / 3600 % 24;
	int min = time % 3600 / 60;
	int sec = time % 60;

	string msg = to_string(hour);
	msg += (min > 9 ? ":" : ":0") + to_string(min);
	msg += (sec > 9 ? ":" : ":0") + to_string(sec);

	return msg;
}


string output_language(int key) {
	string msg = "";

	switch (key) {
	case 0: msg += "You made a mistake!"; break;
	case 1: msg += "Enter the number of examples: "; break;
	case 2: msg += "Do you want to repeat? (Y - Yes / N - No): "; break;
	case 3: msg += "You solved all the examples for: "; break;
	case 4: msg += "Ты допустил ошибку!"; break;
	case 5: msg += "Введите кол-во примеров: "; break;
	case 6: msg += "Вы хотите повторить? (Y - Да / N - Нет): "; break;
	case 7: msg += "Вы решили все примеры за: "; break;
	}


	return msg;
}