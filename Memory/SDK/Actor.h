#pragma once
#include <Windows.h>
#include "../../Math/Math.h"
#include "Level.h"
#include <bitset>
#include <vector>
#include <functional>

class Actor { // 1.17.11
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

    std::string getType() {
		return (char*)((uintptr_t)(this) + 0x410);
	};

    AABB* position() {
        return reinterpret_cast<AABB*>((uintptr_t)(this) + 0x4D0);
    };

    Vector3* velocity() {
        return reinterpret_cast<Vector3*>((uintptr_t)(this) + 0x50C);
    };

	std::string getUsername() {
		return (char*)((uintptr_t)(this) + 0x920);
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
/*private:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
public:
	virtual void _serverInitItemStackIds(void);
	virtual void _doInitialMove(void);
private:
	virtual void Function6();
public:
	virtual void reset(void);
	virtual __int64 getOnDeathExperience(void);
	virtual int getOwnerEntityType(void);
	virtual void remove(void);
	virtual void setPos(Vector3*);
private:
	virtual void Function12();
public:
	virtual __int64 getPredictedMovementValues(void);
	virtual __int64 getStateVectorComponent(void);
	virtual Vector3* getPos(void);
	virtual Vector3* getPosExtrapolated(float);
	virtual Vector3* getAttachPos(__int64 ActorLocation, float);
	virtual Vector3* getFiringPos(void);
	virtual void setRot(Vector2*);
	virtual void move(__int64 IActorMovementProxy, Vector3*);
	virtual void move(Vector3*);
	virtual Vector3* getInterpolatedRidingPosition(float);
	virtual float getInterpolatedBodyRot(float);
	virtual float getInterpolatedHeadRot(float);
	virtual float getInterpolatedBodyYaw(float);
	virtual float getYawSpeedInDegreesPerSecond(void);
	virtual float getInterpolatedWalkAnimSpeed(float);
	virtual Vector3* getWorldPosition(void);
private:
	virtual void Function29();
public:
	virtual void updateEntityInside(void);
	virtual void updateEntityInside(AABB*);
	virtual bool isFireImmune(void);
private:
	virtual void Function33();
public:
	virtual bool blockedByShield(__int64 ActorDamageSource, Actor*);
	virtual void teleportTo(Vector3*, bool, int, int);
	virtual void tryTeleportTo(Vector3*, bool, bool, int, int);
	virtual void chorusFruitTeleport(Vector3*);
	virtual void lerpTo(Vector3*, Vector2*, int);
	virtual void lerpMotion(Vector3*);
	virtual void tryCreateAddActorPacket(void);
	virtual void normalTick(void);
	virtual void baseTick(void);
	virtual void rideTick(void);
	virtual void positionRider(Actor*, float);
	virtual float getRidingHeight(void);
	virtual void startRiding(Actor*);
	virtual void addRider(Actor*);
	virtual void flagRiderToRemove(Actor*);
	virtual void getExitTip(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, __int64 InputMode);
	virtual bool intersects(Vector3*, Vector3*);
	virtual bool isFree(Vector3*);
	virtual bool isFree(Vector3*, float);
	virtual bool isInWall(void);
	virtual bool isInvisible(void);
	virtual bool canShowNameTag(void);
private:
	virtual void Function56();
public:
	virtual void setNameTagVisible(bool);
private:
	virtual void Function57();
	virtual void Function58();
	virtual void Function59();
	virtual void Function60();
	virtual void Function61();
	virtual void Function62();
	virtual void Function63();
public:
	virtual void setScoreTag(std::string const&);
private:
	virtual void Function65();
public:
	virtual bool isInWater(void);
	virtual bool hasEnteredWater(void);
	virtual bool isImmersedInWater(void);
	virtual bool isInLava(void);
	virtual bool isUnderLiquid(__int64 MaterialType);
	virtual bool isOverWater(void);
	virtual void setBlockMovementSlowdownMultiplier(Vector3*);
	virtual void resetBlockMovementSlowdownMultiplier(void);
	virtual float getCameraOffset(void);
	virtual float getShadowHeightOffs(void);
	virtual float getShadowRadius(void);
	virtual Vector3* getHeadLookVector(float);
private:
	virtual void Function78();
public:
	virtual bool canSee(Vector3*);
	virtual bool canSee(Actor*);
	virtual bool isSkyLit(float);
	virtual float getBrightness(float);
private:
	virtual void Function83();
	virtual void Function84();
public:
	virtual void onAboveBubbleColumn(bool);
	virtual void onInsideBubbleColumn(bool);
	virtual bool isImmobile(void);
	virtual bool isSilent(void);
	virtual bool isPickable(void);
private:
	virtual void Function90();
public:
	virtual bool isSleeping(void);
private:
	virtual void Function92();
public:
	virtual void setSneaking(bool);
	virtual bool isBlocking(void);
	virtual bool isDamageBlocked(__int64 ActorDamageSource);
	virtual bool isAlive(void);
	virtual bool isOnFire(void);
	virtual bool isOnHotBlock(void);
private:
	virtual void Function99();
public:
	virtual bool isSurfaceMob(void);
private:
	virtual void Function101();
	virtual void Function102();
	virtual void Function103();
public:
	virtual bool isAffectedByWaterBottle(void);
	virtual bool canAttack(Actor*, bool);
	virtual bool setTarget(Actor*);
private:
	virtual void Function107();
public:
	virtual bool isValidTarget(Actor*);
	virtual void attack(Actor*);
	virtual float performRangedAttack(Actor*, float);
	virtual void adjustDamageAmount(int);
	virtual int getEquipmentCount(void);
	virtual void setOwner(__int64 ActorUniqueID);
	virtual void setSitting(bool);
private:
	virtual void Function114();
	virtual void Function115();
public:
	virtual __int64 getInventorySize(void);
	virtual __int64 getEquipSlots(void);
	virtual __int64 getChestSlots(void);
	virtual void setStanding(bool);
	virtual bool canPowerJump(void);
	virtual void setCanPowerJump(bool);
	virtual bool isJumping(void);
	virtual bool isEnchanted(void);
private:
	virtual void Function124();
	virtual void Function125();
public:
	virtual bool shouldRender(void);
	virtual bool isInvulnerableTo(__int64 ActorDamageSource);
private:
	virtual void Function129();
public:
	virtual void actuallyHurt(int, __int64 ActorDamageSource, bool);
	virtual void animateHurt(void);
	virtual void doFireHurt(int);
	virtual void onLightningHit(void);
private:
	virtual void Function134();
public:
	virtual void feed(int);
	virtual void handleEntityEvent(__int64 ActorEvent, int);
	virtual float getPickRadius(void);
	virtual __int64 getActorRendererId(void);
private:
	virtual void E();
	virtual void A();
	virtual void SPORTS();
public:
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(int, int);
	virtual void despawn(void);
	virtual void killed(Actor*);
	virtual void awardKillScore(Actor*, int);
private:
	virtual void functionv();
	virtual void ITS();
	virtual void VRFD();
public:
	virtual __int64 getArmorMaterialTypeInSlot(int ArmorSlot);
	virtual __int64 getArmorMaterialTextureTypeInSlot(int ArmorSlot);
	virtual __int64 getArmorColorInSlot(int ArmorSlot, int);
private:
	virtual void THE();
	virtual void GAME();
	virtual void f1();
	virtual void f2();
	virtual void f3();
	virtual void f4();
public:
	virtual void consumeTotem(void);
	virtual void save(__int64 CompoundTag);
	virtual void saveWithoutId(__int64 CompoundTag);
	virtual void load(__int64 CompoundTag, __int64 DataLoadHelper);
	virtual void loadLinks();
	virtual __int64 getEntityTypeId(void);
	virtual __int64 getRawName(void);
	virtual __int64 getSourceUniqueID(void);
	virtual void setOnFire(int duration);
	virtual void extinguishFire(void);
	virtual void thawFreezeEffect(void);
	virtual bool canFreeze(void);
	virtual bool isWearingLeatherArmor(void);
	virtual AABB* getHandleWaterAABB(void);
private:
	virtual void Function171();
public:
	virtual __int64 getId(void);
	virtual __int64 getPortalWaitTime(void);
	virtual DWORD getDimensionId(void);
	virtual bool canChangeDimensions(void);
private:
	virtual void Function176();
public:
	virtual void changeDimension(int Dimension, bool);
	virtual __int64 getControllingPlayer(void);
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float, float, __int64 ActorDamageSource);
	virtual void handleFallDistanceOnServer(float, float, bool);
private:
	virtual void Function182();
	virtual void Function183();
public:
	virtual void onSynchedDataUpdate(int);
	virtual void canAddRider(Actor*);
private:
	virtual void Function186();
	virtual void Function187();
public:
	virtual bool inCaravan(void);
private:
	virtual void Function189();
public:
	virtual void tickLeash(void);
private:
	virtual void Function191();
	virtual void Function192();
public:
	virtual void stopRiding(bool, bool, bool);
	virtual void startSwimming(void);
	virtual void stopSwimming(void);
	virtual __int64 buildDebugInfo(void);
	virtual int getCommandPermissionLevel(void);
	virtual __int64 getMutableAttribute(__int64 Attribute);
	virtual __int64 getAttribute(int Attribute);
	virtual __int64 getDeathTime(void);
	virtual void heal(int);
	virtual bool isInvertedHealAndHarm(void);
	virtual bool canBeAffected(__int64 MobEffectInstance);
	virtual bool canBeAffected(int);
	virtual bool canBeAffectedByArrow(__int64 MobEffectInstance);
	virtual void onEffectAdded(__int64 MobEffectInstance);
	virtual void onEffectUpdated(__int64 MobEffectInstance);
	virtual void onEffectRemoved(__int64 MobEffectInstance);
	virtual __int64 getAnimationComponent(void);
	virtual void openContainerComponent(Player*);
	virtual void swing(void);
	virtual void useItem(__int64 ItemStackBase, __int64 ItemUseMethod, bool);
private:
	virtual void Function213();
	virtual void Function214();
	virtual void Function215();
public:
	virtual float getMapDecorationRotation(void);
	virtual float getRiderYRotation(Actor*);
	virtual float getYHeadRot(void);
	virtual bool isWorldBuilder(void);
	virtual bool isCreative(void);
	virtual bool isAdventure(void);
private:
	virtual void Function220();
	virtual void Function221();
	virtual void Function222();
	virtual void Function223();
	virtual void Function224();
	virtual void Function225();
	virtual void Function226();
public:
	virtual void setSize(float width, float height);
	virtual __int64 getLifeSpan(void);
	virtual void onOrphan(void);
	virtual void wobble(void);
	virtual bool wasHurt(void);
	virtual void startSpinAttack(void);
	virtual void stopSpinAttack(void);
	virtual bool setDamageNearbyMobs(bool);
private:
	virtual void Function335();
public:
	virtual void reloadLootTable(__int64 EquipmentTableDefinition);
	virtual void reloadLootTable(void);
	virtual __int64 getLootTable(void);
private:
	virtual void Function339();
	virtual void Function340();
public:
	virtual void kill(void);
	virtual void die(__int64 ActorDamageSource);
	virtual bool shouldTick(void);
	virtual void createMovementProxy(void);
	virtual __int64 getMovementProxy(void);
	virtual float getNextStep(float);
	virtual void updateEntitySpecificMolangVariables(__int64 RenderParams);
	virtual void useWebsocketEncryption(void);
private:
	virtual void Function349();
public:
	virtual bool outOfWorld(void);
	virtual void _hurt(__int64 ActorDamageSource, int, bool, bool);
	virtual void markHurt(void);
	virtual __int64 _getAnimationComponent(__int64 , __int64 AnimationComponentGroup);
	virtual void readAdditionalSaveData(__int64 CompoundTag, __int64 DataLoadHelper);
	virtual void addAdditionalSaveData(__int64 CompoundTag);
private:
	virtual void Function356();
	virtual void Function357();
	virtual void Function358();
public:
	virtual void checkInsideBlocks(float);
	virtual void pushOutOfBlocks(Vector3*);
	virtual void updateWaterState(void);
	virtual void doWaterSplashEffect(void);
	virtual void spawnTrailBubbles(void);
	virtual void updateInsideBlock(void);
	virtual void _removeRider(__int64 ActorUniqueID, bool, bool, bool);
	virtual void _onSizeUpdated(void);
private:
	virtual void Function367();*/
};