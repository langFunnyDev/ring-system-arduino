typedef struct  {
  byte hours;
  byte minutes;
  byte seconds;
  bool is_break;
} shedule_part;

shedule_part min40_shedule[20] {
  {8, 0, 0, false},
  {8, 40, 0, true},
  {8, 50, 0, false},
  {9, 30, 0, true},
  {9, 45, 0, false},
  {10, 25, 0, true},
  {10, 40, 0, false},
  {11, 20, 0, true},
  {11, 35, 0, false},
  {12, 15, 0, true},
  {12, 25, 0, false},
  {13, 5, 0, true},
  {13, 15, 0, false},
  {13, 55, 0, true},
  {14, 10, 0, false},
  {14, 50, 0, true},
  {15, 0, 0, false},
  {15, 40, 0, false},
  {15, 50, 0, true},
  {16, 30, 0, false}
};


shedule_part min30_shedule[20] {
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
  {14, 20, 0, false}
};
