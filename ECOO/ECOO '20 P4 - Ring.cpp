#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M1 = 1e9 + 7;

struct step {
  string type;
  int int_value;
  string str_value;
};

struct fun {
  int m, b, end;
};

vector<step> steps;

int mod(int a) {
  int c = a % M1;
  return (c < 0) ? c + M1 : c;
}

map<string, fun> dp;
fun solve(int i) {
  string fun_name = steps[i].str_value;

  fun curr_fun;
  curr_fun.m = 1, curr_fun.b = 0;
  i++;
  while(steps[i].type != "END") {
    if(steps[i].type == "MULT") {
        curr_fun.m = mod(curr_fun.m * steps[i].int_value);
        curr_fun.b = mod(curr_fun.b * steps[i].int_value);
    }else if(steps[i].type == "ADD") {
        curr_fun.b = mod(curr_fun.b + steps[i].int_value);
    }else if(steps[i].type == "SUB") {
        curr_fun.b = mod(curr_fun.b - steps[i].int_value);
    }else if(steps[i].type == "CALL") {
        curr_fun.m = mod(curr_fun.m * dp[steps[i].str_value].m);
        curr_fun.b = mod(curr_fun.b * dp[steps[i].str_value].m);
        curr_fun.b = mod(curr_fun.b + dp[steps[i].str_value].b);
    }else if(steps[i].type == "FUN") {
        solve(i);
        i = dp[steps[i].str_value].end;
    }
    i++;
  }
  
  curr_fun.end = i;
  return dp[fun_name] = curr_fun;
}

void solve_tc() {
  int N;
  cin >> N;

  step entire_fun;
  entire_fun.type = "FUN", entire_fun.str_value = "Entire", steps.push_back(entire_fun);
  for(int i = 0; i < N; i++) {
    step curr_step;
    cin >> curr_step.type;
    if(curr_step.type == "END") {
      steps.push_back(curr_step);
      continue;
    }
    if(curr_step.type == "FUN" || curr_step.type == "CALL") {
      cin >> curr_step.str_value;
    } else {
      cin >> curr_step.int_value;
    }
    steps.push_back(curr_step);
  }
  step entire_end;
  entire_end.type = "END";
  steps.push_back(entire_end);

  cout << solve(0).b << '\n';
  
  steps.clear(), dp.clear();
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    solve_tc();
  }

  return 0;
}