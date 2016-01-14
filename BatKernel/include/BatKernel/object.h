#ifndef OBJECT_H
#define OBJECT_H


class Object
{
    public:
        Object();
        virtual ~Object();



        virtual void Init() = 0;
        virtual void Terminate() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
    protected:
    private:
};

#endif // OBJECT_H
