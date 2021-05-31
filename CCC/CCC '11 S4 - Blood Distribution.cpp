#include <iostream>

using namespace std;

int max_patients = 0;

void give_blood(int &units, int &patients) {
  if(units > patients) {
    max_patients += patients;
    units -= patients;
    patients = 0;
  }else if(patients > units) {
    max_patients += units;
    patients -= units;
    units = 0;
  }else if(patients == units){
    max_patients += patients;
    patients = units = 0;
  }
}

int main() {

  int on, op, an, ap, bn, bp, abn, abp;
  cin >> on >> op >> an >> ap >> bn >> bp >> abn >> abp;

  int pon, pop, pan, pap, pbn, pbp, pabn, pabp;
  cin >> pon >> pop >> pan >> pap >> pbn >> pbp >> pabn >> pabp;

  // Type-O patients
  give_blood(on, pon);
  give_blood(op, pop);
  give_blood(on, pop);

  // Type-A
  give_blood(an, pan);
  give_blood(on, pan);
  give_blood(ap, pap);
  give_blood(an, pap);
  give_blood(op, pap);
  give_blood(on, pap);

  // Type-B
  give_blood(bn, pbn);
  give_blood(on, pbn);
  give_blood(bp, pbp);
  give_blood(bn, pbp);
  give_blood(op, pbp);
  give_blood(on, pbp);

  //Type-AB
  give_blood(on, pabn);
  give_blood(an, pabn);
  give_blood(bn, pabn);
  give_blood(abn, pabn);
  give_blood(on, pabp);
  give_blood(an, pabp);
  give_blood(bn, pabp);
  give_blood(abn, pabp);
  give_blood(op, pabp);
  give_blood(ap, pabp);
  give_blood(bp, pabp);
  give_blood(abp, pabp);

  cout << max_patients << endl;

  return 0;
}