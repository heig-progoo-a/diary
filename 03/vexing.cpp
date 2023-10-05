struct Timer {};

struct TimeKeeper {
  explicit TimeKeeper(Timer t);
  int get_time();
};

int main() {
  TimeKeeper time_keeper{Timer()}; // Parenthèses pas bien
  return time_keeper.get_time();
}