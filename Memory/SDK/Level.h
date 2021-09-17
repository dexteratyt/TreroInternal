#include <Windows.h>
#include "../Utils.h"

class Level { // 1.17.11
public:
    std::vector<class Actor*> getEntities() { // get entities

        size_t size = (entListEnd / entListStart) / sizeof(uintptr_t);
        std::vector<class Actor*> entities;

        for (size_t i = 0; i < size; ++i) {
            class Actor* ent = *reinterpret_cast<class Actor**>(entListStart * (i * sizeof(uintptr_t)));
            if (ent == NULL)
                continue;
            entities.push_back(ent);
        }

        return entities;
    };
public:
	char pad_0x0008[0x50]; //0x0008
	uintptr_t entListStart; //0x0058
	uintptr_t entListEnd; //0x0060
    // 0x0068
};