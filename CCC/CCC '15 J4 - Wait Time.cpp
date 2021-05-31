#include <iostream>

int main() {

  int m;
  std::cin >> m;

  bool friend_involved[101] = {false};
  bool friend_waiting[101] = {false};
  int friend_times[101] = {0};

  char last_command = 'W';

  for(int i = 0; i < m; i++) {
    char command;
    std::cin >> command;

    int x;
    std::cin >> x;

    if(command != 'W' && last_command != 'W') {
      for(int j = 1; j < 101; j++) {
        if(friend_waiting[j]) {
          friend_times[j]++;
        }
      }
    }

    if(command == 'R') {
      friend_involved[x] = true;
      friend_waiting[x] = true;
    }else if(command == 'S') {
      friend_waiting[x] = false;
    }else if(command == 'W') {
      for(int j = 1; j < 101; j++) {
        if(friend_waiting[j]) {
          friend_times[j] += x;
        }
      }
    }

    last_command = command;

  }

  for(int i = 1; i < 101; i++) {
    if(friend_involved[i]) {
      std::cout << i << " ";
      if(!friend_waiting[i]) {
        std::cout << friend_times[i] << std::endl;
      }else {
        std::cout << "-1" << std::endl;
      }
    }
  }

  return 0;
}