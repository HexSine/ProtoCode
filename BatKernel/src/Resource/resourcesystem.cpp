#include "BatKernel/precompiled.h"
#include "BatKernel/Resource/resourcesystem.h"

ResourceSystem::~ResourceSystem()
{
    UnloadAll();
}




// unload a resource with the specified URI
void ResourceSystem::Unload(URI& Uri)
{
    ResourceIterator itr = m_Resources.find(Uri);
    // if it is found...
    if (itr != m_Resources.end())
    {
        // ... deallocate it
        delete itr->second;
        // then remove it from the list
        m_Resources.erase(Uri);
    }
}


// unload all resources
void ResourceSystem::UnloadAll()
{
    // iterate through every element of the resource list
    ResourceIterator itr;
    for (itr = m_Resources.begin(); itr != m_Resources.end(); itr++)
        // delete each resource
        delete itr->second;
    // finally, clear the list
    m_Resources.clear();
}



