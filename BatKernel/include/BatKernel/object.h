#ifndef OBJECT_H
#define OBJECT_H


class Object
{
    public:
        Object();
        virtual ~Object();

        virtual void Init();
        virtual void Terminate();
        virtual void Update();
    protected:
    private:
};

#endif // OBJECT_H
