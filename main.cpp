#include <Windows.h>
#include <MinHook.h>
#include "Math/Math.h"
#include <cmath>

#define PI 3.14159265359

class ClientInstance { // 1.17.11
public:
    class Player* getPlayer(){ // local player
        return *reinterpret_cast<Player**>((uintptr_t)(this) + 0x140);
    };

    bool* getKey(char c) { // vDefinedKeys
        return reinterpret_cast<bool*>((uintptr_t)GetModuleHandleA("Minecraft.Windows.exe") + 0x402EA20 + ((int)c * 4));
    };
    bool* getKey(int c) { // VK_
        return reinterpret_cast<bool*>((uintptr_t)GetModuleHandleA("Minecraft.Windows.exe") + 0x402EA20 + (c * 4));
    };
};

class Player { // 1.17.11
public:
    Vector2* bodyRots() {
        return reinterpret_cast<Vector2*>((uintptr_t)(this) + 0x148);
    };

    bool* onGround() {
        return reinterpret_cast<bool*>((uintptr_t)(this) + 0x1E0);
    };

    bool* touchingBlock() {
        return reinterpret_cast<bool*>((uintptr_t)(this) + 0x1E4);
    };

    float* stepHeight() {
        return reinterpret_cast<float*>((uintptr_t)(this) + 0x240);
    };

    bool* inWater() {
        return reinterpret_cast<bool*>((uintptr_t)(this) + 0x265);
    };

    class Level* getLevel(){
        return *reinterpret_cast<Level**>((uintptr_t)(this) + 0x378);
    };

    Vector3* velocity() {
        return reinterpret_cast<Vector3*>((uintptr_t)(this) + 0x50C);
    };

    AABB* position() {
        return reinterpret_cast<AABB*>((uintptr_t)(this) + 0x4D0);
    };

    // cVoids
    void teleport(Vector3 v) {
        position()->lower.x = v.x;
        position()->lower.y = v.y;
        position()->lower.z = v.z;

        position()->upper.x = v.x + 0.6f;
        position()->upper.y = v.y + 1.8f;
        position()->upper.z = v.z + 0.6f;
    };

    void teleport(float x, float y, float z) {
        teleport(Vector3(x,y,z));
    };
};

class Level { // 1.17.11
public:
    //
};

typedef void(__thiscall* tick)(ClientInstance*, void* a2);
tick _tick;
bool vModule = false;

void callback(ClientInstance* instance, void* a2){ // trying to hook keymap so i can create bhop

    // *instance->getKey('W')

    auto player = instance->getPlayer();

    if (vModule && *player->inWater()){ // vModule
        player->velocity()->y = .1f;
        *player->onGround() = true;
    }

    if (*instance->getKey('R')){ // vModule
        vModule = !vModule;
    }

    _tick(instance, a2);
};

void init(HMODULE hModule){
    if(MH_Initialize() == MH_OK){
        uintptr_t baseAddr = (uintptr_t)GetModuleHandleA("Minecraft.Windows.exe");
        uintptr_t hookAddr = (uintptr_t)(baseAddr + 0x778C35);

        if(MH_CreateHook((void*)hookAddr, &callback, reinterpret_cast<LPVOID*>(&_tick)) == MH_OK){
            MH_EnableHook((void*)hookAddr);
        };
    };
};

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpReserved){
    switch(fdwReason){
        case DLL_PROCESS_ATTACH:
            CreateThread(0, 0, (LPTHREAD_START_ROUTINE)init, hInstance, 0, 0);
        break;
    };
    return TRUE;
};

/*

if(player != nullptr) {

        auto yaw = player->bodyRots()->y; // yaw
        
        if (*instance->getKey('W')){
            if (!*instance->getKey('A') && !*instance->getKey('S')){
                yaw += 90.0f;
            }
            if (*instance->getKey('A')){
                yaw += 45.0f;
            }
            else if (*instance->getKey('D')){
                yaw += 135.0f;
            }
        }
        else if (*instance->getKey('S')){
            if (!*instance->getKey('A') && !*instance->getKey('S')){
                yaw -= 90.0f;
            }
            if (*instance->getKey('A')){
                yaw -= 45.0f;
            }
            else if (*instance->getKey('D')){
                yaw -= 135.0f;
            }
        }
        else if (!*instance->getKey('W') && !*instance->getKey('S')){
            if (!*instance->getKey('A') && *instance->getKey('D')){
                yaw += 180.0f;
            }
        }
        
        if (!(*instance->getKey('W') | *instance->getKey('A') | *instance->getKey('S') | *instance->getKey('D'))) return;

        auto egirlbathwater = yaw * ((float)PI / 180.0f);
        auto speed = 3.0f;

        player->velocity()->x = cos(egirlbathwater) * speed;
        player->velocity()->z = sin(egirlbathwater) * speed;
    }


*/