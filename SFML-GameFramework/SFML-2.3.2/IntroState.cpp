#include "IntroState.h"
#include "IntroScene.h"


void IntroState::pause() 
{
	printf("IntroState pause\n");
}

void IntroState::resume() 
{
	printf("IntroState resume\n");
}

IntroState* IntroState::intro_state_ = NULL;

IntroState* IntroState::Instance(AbstractScene* scene, EventHandler* event_handler)
{	
	intro_state_ = new IntroState(scene, event_handler);
	return intro_state_;
}

IntroState * IntroState::Instance()
{
	if (intro_state_ == NULL)
		printf("Instance not created");
	return intro_state_;
}
 