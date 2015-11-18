#ifndef KNIGHT_H
#define KNIGHT_H

#include "character.h"
class Knight : public Character
{
    public:
        Knight();
        virtual ~Knight();
    protected:
        virtual void SetStats();
    private:
};

#endif // KNIGHT_H
