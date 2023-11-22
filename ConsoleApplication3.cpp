#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <ctime>

using namespace std;
void rules() {
    cout << "\t\t\tДобро пожаловать в игру \"Словомеска\"\n\n";
    cout << "Угадай все буквы, чтобы сложилось слово\n";
    cout << "Введи 'hint' для получения маленького намека :) .\n";
    cout << "Введи 'quit' чтобы покинуть нас :( .\n\n";
}
int main() {
    srand(time(NULL));
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const int NUM_WORDS = 5;
    int curNumWords = 0, prevcurNumWords = -1;
    int score_cur_word = 0;
    int hintPenalty = 3;
    char playAgain = 'Y';
    string passedWords[NUM_WORDS] = { "стена","стекло","собака","желания","правда" };
    string hintWords[NUM_WORDS];
    for (int i = 0; i < NUM_WORDS; i++) {
        hintWords[i] = passedWords[i];
    }
    string hint[NUM_WORDS] = { {"Они тебя окружают и защищают, по крайней мера одна она из этих сестер, что служат дому опорами.."},
    {"Сквозь нее ты смотришь, но он не пропускает холод улиц.."},
    {"Лает, кусает, в дом не пускает.."},
    {"Причина всех твоих страдании.."},
    {"В отличии от лжи, она таааак горька..."} };
    while (playAgain == 'y' || playAgain == 'Y') {
        rules();
        for (int i = 0; i < NUM_WORDS; i++) {
            for (int j = 0; j < hintWords[i].length(); j++) {
                int random = rand() % hintWords[i].length();
                swap(hintWords[i][j], hintWords[i][random]);
            }
        }
        curNumWords = rand() % 5;
        if (curNumWords == prevcurNumWords && curNumWords != 0) {
            curNumWords--;
        }
        else if (curNumWords == prevcurNumWords && curNumWords == 0) {
            curNumWords++;
        }
        prevcurNumWords = curNumWords;
        cout << "Зашифрованое слово: " << hintWords[curNumWords] << endl;
        cout << "Ваше количество попыток: " << hintPenalty << ". Ваше количество балов: " << score_cur_word << "." << endl;
        string guess;
    tryagain2:
        cout << "А твой ответ: ";
        cin >> guess;
        if (guess != passedWords[curNumWords] && guess != "quit" && guess != "hint") {
            cout << "Вы неугадали! ";
            hintPenalty--;
            cout << "Ваше количество попыток стало " << hintPenalty << endl;
            if (hintPenalty == 0) {
                cout << "Вы проиграли!!" << endl;
                cout << "Желаете начать игру заного: Y - да, N - нет!" << endl;
                cin >> playAgain;
                if (playAgain == 'N' || playAgain == 'n') {
                    cout << "Спасибо, за игру!" << endl;
                }
                else if (playAgain == 'y' || playAgain == 'Y') {
                    hintPenalty = 3;
                    score_cur_word = 0;
                    continue;
                }
                else {
                    cout << "Вы ввели не правильно символ!" << endl;
                    goto tryagain;
                }
            }
            goto tryagain2;
        }
        if (guess == "hint") {
            cout << "Ваша подсказка: " << hint[curNumWords] << endl;
            goto tryagain2;
        }
        else if (guess == passedWords[curNumWords]) {
            cout << "Ура вы угадали!" << endl;
            score_cur_word += passedWords[curNumWords].length();
            cout << "Ваше количество балов стало: " << score_cur_word << endl;
        }
    tryagain:
        cout << "Хотите сыграть ещё? Y - да, N - нет." << endl;
        cin >> playAgain;
        if (playAgain == 'N' || playAgain == 'n') {
            cout << "Спасибо, за игру!" << endl;
        }
        else if (playAgain == 'y' || playAgain == 'Y') {
            system("cls");
            continue;
        }
        else {
            cout << "Вы ввели не правильно символ!" << endl;
            goto tryagain;
        }
    }
}