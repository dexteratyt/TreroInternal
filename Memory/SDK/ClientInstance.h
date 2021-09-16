#include <Windows.h>
#include "../Utils.h"

class ClientInstance {
public:
    class Player* getLocalPlayer(){
		static unsigned int offset = 0x140;
		//offset = *reinterpret_cast<int*>(Mem::findSig("48 8B 81 ? ? ? ? C3 CC CC CC CC CC CC CC CC 40 55") + 3);
        return *reinterpret_cast<Player**>((uintptr_t)(this) + offset); // 0x140
    };
};