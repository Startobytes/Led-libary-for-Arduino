#ifndef tl
#define tl
#include "Arduino.h"

class LedLib {
  public:
    // Constructor 
    LedLib(int _pin, bool db);
    int pin;
    
    // Methods
    void blk(int dlt);
    void start_db(int baud = 9600);
    bool _debug;
    void on(int a);
    void off();
    void fade(int am, int dl, bool tf);
    void say();

  private:
    
    void lkl();
    
};
#endif
