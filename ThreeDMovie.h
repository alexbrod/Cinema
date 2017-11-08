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
	ThreeDMovie(string& name, int lengthInMinuttes, const vector<string>& actorsList,
				int ageLimit, eGenre genre, bool glasses);

    ~ThreeDMovie () override = default;

	bool isGlasses() const;

	void setGlasses(bool glasses);


	void toOs(ostream& os) const override;

};

#endif