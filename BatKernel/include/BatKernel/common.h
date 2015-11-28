typedef signed char         s8;
typedef signed short        s16;
typedef signed int          s32;

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;

typedef float               f32;
typedef double              f64;


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
