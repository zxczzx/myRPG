#include <thread>
#include <mutex>
#include <chrono>
#include <limits>
#include "Game.h"

class MainThread {
private:
	int action;
	std::unique_ptr<Game> game;

	void handleMainInput();
	void MainInput();

public:
	MainThread();

	std::thread handleInputThread();
	std::thread InputThread();
};

// ----------* MAIN *----------

int main(int argc, char **argv) {
	std::unique_ptr<MainThread> mainThread = std::make_unique<MainThread>();
	std::thread mainHandleInput = mainThread->handleInputThread();
	std::thread mainInput = mainThread->InputThread();
	mainInput.join();
	mainHandleInput.join();
	return 0;
}

//----------------------------

MainThread::MainThread() : game(std::make_unique<Game>()), action(0){
	game->setGraphic(Graphic::MENU_GUI);
}

void MainThread::handleMainInput(){
	while (true){
		game->handleInput(game->atomicAction.load());
		game->atomicAction.store(0);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

void MainThread::MainInput(){
	while (true){
		std::cin >> action;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		game->atomicAction.store(action);
		game->gotInput = true;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

std::thread MainThread::handleInputThread(){
	return std::thread([=] { handleMainInput(); });
}

std::thread MainThread::InputThread(){
	return std::thread([=] { MainInput(); });
}