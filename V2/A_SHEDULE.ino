typedef struct  {
  byte hours;
  byte minutes;
  byte seconds;
  bool is_break;
} shedule_part;

shedule_part min40_shedule[24] {
  {8, 0, 0, false},
  {8, 45, 0, true},
  {8, 50, 0, false},
  {9, 35, 0, true},
  {9, 40, 0, false},
  {10, 25, 0, true},
  {10, 30, 0, false},
  {11, 15, 0, true},
  {11, 20, 0, false},
  {12, 05, 0, true},
  {12, 10, 0, false},
  {12, 55, 0, true},
  {13, 0, 0, false},
  {13, 45, 0, true},
  {13, 50, 0, false},
  {14, 35, 0, true},
  {14, 40, 0, false},
  {15, 25, 0, false},
  {15, 30, 0, true},
  {16, 15, 0, false},
  {16, 20, 0, true},
  {17, 5, 0, false},
  {17, 10, 0, true},
  {17, 55, 0, false}
};


shedule_part min30_shedule[24] {
  {8, 0, 0, false},
  {8, 30, 0, true},
  {8, 40, 0, false},
  {9, 10, 0, true},
  {9, 20, 0, false},
  {9, 50, 0, true},
  {10, 0, 0, false},
  {10, 30, 0, true},
  {10, 45, 0, false},
  {11, 15, 0, true},
  {11, 20, 0, false},
  {11, 50, 0, true},
  {12, 00, 0, false},
  {12, 30, 0, true},
  {12, 35, 0, false},
  {13, 5, 0, true},
  {13, 10, 0, false},
  {13, 40, 0, false},
  {13, 50, 0, true},
  {14, 20, 0, false},
  {13, 50, 0, true},
  {14, 20, 0, false},
  {13, 50, 0, true},
  {14, 20, 0, false}
};
