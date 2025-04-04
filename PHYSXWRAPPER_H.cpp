#ifndef PHYSXWRAPPER_H
#define PHYSXWRAPPER_H

#include <PxPhysicsAPI.h>

namespace PhysXWrapper {

class PhysXWrapper {
public:
    PhysXWrapper();
    ~PhysXWrapper();

    bool initialize();
    void shutdown();

    physx::PxScene* createScene();

private:
    physx::PxPhysics* gPhysics;
    physx::PxFoundation* gFoundation;
    physx::PxScene* gScene;
    physx::PxCooking* gCooking;

    bool init64BitPhysX();
    bool init32BitPhysX();
};

} // namespace PhysXWrapper

#endif // PHYSXWRAPPER_H

