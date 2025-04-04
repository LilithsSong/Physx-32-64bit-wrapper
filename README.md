# Physx-32-64bit-wrapper

Creating a wrapper for upgrading a 32-bit PhysX library to 64-bit involves several key steps. The wrapper essentially helps in ensuring that the transition from 32-bit to 64-bit is smooth by updating memory management, system architecture compatibility, and other low-level adjustments. Here's a general approach using C++ to build a wrapper that can work with a 64-bit PhysX library.
Steps to create a wrapper:
• Determine the type of PhysX library you're using. The PhysX SDK provided by NVIDIA has been compiled for different architectures (32-bit and 64-bit). The wrapper must check the current environment and select the appropriate PhysX library.
• Handle the transition between 32-bit and 64-bit types. Ensure the proper handling of pointers, sizes, and any system-specific configurations that differ between 32-bit and 64-bit.
• Abstract 32-bit calls to 64-bit PhysX functions. If you're moving from a 32-bit version of the SDK to a 64-bit one, you must ensure all uintptr_t and pointer-related types are correctly managed.

