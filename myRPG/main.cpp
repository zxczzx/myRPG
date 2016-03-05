//#include <thread>
//#include <mutex>
//#include <chrono>
//#include <limits>
//#include <regex>
//#include "World.h"
//
//class MainThread {
//private:
//	int action;
//	std::unique_ptr<World> world;
//
//	void handleMainInput();
//	void MainInput();
//
//public:
//	MainThread();
//
//	std::thread handleInputThread();
//	std::thread InputThread();
//};
//
//// ----------* MAIN *----------
//
//int main(int argc, char **argv) {
//	std::unique_ptr<MainThread> mainThread = std::make_unique<MainThread>();
//	std::thread mainHandleInput = mainThread->handleInputThread();
//	std::thread mainInput = mainThread->InputThread();
//	mainInput.join();
//	mainHandleInput.join();
//	return 0;
//}
//
////----------------------------
//
//MainThread::MainThread() : world(std::make_unique<World>()), action(0){
//	world->setGraphic(Graphic::MENU_GUI);
//}
//
//void MainThread::handleMainInput(){
//	while (true){
//		world->handleInput(world->atomicAction.load());
//		world->atomicAction.store(0);
//		std::this_thread::sleep_for(std::chrono::milliseconds(10));
//	}
//}
//
//void MainThread::MainInput(){
//	std::regex r("[[:digit:]]+");
//	std::string input;
//	while (true){
//		world->accum_mutex.lock();
//		std::cin >> input;
//
//		if (std::regex_match(input, r)){
//			action = std::stoi(input);
//			world->atomicAction.store(action);
//			world->gotInput = true;
//		}
//
//		std::this_thread::sleep_for(std::chrono::milliseconds(10));
//		world->accum_mutex.unlock();
//	}
//}
//
//std::thread MainThread::handleInputThread(){
//	return std::thread([=] { handleMainInput(); });
//}
//
//std::thread MainThread::InputThread(){
//	return std::thread([=] { MainInput(); });
//}

#include "Game.h"

void main() {
	Game world;
	while (!world.getWindow()->isDone()) {
		world.handleInput();
		world.update();
		world.render();
		world.restartClock();
	}
}