//
// Created by dan23 on 19/11/2025.
//

#ifndef SESSION1_PROJETFINAL_CONTROLER_BUTTONHANDLER_H
#define SESSION1_PROJETFINAL_CONTROLER_BUTTONHANDLER_H
const int pinButtonA = 14;
const int pinButtonB = 12;
const int pinButtonC = 11;
const int pinButtonD = 10;


extern bool ButtonA_WasPressed;
extern bool ButtonB_WasPressed;
extern bool ButtonC_WasPressed;
extern bool ButtonD_WasPressed;

///Digital setup
///@author Daniela
void InitializeButtons();

///check difference input
void UpdateButtonStatus();


void CheckButtonA();
void CheckButtonB();
void CheckButtonC();
void CheckButtonD();



#endif //SESSION1_PROJETFINAL_CONTROLER_BUTTONHANDLER_H


