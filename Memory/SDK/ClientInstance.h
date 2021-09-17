#include <Windows.h>
#include "../Utils.h"

class ClientInstance {
public:
    class Player* getLocalPlayer(){
		static unsigned int offset = 0x140;
		//offset = *reinterpret_cast<int*>(Mem::findSig("48 8B 81 ? ? ? ? C3 CC CC CC CC CC CC CC CC 40 55") + 3);
        return *reinterpret_cast<Player**>((uintptr_t)(this) + 0x140);
    };
    
    //class GuiData* getGuiData(){
    //    return *reinterpret_cast<GuiData**>((uintptr_t)(this) + 0x4D8);
    //};

    // GuiData class 0x4D8
};