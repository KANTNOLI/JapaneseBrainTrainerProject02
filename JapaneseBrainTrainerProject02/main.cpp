#include "logic.h"

#define MAX_NUMBER 9
#define MIN_NUMBER 1


int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");

	char restart = ' ';

	do
	{
		int count;
		int count2 = 1;

		int enter;

		cout << "Choose language / Выберите язык (1 - RUS/2 - EN)" << endl;
		char choose = _getch();

		if (choose == '1') {
			cout << output_language(5);
		}
		else {
			cout << output_language(1);
		}

		cin >> count;
		int start_time = time(NULL);
		bool chance = chance_symbol();
		while (count > 0)
		{

			int n1 = rand_init(MAX_NUMBER, MIN_NUMBER);
			int n2 = rand_init(MAX_NUMBER, MIN_NUMBER);
			int n3 = rand_init(MAX_NUMBER, MIN_NUMBER);

			while (n2 == n1) {
				n2 = rand_init(MAX_NUMBER, MIN_NUMBER);
			}

			while (n3 == n2 || n3 == n1) {
				n3 = rand_init(MAX_NUMBER, MIN_NUMBER);
			}


			cout << to_string(count2) + ": ";
			int answer = create_example(n1, n2, n3, chance);
			cin >> enter;
			if (enter != answer)
			{
				do
				{

					if (choose == '1')
					{
						cout << output_language(4) << endl << to_string(count2) + ": ";
					}
					else {
						cout << output_language(0) << endl << to_string(count2) + ": ";
					}
					create_example(n1, n2, n3, chance);
					cin >> enter;
				} while (enter != answer);
			}


			count--;
			count2++;
		}

		int stop_time = time(NULL);

		string time = output_time(stop_time - start_time);


		if (choose == '1')
		{
			cout << output_language(7) << time << endl;
		}
		else {
			cout << output_language(3) << time << endl;
		}



		if (choose == '1')
		{
			cout << output_language(6) << endl;
		}
		else {
			cout << output_language(2) << endl;
		}

		restart = _getch();

		system("cls");
	} while (restart == '1');


	



	return 0;
}