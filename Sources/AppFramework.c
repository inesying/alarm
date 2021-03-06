/*
 * AppFramework.c
 *
 *  Created on: Mar 5, 2021
 *      Author: ??????
 */

#include "AppFramework.h"

App* currentApp=NULL;

void App_create(App* app,void (*paintHandler)(),void (*eventHandler)(int event,int data))
{
	app->paintHandler=paintHandler;
	app->eventHandler=eventHandler;
}

void App_switchTo(App* app){
	if(currentApp!=NULL){
		App_sendMessage(EVENT_APP_QUIT,0);
	}
	currentApp=app;
	App_sendMessage(EVENT_APP_INIT,0);
}

App* App_getCurrentApp()
{
	return currentApp;
}

void App_sendMessage(int event,int data){
	currentApp->eventHandler(event,data);
}

void App_repaint(){
	currentApp->paintHandler();
}


