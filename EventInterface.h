#ifndef GAME_EVENT_H
#define GAME_EVENT_H


class EventInterface{
private:
    int some_data;
public:
    EventInterface() = default;
    EventInterface(int some_data);
    EventInterface(const EventInterface& other_event_interface);
    EventInterface& operator = (const EventInterface& other_event_interface);
    int get_data() const;
};


#endif //GAME_EVENT_H