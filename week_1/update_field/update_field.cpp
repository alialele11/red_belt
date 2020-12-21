#include "airline_ticket.h"
#include "test_runner.h"

using namespace std;
bool operator ==(const Date& l, const Date& r){
	return l.year == r.year && l.month == r.month && l.day == r.day;
}
bool operator ==(const Time l, const Time& r){
	return l.hours == r.hours && l.minutes == r.minutes;
}
bool operator <(const Date& l, const Date& r){
	if(l.year == r.year){
		if(l.month == r.month){
			return  l.day < r.day;
		}
		else{
			return l.month < r.month;
		}
	}
	else{
		return l.year < r.year;
	}
}
bool operator <=(const Date& l, const Date& r){
	if(l.year == r.year){
		if(l.month == r.month){
			return  l.day < r.day;
		}
		else{
			return l.month <= r.month;
		}
	}
	else{
		return l.year < r.year;
	}
}
bool operator <(const Time l, const Time& r){
	if(l.hours == r.hours){
		return l.minutes < r.minutes;
	}
	else{
		return l.hours < r.hours;
	}
}
bool operator <=(const Time l, const Time& r){
	if(l.hours == r.hours){
		return l.minutes <= r.minutes;
	}
	else{
		return l.hours < r.hours;
	}
}

ostream& operator<<(ostream& os, const Date& d) {
  return os << d.year << '-' << d.month << '-' << d.day;
}

ostream& operator<<(ostream& os, const Time& t) {
  return os << t.hours << ':' << t.minutes;
}
istream& operator >> (istream& stream, Date& date) {
    stream >> date.year;
    stream.ignore(1);
    stream >> date.month;
    stream.ignore(1);
    stream >> date.day;
    return stream;
}
istream& operator >> (istream& stream, Time& time) {
    stream >> time.hours;
    stream.ignore(1);
    stream >> time.minutes;
    return stream;
}
#define UPDATE_FIELD(ticket, field, values)  { \
    map<string, string>::const_iterator it;   \
    it = values.find(#field); \
    if (it != values.end()) { \
    istringstream is(it->second); \
    is >> ticket.field; \
    }}
void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"},
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };
  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
  // значения этих полей не должны измениться
  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}
