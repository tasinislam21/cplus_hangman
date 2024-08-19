#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

string get_random_word()
{
	vector<string> words;
	ifstream infile("word.txt");
	string single_word;

	while (infile >> single_word){
		words.push_back(single_word);
	}
	infile.close();
	srand(time(NULL));
	int random_pos = rand() % words.size();
	string choosen_word = words[random_pos];
	return choosen_word;
}

int main()
{
	string choosen_word = get_random_word();
    int word_size = choosen_word.length();
    cout << "Choosen words: " << choosen_word << endl;
    cout << "Number of characters: " << word_size << endl;
    for (int i = 0; i < word_size; i++) {
        cout << "_" << " ";
    }


}

