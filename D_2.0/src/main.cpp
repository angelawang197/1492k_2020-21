/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// R                    motor_group   1, 2            
// L                    motor_group   3, 4            
// Lift1                motor         5               
// BigLift              motor         6               
// Controller1          controller                    
// Rings                motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

int main() {
    
  while (1){
    
        //int a=Controller1.Axis3.value() *.9;
        int a=pow(Controller1.Axis3.value(),3)/(10000) * .9;
        int b=Controller1.Axis1.value() * .7;
        int left=a+b;
        int right=a-b;
        
        L.spin(fwd, left, pct);
        R.spin(fwd, right, pct);
       
        Lift1.setVelocity(40, pct);
        BigLift.setVelocity(80, pct);
        Rings.setVelocity(80, pct);
        Lift1.setBrake(hold);
        BigLift.setBrake(hold);
        Rings.setBrake(coast);

        if(Controller1.ButtonX.pressing()) {
            Lift1.spin(fwd);
        } else if(Controller1.ButtonY.pressing()) {
            Lift1.spin(reverse);
        } else {
            Lift1.stop();
        }

        if(Controller1.ButtonRight.pressing()) {
            BigLift.spin(fwd);
        } else if(Controller1.ButtonUp.pressing()) {
            BigLift.spin(reverse);
        } else {
            BigLift.stop();
        }

        if(Controller1.ButtonR2.pressing()){
          Rings.spin(fwd);
        } else if(Controller1.ButtonR1.pressing()){
          Rings.spin(reverse);
        } else {
          Rings.stop();
        }

        task::sleep(20);
        // sleep is great
        // zzzzzzzzzzzzzzz *snores*
  }
}
