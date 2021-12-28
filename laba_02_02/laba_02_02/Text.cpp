#include "Text.h"
#define D " ,:;"
#define E ".!?"
Text::Text()
{
	string path = "Text.txt", line = "", str = "", word = "";
	ifstream f;

	f.open(path);
	if (f.is_open()) {
		cout << "Ввод слова для поиска: ";
		cin >> word;
		cout << "\n";
		while (getline(f, line, '\0'))
		{
			//std::cout << line;
			str = search(line, word);


		}
		f.close();
		if (str.length() == 0)
			cout << "Не найдено:" << word << "\n";
		std::cout << str;
	}
	else
		cout << "Ошибка при попытке открыть файл\n";

}

string Text::search(string line, string word)
{
	bool flag = false;
	int i = 0, pos1 = 0, pos2 = 0, pos1w = 0, pos2w = 0;
	char c, prev;
	string wrd = "", out = "";
	while (line[i] != '\0') {
		c = line[i];
		if (c == D[0] || c == D[1] || c == D[2] || c == D[3]
			|| c == D[4] || c == E[0]
			|| c == E[1] || c == E[2]) {
			prev = line[i - 1];
			//найден разделитель


			if (prev != D[0] && prev != D[1] && prev != D[2] && prev != D[3]
				&& prev != D[4]
				&& prev != E[0] && prev != E[1] && prev != E[2]) {
				//предыдущий символ не разделитель


				if (c == D[0] || c == D[1] || c == D[2] || c == D[3]
					|| c == D[4] || c == E[0] || c == E[1] || c == E[2]) {
					pos2w = i;
					wrd = line.substr(pos1w, pos2w - pos1w);
					if (word == wrd)
						flag = true;

				}
				if (c == E[0] || c == E[1] || c == E[2]) {
					pos2 = i;
					if (flag) {
						out += line.substr(pos1, pos2 - pos1 + 1) + "\n";
						flag = false;
					}
				}

			}

		}
		else {

			if (i != 0) {
				if (line[i - 1] == D[0] || line[i - 1] == D[1] || line[i - 1] == D[2] || line[i - 1] == D[3]
					|| line[i - 1] == D[4] || line[i - 1] == E[0] || line[i - 1] == E[1] || line[i - 1] == E[2]) {
					pos2w = i;
					pos1w = i;
				}
				if (i >= 2) {
					if ((line[i - 1] == D[0] || line[i - 1] == D[1] || line[i - 1] == D[2] || line[i - 1] == D[3]
						|| line[i - 1] == D[4] || line[i - 1] == '\n' || line[i - 1] == E[0] || line[i - 1] == E[1] || line[i - 1] == E[2]) && (line[i - 2] == E[0]
							|| line[i - 2] == E[1] || line[i - 2] == E[2])) {

						pos2 = i;
						pos1 = i;
						pos2w = i;
						pos1w = i;

					}
				}
			}

		}
		i++;
	}
	return string(out);
}
