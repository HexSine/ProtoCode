/*
 ResourceManager.hpp - Generic template resource manager

 (C) Alexander Thorne (SFML Coder) 2011
 http://sfmlcoder.wordpress.com/

 Manages loading and unloading of a resource type specified by a
 template argument.

****************************************************************/
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <string>
#include <exception>
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

class ResourceManager {
	typedef typename std::pair<URI, Resource*> ResourcePair;
	typedef typename std::map<URI, Resource*> ResourceList;

	// the list of the manager's resources
	ResourceList Resources;
public:
	~ResourceManager() { UnloadAll(); }

	// Load a resource with the specified URI
	// the URI could represent, e.g, a filename
	template <class T>
	URI& Load(URI& Uri);
	// unload a resource with the specified URI
	void Unload(URI& Uri);
	// unload all resources
	void UnloadAll();

	// get a pointer to a resource
	template <class T>
	T* GetPtr(URI& Uri);
	// get a reference to a resource
	template <class T>
	T& Get(URI& Uri);
};

template <class T>
URI& ResourceManager::Load(URI& Uri)
{
	// check if resource URI is already in list
	// and if it is, we do no more
	if (Resources.find(Uri) == Resources.end())
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
		Resources.insert(ResourcePair(Uri, temp));
	}
	return Uri;
}

inline void ResourceManager::Unload(URI& Uri)
{
	// try to find the specified URI in the list
	typename ResourceList::const_iterator itr = Resources.find(Uri);
	// if it is found...
	if (itr != Resources.end())
	{
		// ... deallocate it
		delete itr->second;
		// then remove it from the list
		Resources.erase(Uri);
	}
}

inline void ResourceManager::UnloadAll()
{
	// iterate through every element of the resource list
	typename ResourceList::iterator itr;
	for (itr = Resources.begin(); itr != Resources.end(); itr++)
		// delete each resource
		delete itr->second;
	// finally, clear the list
	Resources.clear();
}

template <class T>
T* ResourceManager::GetPtr(URI& Uri)
{
	// find the specified URI in the list
	typename ResourceList::const_iterator itr;
	// if it is there...
	itr = Resources.find(Uri);
	if (itr != Resources.end())
		// ... return a pointer to the corresponding resource
		return (T*)itr->second;
	// ... else return 0
	return 0;
}

template <class T>
T& ResourceManager::Get(URI& Uri)
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
#endif
