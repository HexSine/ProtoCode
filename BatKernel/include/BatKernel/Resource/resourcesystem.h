#ifndef RESOURCESYSTEM_H
#define RESOURCESYSTEM_H

#include "BatKernel/Resource/resource.h"

typedef const std::string URI;

// exceptions
namespace Exceptions {

	// thrown if user requests a resource URI not present in the manager's list
	class URINotFound : public std::runtime_error
	{
	public:
		URINotFound(const std::string& Message = "The specified URI was not found in the resource index.")
			: runtime_error(Message) { }
	};

	// thrown if a resource allocation fails
	class BadResourceAllocation : public std::runtime_error {
	public:
		BadResourceAllocation(const std::string& Message = "Failed to allocate memory for resource.")
			: runtime_error(Message) {}
	};
}
class ResourceSystem
{

    typedef std::unordered_map<std::string,Resource*> ResourceMap;
    typedef std::pair<std::string,Resource*> ResourcePair;
    typedef ResourceMap::const_iterator ResourceIterator;

    public:
        ~ResourceSystem();
        // Load a resource with the specified URI
        // the URI could represent, e.g, a filename
        template <typename T>
        URI& Load(URI& Uri);



        // unload a resource with the specified URI
        void Unload(URI& Uri);


        // unload all resources
        void UnloadAll();
        // get a pointer to a resource
        template <typename T>



        T* GetPtr(URI& Uri);
        // get a reference to a resource
        template <typename T>
        T& Get(URI& Uri);


        ResourceMap m_Resources;
    private:
};
template <typename T>
URI& ResourceSystem::Load(URI& Uri)
{
    // check if resource URI is already in list
    // and if it is, we do no more
    if (m_Resources.find(Uri) == m_Resources.end())
    {
        // try to allocate the resource
        // NB: if the Resource template argument does not have a
        // constructor accepting a const std::std::string, then this
        // line will cause a compiler error
        Resource* temp = new (std::nothrow) T(Uri);
        // check if the resource failed to be allocated
        // std::nothrow means that if allocation failed
        // temp will be 0
        if (!temp)
            throw Exceptions::BadResourceAllocation();
        // add the resource and it's URI to the manager's list
        m_Resources.insert(ResourcePair(Uri, temp));
    }
    return Uri;
}
// get a pointer to a resource
template <typename T>
T* ResourceSystem::GetPtr(URI& Uri)
{
    // find the specified URI in the list
    ResourceIterator itr;
    // if it is there...
    if ((itr = m_Resources.find(Uri)) != m_Resources.end())
        // ... return a pointer to the corresponding resource
        return (T*)itr->second;
    // ... else return 0
    return 0;
}
// get a reference to a resource
template <typename T>
T& ResourceSystem::Get(URI& Uri)
{
    // get a pointer to the resource
    T* temp = GetPtr<T>(Uri);
    // if the resource was found...
    if (temp)
        // ... dereference the pointer to return a reference
        // to the resource
        return *temp;
    else
        // ... else throw an exception to notify the caller that
        // the resource was not found
        throw Exceptions::URINotFound();
}
#endif // RESOURCESYSTEM_H
