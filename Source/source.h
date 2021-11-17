


#ifndef MY_SOURCE_H
#define MY_SOURCE_H

class iterator;

class Isource
{
public:
    virtual iterator* Create_Iterator()=0;
    //
};


class source: public Isource
{
private:
    virtual iterator* Create_Iterator()=0;
public:
    //source(/* args */);
    //~source();
};





#endif