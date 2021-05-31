#include <bits/stdc++.h>
using namespace std;

string one = "          |\n       \\  |  /\n        \\ | /\n         \\|/\n       XXXXXXX\n      X       X\n     X  O   O  X\n    X     V     X\nW   X  X     X  X\n \\   X  XXXXX  X\n  \\   X       X\n   \\   XXXXXXX\n    \\ X       X---\n     X    O    X  \\\n    X           X  \\\n     XXXXXXXXXXX    \\\n      OOOO OOOO      M\n      OOOO OOOO";

string two[] = {
  "          |",
  "       \\  |  /",
  "        \\ | /",
  "         \\|/",
  "       XXXXXXX",
  "      X       X",
  "     X  O   O  X",
  "    X     V     X",
  "W   X  X     X  X",
  " \\   X  XXXXX  X",
  "  \\   X       X",
  "   \\   XXXXXXX",
  "    \\ X       X---",
  "     X    O    X  \\",
  "    X           X  \\",
  "     XXXXXXXXXXX    \\",
  "     X         X     M",
  "    X     O     X",
  "   X      O      X",
  "  X               X",
  "   XXXXXXXXXXXXXXX",
};

string leg_segment = "OOOO OOOO";

void print_centred(const string &s, int centre) {
  string spaces(centre - s.size() / 2 - 1, ' ');
  cout << spaces << s;
}

void print_torso(int n, int centre) {
  string spaces(n*n - n + 7, ' ');
  print_centred("X" + spaces + "X", centre);
  cout << endl;

  for(int i = 0; i < n; i++) {
    spaces = string(0.5*n*n - 0.5*n + 4 + i, ' ');
    print_centred("X" + spaces + "O" + spaces + "X", centre);
    cout << endl;
  }

  spaces = string(n*n + n + 9, ' ');
  print_centred("X" + spaces + "X", centre);
  cout << endl;

  string bottom(n*n + n + 9, 'X');
  print_centred(bottom, centre);
  cout << endl;
}

int calc_centre(int n) {
  if(n == 1 || n == 2) return 11;
  if(n == 3) return 12;
  return n + calc_centre(n-1);
}

void print_two_with_offset(int centre) {
  for(string line : two) {
    string spaces(centre - 11, ' ');
    cout << spaces << line << endl;
  }
}

int main() {

  int t = 5;

  while(t--) {

    int n;
    cin >> n;

    if(n == 1) {
      cout << one << endl; 
    }else {
      int centre = calc_centre(n);

      print_two_with_offset(centre);

      for(int i = 3; i <= n; i++)
        print_torso(i, centre);

      print_centred(leg_segment, centre);
      cout << endl;
      print_centred(leg_segment, centre);
      cout << endl;
    }
    
    if(t) cout << endl;
  }

  return 0;
}