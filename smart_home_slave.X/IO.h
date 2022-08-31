#ifndef IO_H
#define	IO_H


#define Buzzer PD5


// PORT CONFIGURETION................

void SetPortDir(int PortNum, int Statue);
void SetPortData(int PortNum, int Data);
void TogglePort(int PortNum);

// PIN CONFIGURETION................

void SetPinDir(int PortNum, int PinNum, int Statue);
void SetPinData(int PortNum, int PinNum, int Data);
void TogglePin(int PortNum, int PinNum);


void Init_Buzzer();


void Set_Buzzer(int state);

int IsPressed(int PortNum, int ButtonNum);



#endif	/* IO_H */

