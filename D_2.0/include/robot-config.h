using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor_group R;
extern motor_group L;
extern motor Lift1;
extern motor BigLift;
extern controller Controller1;
extern motor Rings;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );