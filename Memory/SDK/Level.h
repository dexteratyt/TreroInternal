#include <Windows.h>
#include "../Utils.h"

class Level { // 1.17.11
public:
    bool* presetFunc() {
        return reinterpret_cast<bool*>((uintptr_t)(this) + 0x0);
    };
public:
    virtual void function1();
};