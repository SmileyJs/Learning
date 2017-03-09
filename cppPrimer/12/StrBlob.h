#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <memory>

using namespace std;

class StrBlobPtr;

class StrBlob {
public:
	// using size_type = vector<string>::size_type;
	typedef vector<string>::size_type size_type;

	friend StrBlobPtr;

	StrBlob();
	StrBlob(vector<string> &vec);
	explicit StrBlob(initializer_list<string> il);

	size_type size() { return data->size();}
	bool empty() { return data->empty(); };

	string & front();
	string & back();
	// const string & front() const;
	// const string & back() const;
	string & front() const;
	string & back() const;
	void push_back(const string &s);
	void pop_back();

private:
	shared_ptr<vector<string>> data;
	void check(size_type t, const string &msg);
	void check(size_type t, const string &msg) const;
};

StrBlob::StrBlob()
{
	data = make_shared<vector<string>>();
}

StrBlob::StrBlob(vector<string> &s)
{
	data = make_shared<vector<string>>(s);
}

StrBlob::StrBlob(initializer_list<string> il)
{
	data = make_shared<vector<string>>(il);
}

void
StrBlob::check(size_type t, const string &msg)
{
	if (t > data->size()) {
		throw out_of_range(msg);
	}
}

void
StrBlob::check(size_type t, const string &msg) const
{
	if (t > data->size()) {
		throw out_of_range(msg);
	}
}

string &
StrBlob::front()
{
	check(0, "out_of_range_front");
	return data->front();
}

// const string &
// StrBlob::front() const
// {
// 	check(0, "out_of_range_const_front");
// 	return data->front();
// }

string &
StrBlob::front() const
{
	check(0, "out_of_range_front");
	return data->front();
}

string &
StrBlob::back()
{
	check(0, "out_of_range_back");
	return data->back();
}

// const string &
// StrBlob::back() const
// {
// 	check(0, "out_of_range_const_back");
// 	return data->back();
// }

string &
StrBlob::back() const
{
	check(0, "out_of_range_back");
	return data->back();
}

void
StrBlob::push_back(const string &s)
{
	data->push_back(s);
}

void
StrBlob::pop_back()
{
	check(0, "out_of_range_pop_back");
	data->pop_back();
}


class StrBlobPtr {
	StrBlobPtr ();
	StrBlobPtr (StrBlob &a , vector<string>::size_type sz = 0) : wPtr(a.data), curr = sz {};

	string &deRef();
	StrBlobPtr &incr();

private:
	shared_ptr<vector<string>> check();
	weak_ptr<vector<string>> wPtr;
	vector<string>::size_type curr;
};