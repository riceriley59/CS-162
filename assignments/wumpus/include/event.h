#ifndef EVENT_H
#define EVENT_H

#include <string>

class Event{
    protected:
        //event type identifier
        std::string const name;
    public:
        //allow child classes to call constructor with specfic name to identify type
        //of event
        Event();
        Event(std::string);

        //pure virtual funcitons
        virtual void percept()=0;
        virtual void encounter()=0;

        std::string get_name() const;

        virtual ~Event() = default;
};


#endif