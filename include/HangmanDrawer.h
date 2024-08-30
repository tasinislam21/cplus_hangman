#ifndef HANGMANDRAWER_H
#define HANGMANDRAWER_H
#include <iostream>
#include <fstream>

using namespace std;

class HangmanDrawer
{
    public:
        HangmanDrawer();
        string getDrawing(int deathLevel);
    protected:

    private:
        char* picture[8] = {
R"(
  +---+
  |   |
      |
      |
      |
      |
=========
)",
R"(
  +---+
  |   |
  O   |
      |
      |
      |
=========
)",
R"(
  +---+
  |   |
  O   |
  |   |
      |
      |
=========
)",
R"(
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========
)",
R"(
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========
)",
R"(
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========
)",
R"(
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========
)"  };
};

#endif // HANGMANDRAWER_H
