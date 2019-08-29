typedef struct  {
  byte id;
  char mode_name[14];
} mode;

mode modes[5] {
  {1, "40 minutes"},
  {2, "30 minutes"},
  {3, "Attention all"},
  {4, "Fire alarm"},
  {5, "Idle mode"}
};
