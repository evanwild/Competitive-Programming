#include <iostream>
#include <string>

int main() {

  int num_games;
  std::cin >> num_games;

  std::string alice[100];
  for(int i = 0; i < num_games; i++) {
    std::cin >> alice[i];
  }

  std::string bob[100];
  for(int i = 0; i < num_games; i++) {
    std::cin >> bob[i];
  }

  int alice_wins = 0;
  int bob_wins = 0;
  for(int i = 0; i < num_games; i++) {
    if(alice[i] == bob[i]) {
      continue;
    }
    if(alice[i] == "rock" && bob[i] == "scissors") {
      alice_wins++;
      continue;
    }
    if(alice[i] == "paper" && bob[i] == "rock") {
      alice_wins++;
      continue;
    }
    if(alice[i] == "scissors" && bob[i] == "paper") {
      alice_wins++;
      continue;
    }
    if(bob[i] == "rock" && alice[i] == "scissors") {
      bob_wins++;
      continue;
    }
    if(bob[i] == "paper" && alice[i] == "rock") {
      bob_wins++;
      continue;
    }
    if(bob[i] == "scissors" && alice[i] == "paper") {
      bob_wins++;
      continue;
    }
  }

  std::cout << alice_wins << " " << bob_wins << std::endl;

  return 0;
}