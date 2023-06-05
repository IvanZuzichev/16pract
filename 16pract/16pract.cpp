#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "RU");

    ifstream file("C:\\Users\\СВОЙ ПУТЬ"); // СВОЙ ПУТЬ К ФАЙЛУ
    if (!file.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    string word;
    map<string, int> word_mas;

    while (file >> word)
    {
        word_mas[word]++;
    }

    vector<pair<string, int>> sorted(word_mas.begin(), word_mas.end());
    sort(sorted.begin(), sorted.end(), [](auto const& fst, auto const& sec) {
        return fst.second > sec.second;
        });

    for (auto const& word : sorted) {
        cout << word.first << " - " << word.second << "\n";
    }
    return 0;
    file.close();
}