/*
 * main implementation: use this 'C' sample to create your own application
 *
 */






#include "derivative.h" /* include peripheral declarations */



#include "Timer.h"
#include "OLED.H"
#include "OLEDFB.h"
#include "OLEDFONT.h"
#include "Counter.h"
#include "Button.h"
#include "Buzzer.h"
#include "MusicLibrary.h"
#include "Led.h"

#include "AppFramework.h"

#include "CLOCKAPP.h"



int main()
{
	Timer_init(10);
	OLED_Init();
	OLEDFB_init();
	
	Buzzer_init();
	Button_init();
	Led_init();
	
	MusicLibrary_init();
	AppAlarmClock_init();
	
	
	//FPS¼ÆÊýÆ÷
	Timer_set(16, updateCounter);
	Timer_set(250, updateCounter2);
	
	int frame = 0;
	
	
	App_switchTo(&AppAlarmClock_theApp);
    
    
	for(;;)
	{
		
		OLEDFB_clear();
		App_repaint();
	    frame ++;
	    OLEDFB_flush();
	}
	return 0;
}
