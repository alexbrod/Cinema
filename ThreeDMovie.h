#ifndef  THREEDMOVIE_H
#define THREEDMOVIE_H

#include <ostream>
#include "Movie.h"

class ThreeDMovie : public Movie
{

private:
	bool glasses;
public:

    ThreeDMovie(const ThreeDMovie& threeDMovie) = delete;
	ThreeDMovie(char * name, int lengthInMinuttes, const char** actorsList, int numberOfActors,
				int ageLimit, eGenre genre, bool glasses);

    ~ThreeDMovie () override = default;

	bool isGlasses() const;

	void setGlasses(bool glasses);


	void toOs(ostream& os) const override;

};

#endif