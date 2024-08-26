#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

string choosen_word;
int word_size;

void get_random_word(){
	vector<string> words;
	ifstream infile("word.txt");
	string single_word;

	while (infile >> single_word){
		words.push_back(single_word);
	}
	infile.close();
	srand(time(NULL));
	int random_pos = rand() % words.size();
	choosen_word = words[random_pos];
}

void process_input(vector<char> *input_history){
    bool valid = false;
    string input_string;
    char input_char;
    while (!valid){
        cout << "Guess a letter: "; // Type a number and press enter
        cin >> input_string;
        if (input_string.length() > 1){
            cout << "Please only enter 1 character." << endl;
            continue;
        }
        input_char = input_string.c_str()[0];
        int cnt = count((*input_history).begin(), (*input_history).end(), input_char);
        if (cnt > 0){
            cout << "You have already typed that in." << endl;
        }
        else {
            (*input_history).push_back(input_char);
            valid = true;
        }
    }
}

void print_dashes(){
    for (int i = 0; i < word_size; i++) {
        cout << "_" << " ";
    }
    cout << "\n";
}

void print_partial_words(vector<char> word, vector<char> correct){
    char current_letter;
    for (int i = 0; i < word.size(); i++) {
        current_letter = word[i];
        auto it = find(correct.begin(), correct.end(), current_letter);
        if (it != correct.end()){
            cout << current_letter << " ";
        }
        else {
            cout << "_" << " ";
        }
    }
    cout << "\n";
}

bool game_process() {
    vector<char> word_vector(choosen_word.begin(), choosen_word.end());
    vector<char> unique_chars = word_vector;
    sort(unique_chars.begin(), unique_chars.end());
    vector<char>::iterator it;
    it = unique(unique_chars.begin(), unique_chars.end());
    unique_chars.resize(distance(unique_chars.begin(),it));
    vector<char> already_inputted;
    vector<char> correctly_guessed;
    int i = 0;
    while (i != 6){
        if (i > 0){
            cout << "So far, you have inputted: " << " ";
            for (auto element : already_inputted) {
                cout << element << " ";
            }
            cout << "\n";
        }
        process_input(&already_inputted);
        char choosen_char = already_inputted.back();
        int cnt = count(word_vector.begin(), word_vector.end(), choosen_char);
        if (cnt > 0){
            cout << "You have guessed the right letter!" << endl;
            correctly_guessed.push_back(choosen_char);
            print_partial_words(word_vector, correctly_guessed);
            if (unique_chars.size() == correctly_guessed.size()){
                return true;
            }
        }
        else {
            cout << "That's incorrect." << endl;
            i++;
        }
    }
    return false;
}

int main(){
	get_random_word();
    word_size = choosen_word.length();
    cout << "Choosen words: " << choosen_word << endl;
    cout << "Number of characters: " << word_size << endl;
    print_dashes();
    bool hasWon = game_process();
    if (hasWon){
        cout << "You won!" << endl;

    }
    else {
        cout << "You lose!" << endl;
        cout << "The correct word was " << choosen_word << endl;
    }
    return 0;
}
