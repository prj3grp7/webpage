#include "WebPage.h"
#include "GameController.h"

int main()
{
	MsgQueue GameControllerMsgQueue_;
	GameController GameControllerObj_(&GameControllerMsgQueue_);
	WebPage WebPageObj_(&GameControllerMsgQueue_);

	Thread GameThread(&GameControllerObj_);
	Thread WebPageThread(&WebPageObj_);

	GameThread.start();
	WebPageThread.start();
	
	GameThread.join();
	WebPageThread.join();
}
