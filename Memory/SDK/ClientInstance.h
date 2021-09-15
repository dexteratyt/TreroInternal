#include <Windows.h>

class ClientInstance {
public:
    class Player* getLongP(){
        return *reinterpret_cast<Player**>((uintptr_t)(this) + 0x140);
    };

    bool* getKey(char c) {
        return reinterpret_cast<bool*>((uintptr_t)GetModuleHandleA("Minecraft.Windows.exe") + 0x402EA20 + ((int)c * 4));
    };
    bool* getKey(int c) {
        return reinterpret_cast<bool*>((uintptr_t)GetModuleHandleA("Minecraft.Windows.exe") + 0x402EA20 + (c * 4));
    };
};