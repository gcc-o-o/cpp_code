//tabletennis.h -- table-teniss base class
#ifndef TABLETENNIS_H_
#define TABLETENNIS_H_
#include <string>
using std::string;

//simple base class
class TableTennisPlayer
{
private:
	string firstname;
	string lastname;
	bool hastable;
public:
	TableTennisPlayer(const string & fn = "none", const string & ln = "none", bool ht = false);
	void Name() const;
	bool HasTable() const{return hastable;}
	void ResetTable(bool ht) {hastable = ht;}
};

//simplw derived class
class RatedPlayer : public TableTennisPlayer
{
private:
	unsigned int rating;
public:
	RatedPlayer(unsigned int r = 0, const string & fn = "none", const string & ln = "none", bool ht = false);
	RatedPlayer(unsigned int r, const TableTennisPlayer & ttp);
	unsigned int Rating() const {return rating;}
	void ResetRating(unsigned int r){rating = r;};
};

#endif