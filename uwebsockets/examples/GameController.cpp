#include "GameController.h"
#include "WebPageResponse.h"

void GameController::run()
{
	while (true)
	{
		unsigned long messageID;
		Message * msg = GameControllerMsgQueue_->receive(messageID);
		dispatcher(messageID, msg);
		delete msg;
	}
}

void GameController::dispatcher(unsigned long messageID, Message * msg)
{
	switch (messageID)
	{
	case ID_INFO_READY:
	{
		WebPageResponse * ind = static_cast<WebPageResponse *>(msg);

		cout << "Team 1:" << endl;
		cout << "Teamname is: " << ind->team1_.getTeam() << endl;
		cout << "Username1 is: " << ind->team1_.getUser1() << endl;
		cout << "Username2 is: " << ind->team1_.getUser2() << endl;
		cout << "Red is: " << ind->team1_.getRed() << endl;
		cout << "Green is: " << ind->team1_.getGreen() << endl;
		cout << "Blue is: " << ind->team1_.getBlue() << endl << endl;

		cout << "Team 2:" << endl;
		cout << "Teamname is: " << ind->team2_.getTeam() << endl;
		cout << "Username1 is: " << ind->team2_.getUser1() << endl;
		cout << "Username2 is: " << ind->team2_.getUser2() << endl;
		cout << "Red is: " << ind->team2_.getRed() << endl;
		cout << "Green is: " << ind->team2_.getGreen() << endl;
		cout << "Blue is: " << ind->team2_.getBlue() << endl << endl;
	}
	}
}
