#include "Engine.h"


int main(int argc, char** argv) {

	Engine* engine = Engine::getInstance();
	engine->init(argc, argv);
	engine->start();

    return 1;


}



