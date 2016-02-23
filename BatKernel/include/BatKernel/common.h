typedef signed char         s8;
typedef signed short        s16;
typedef signed int          s32;

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;

typedef float               f32;
typedef double              f64;
/*
//Get unique ID's for classes
using typeid_t = void const*;
template <typename T>
static typeid_t* type_id() noexcept
{
    static char const type_id{};
    return &type_id;
}
*/
using typeid_t = void const*;

template <typename T>
static typeid_t type_id() noexcept
{
    static char const type_id{};
    return &type_id;
}



template<typename T>
void SafeDelete(T* p)
{
    if(p != NULL)
    {
        delete p;
    }
}

template<typename T>
void SafeDeleteArray(T* p)
{
    if(p != NULL)
    {
        delete[] p;
    }
}
template <typename T1,typename T2>
static std::vector<T1*> VectorCast(std::vector<T2*> inVec)
{
    std::vector<T1*> outVec(inVec.size());
    for(u32 i = 0, c = inVec.size(); i < c; ++i)
    {
        outVec[i] = static_cast<T1*>(inVec[i]);
    }
    return outVec;
}
template<typename T>
void SafeDeleteVector(std::vector<T>& p)
{
    for(u32 i = 0, c = p.size(); i < c; ++i)
    {
        delete p[i];
    }
    p.clear();
}
template <typename T1,typename T2>
static std::unordered_set<T1*> UnorderedSetCast(std::unordered_set<T2*> inVec)
{
    std::unordered_set<T1*> outVec(inVec.size());
    for(u32 i = 0, c = inVec.size(); i < c; ++i)
    {
        outVec[i] = static_cast<T1*>(inVec[i]);
    }
    return outVec;
}
template<typename T>
void SafeDeleteSet(std::vector<T>& p)
{
    for(u32 i = 0, c = p.size(); i < c; ++i)
    {
        delete p[i];
    }
    p.clear();
}
