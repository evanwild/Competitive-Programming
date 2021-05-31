#include <iostream>

int time_plus_mins(int time, int mins) {

  int minute = ((time / 10) % 10) * 10 + time % 10;
  int hour = ((time / 1000) % 10) * 10 + (time / 100) % 10;

  for(int i = 0; i < mins; i++) {
    if(minute == 59) {
      minute = 0;
      if(hour == 23) {
        hour = 0;
      }else {
        hour++;
      }
    }else {
      minute++;
    }
  }

  return hour * 100 + minute;
}

int time_minus_mins(int time, int mins) {

  int minute = ((time / 10) % 10) * 10 + time % 10;
  int hour = ((time / 1000) % 10) * 10 + (time / 100) % 10;

  for(int i = 0; i < mins; i++) {
    if(minute == 0) {
      minute = 59;
      if(hour == 0) {
        hour = 23;
      }else {
        hour--;
      }
    }else {
      minute--;
    }
  }

  return hour * 100 + minute;
}

int main() {

  int ottawa;
  std::cin >> ottawa;

  std::cout << ottawa << " in Ottawa" << std::endl;
  std::cout << time_minus_mins(ottawa, 180) << " in Victoria" << std::endl;
  std::cout << time_minus_mins(ottawa, 120) << " in Edmonton" << std::endl;
  std::cout << time_minus_mins(ottawa, 60) << " in Winnipeg" << std::endl;
  std::cout << ottawa << " in Toronto" << std::endl;
  std::cout << time_plus_mins(ottawa, 60) << " in Halifax" << std::endl;
  std::cout << time_plus_mins(ottawa, 90) << " in St. John's" << std::endl;

  return 0;
}