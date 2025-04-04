#ifndef PHYSXWRAPPER_H
#define PHYSXWRAPPER_H

#include <PxPhysicsAPI.h> // Include PhysX SDK headers

namespace PhysXWrapper {

    // Define a class to wrap PhysX SDK
    class PhysXWrapper {
    public:
        PhysXWrapper();
        ~PhysXWrapper();

        bool initialize();
        void shutdown();

        // Add other helper functions here to abstract PhysX calls
        // Example function to create a physics scene
        physx::PxScene* createScene();

    private:
        physx::PxPhysics* gPhysics;        // Pointer to the PhysX SDK
        physx::PxFoundation* gFoundation;  // Foundation for initializing PhysX
        physx::PxScene* gScene;            // Scene instance
        physx::PxCooking* gCooking;        // Cooking instance

        // Function to initialize the 64-bit PhysX SDK
        bool init64BitPhysX();

        // Optionally handle any specifics based on the 32-bit version
        bool init32BitPhysX();
    };

}

#endif // PHYSXWRAPPER_H
