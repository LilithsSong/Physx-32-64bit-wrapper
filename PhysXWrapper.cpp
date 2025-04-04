#include "PhysXWrapper.h"
#include <iostream>
#include <cstdlib>

using namespace physx;
using namespace PhysXWrapper;

PhysXWrapper::PhysXWrapper()
    : gFoundation(nullptr), gPhysics(nullptr), gScene(nullptr), gCooking(nullptr) {}

PhysXWrapper::~PhysXWrapper() {
    shutdown();
}

bool PhysXWrapper::initialize() {
    // For simplicity, we assume 64-bit is the default here
    return init64BitPhysX();
}

void PhysXWrapper::shutdown() {
    if (gScene) {
        gScene->release();
    }
    if (gPhysics) {
        gPhysics->release();
    }
    if (gCooking) {
        gCooking->release();
    }
    if (gFoundation) {
        gFoundation->release();
    }
}

bool PhysXWrapper::init64BitPhysX() {
    // Initialize the foundation for 64-bit PhysX
    gFoundation = PxCreateFoundation(PX_PHYSX_VERSION, gAllocator, gErrorCallback);
    if (!gFoundation) {
        std::cerr << "PhysX foundation initialization failed!" << std::endl;
        return false;
    }

    // Initialize the 64-bit PhysX SDK
    gPhysics = PxCreatePhysics(PX_PHYSX_VERSION, *gFoundation, PxTolerancesScale(), true, nullptr);
    if (!gPhysics) {
        std::cerr << "PhysX initialization failed!" << std::endl;
        return false;
    }

    // Initialize cooking
    gCooking = PxCreateCooking(PX_PHYSX_VERSION, *gFoundation, PxCookingParams(PxTolerancesScale()));
    if (!gCooking) {
        std::cerr << "PhysX cooking initialization failed!" << std::endl;
        return false;
    }

    return true;
}

bool PhysXWrapper::init32BitPhysX() {
    // Initialize a 32-bit version of PhysX (as an example)
    std::cerr << "32-bit initialization is not implemented in this wrapper." << std::endl;
    return false;
}

PxScene* PhysXWrapper::createScene() {
    if (gPhysics) {
        // Create the scene based on PhysX 64-bit
        PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
        sceneDesc.gravity = PxVec3(0.0f, -9.81f, 0.0f);
        gScene = gPhysics->createScene(sceneDesc);
        if (!gScene) {
            std::cerr << "Failed to create PhysX scene!" << std::endl;
            return nullptr;
        }
    }
    return gScene;
}
