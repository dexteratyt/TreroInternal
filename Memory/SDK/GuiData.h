#pragma once

#include "../Utils.h"
#include "../../Math/Math.h"

class GuiData { // minecraft virtual guidata class vtable thing whatevber the fuck you call this minhook thingy yes
public:
	char pad_0x0000[0x20]; //0x0000
	Vector2 res; //0x0020
	Vector2 scaledRes; //0x0028

	float GuiScale() {
		return *reinterpret_cast<float*>(reinterpret_cast<uintptr_t>(this) + 0x34);
	};
	
	char pad_0x0052[0x52];
	uint64_t mouseX; //0x0052
	uint64_t mouseY; //0x0054
};