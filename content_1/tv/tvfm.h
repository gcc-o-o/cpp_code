//tvmf.h -- Tv and Remote classes, using friend member
#ifndef TVMF_H_
#define TVMF_H_

class Tv;		//forword declaration

class Remote
{
private:
	int mode;	//control TV and DVD
public:
	enum {TV, DVD};

	Remote(int m = TV) : mode(m) {}
	bool volup(Tv & t);
	bool voldown(Tv & t);
	void onoff(Tv & t);
	void chanup(Tv & t);
	void chandown(Tv & t);
	void set_channel(Tv & t, int c);
	void set_mode(Tv & t);
	void set_input(Tv & t);
};

class Tv
{
private:
	int state;		//on or off
	int volume;	// assume to be digitized
	int maxChannel;	//maximum number of channels
	int channel;	//current channel setting
	int mode;		//broadcast or cable
	int input;		//TV or DVD
public:
	friend void Remote::set_channel(Tv & t, int c);

	enum {Off, On};
	enum {MinVol, MaxVol = 20};
	enum {Antenna, Cable};
	enum {TV, DVD};

	Tv(int s = Off, int mc = 125) : state(s), volume(5),
		maxChannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff() {state = (state == On) ? Off : On;}
	bool ison() {return state == On;}
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() {mode = (mode == Antenna) ? Cable : Antenna;}
	void set_input() {input = (input == TV) ? DVD : TV;}
	void settings() const;	//display all settings
};

inline bool Remote::volup(Tv & t) {return t.volup();}
inline bool Remote::voldown(Tv & t) {return t.voldown();}
inline void Remote::onoff(Tv & t) {t.onoff();}
inline void Remote::chanup(Tv & t) {t.chanup();}
inline void Remote::chandown(Tv & t) {t.chandown();}
inline void Remote::set_channel(Tv & t, int c) {t.channel = c;}
inline void Remote::set_mode(Tv & t) {t.set_mode();}
inline void Remote::set_input(Tv & t) {t.set_input();}

#endif