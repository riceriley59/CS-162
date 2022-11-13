#ifndef EVENT_H
#define EVENT_H

#include <string>

class Event{
    protected:
        //event type identifier
        char const name;
    public:
        //allow child classes to call constructor with specfic name to identify type
        //of event
        Event();
        Event(char);

        //pure virtual funcitons
        virtual std::string percept()=0;
        virtual void encounter()=0;

        char get_name() const;

        virtual ~Event() = default;
};


#endif