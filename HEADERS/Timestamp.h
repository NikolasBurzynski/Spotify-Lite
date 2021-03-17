#ifndef TIMESTAMP_H
#define TIMESTAMP_H
#include <string>

class Timestamp {
	public:
		Timestamp();
		Timestamp(const Timestamp &);
		void init(struct tm*);
		Timestamp& operator=(const Timestamp&);
		// print timestamp in yyyy/mm/dd hh:mm:ss format.
		std::string toString();
	private:
		void now();
		unsigned int secs;
		unsigned int mins;
		unsigned int hours;
		unsigned int day;
		unsigned int month;
		unsigned int year;
		// data members for secs, mins, hours, day, month and year.
};

#endif
