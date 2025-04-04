#include <PxPhysicsAPI.h>
#include <iostream>

using namespace physx;

class PhysXWrapper
{
public:
    PhysXWrapper(bool is64bit = true)
        : m_is64bit(is64bit)
    {
        init();
    }

    ~PhysXWrapper()
    {
        cleanup();
    }

    void upgradeTo64bit()
    {
        if (!m_is64bit)
        {
            std::cout << "Upgrading to 64-bit PhysX..." << std::endl;
            m_is64bit = true;
            cleanup();
            init();
        }
    }

    void downgradeTo32bit()
    {
        if (m_is64bit)
        {
            std::cout << "Downgrading to 32-bit PhysX..." << std::endl;
            m_is64bit = false;
            cleanup();
            init();
        }
    }

private:
    bool m_is64bit;
    PxFoundation* m_foundation;
    PxPhysics* m_physics;
    PxScene* m_scene;
    PxDefaultCpuDispatcher* m_dispatcher;
    PxPvd* m_pvd;

    void init()
    {
        if (m_is64bit)
        {
            m_foundation = PxCreateFoundation(PX_PHYSICS_VERSION, m_allocator, m_errorCallback);
            m_physics = PxCreatePhysics(PX_PHYSICS_VERSION, *m_foundation, PxTolerancesScale(), true, nullptr);
        }
        else
        {
            m_foundation = PxCreateFoundation(PX_PHYSICS_VERSION, m_allocator, m_errorCallback);
            m_physics = PxCreatePhysics(PX_PHYSICS_VERSION, *m_foundation, PxTolerancesScale(), true, nullptr);
        }

        m_dispatcher = PxDefaultCpuDispatcherCreate(2); // Default CPU dispatcher with 2 worker threads.
        m_scene = m_physics->createScene(PxSceneDesc(m_physics->getTolerancesScale()));
        m_pvd = PxCreatePvd(*m_foundation);
        m_scene->setVisualizationParameter(PxVisualizationParameter::eSCALE, 0.1f);
        m_scene->setPvdConnection(m_pvd);
    }

    void cleanup()
    {
        if (m_scene)
        {
            m_scene->release();
            m_scene = nullptr;
        }

        if (m_physics)
        {
            m_physics->release();
            m_physics = nullptr;
        }

        if (m_foundation)
        {
            m_foundation->release();
            m_foundation = nullptr;
        }

        if (m_dispatcher)
        {
            m_dispatcher->release();
            m_dispatcher = nullptr;
        }

        if (m_pvd)
        {
            m_pvd->release();
            m_pvd = nullptr;
        }
    }
};

// Main function for example usage
int main()
{
    PhysXWrapper physxWrapper;

    // Simulate some physics actions
    physxWrapper.upgradeTo64bit();  // Example of upgrading to 64-bit
    physxWrapper.downgradeTo32bit();  // Example of downgrading to 32-bit

    return 0;
}
