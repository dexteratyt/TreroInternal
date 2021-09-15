#include <Windows.h>
#include <MinHook.h>
#include "Math/Math.h"
#include "Memory/SDK/ClientInstance.h"
#include "Memory/SDK/Actor.h"
#include "Memory/SDK/Player.h"
#include <cmath>

#define PI 3.14159265359

typedef void(__thiscall* tick)(ClientInstance*, void* a2);
tick _tick;
bool vModule = false;

void callback(ClientInstance* instance, void* a2){ // trying to hook keymap so i can create bhop e

    // *instance->getKey('W')

    auto player = instance->getLongP();

    if (vModule){ // vModule
        if (player->isInWater() | player->isInLava())
        player->velocity()->y = .1f;
        *player->onGround() = true;
    }

    player->setSprinting(true);

    if (*instance->getKey('R')){ // vModule
        vModule = !vModule;
    }

    _tick(instance, a2);
};

void init(HMODULE c){
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