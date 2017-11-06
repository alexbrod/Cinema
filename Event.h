#ifndef  EVENT_H
#define EVENT_H

#include <ostream>
#include "Screening.h"
#include "Lecture.h"

class Event : public Screening, public Lecture
{
public:
	Event(const Screening& screening, const Lecture& lecture);

	Event(Event& event) = delete;

    Hall* getHall() const override ;

    void setHall(Hall* hall) override;

    void toOs(std::ostream& os) const override;
};

#endif