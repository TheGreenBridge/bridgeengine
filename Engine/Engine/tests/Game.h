#pragma once

///PLATFORM
#include "..\src\platform\windows\window.h"
#include "..\src\platform\windows\InputManager.h"
#include "..\src\systems\CollisionManager.h"
#include "..\src\systems\AnimationManager.h"
#include "..\src\platform\windows\Console.h"
#include "..\src\systems\SystemManager.h"

//#include <AntTweakBar.h>
// NAMESPACES
using namespace engine;
using namespace engine::memory;
using namespace engine::collision;

#define MEM_STORAGE 8192 // 8 KiB = 8 * 2^10

// GLOBALS
//Vec3 fPoint(10, 10, 10);
class Game {
private:	
	Window window;	
	// SYSTEMS
	SystemManager gSystemManager;
	InputManager gInputManager;
	AnimationManager gAnimationManager;
	CollisionManager gCollisionManager;
public:
	Game();
	~Game();

	void init();
	void run();
};