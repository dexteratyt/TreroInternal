#include <Windows.h>
#include "../Utils.h"

class ClientInstance {
public:
    class Player* getLocalPlayer(){
		static unsigned int offset = 0x140;
		offset = *reinterpret_cast<int*>(Mem::findSig("48 8B 81 ? ? ? ? C3 CC CC CC CC CC CC CC CC 40 55") + 3);
        return *reinterpret_cast<Player**>((uintptr_t)(this) + offset); // 0x140
    };

    bool* getKey(char c) {
        return reinterpret_cast<bool*>((uintptr_t)GetModuleHandleA("Minecraft.Windows.exe") + 0x402EA20 + ((int)c * 4));
    };
    bool* getKey(int c) {
        return reinterpret_cast<bool*>((uintptr_t)GetModuleHandleA("Minecraft.Windows.exe") + 0x402EA20 + (c * 4));
    };
};