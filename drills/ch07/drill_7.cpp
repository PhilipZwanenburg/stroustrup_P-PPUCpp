/*
	calculator08buggy.cpp modified with the corrections of drill 7 of
	Stroustrop(2014,2nd) - Programming Principles and Practice Using C++
*/

#include "../../std_lib_facilities.h"
#include <climits>

struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string n) :kind(ch), name(n) { }
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer=t; full=true; }

	void ignore(char);
};

const char let = '#';
const char quit = 'q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char func = 'f';

const string exitkey = "exit";

Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;
	switch (ch) {
	case quit:  // Allow for quitting by entering quit
	case print: // Replaced case ';' with 'print'
	case '(': case ')':
	case '+': case '-': case '*': case '/':
	case '%':
	case '=':
	case ',': // Used for pow
		return Token(ch);
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9': {
		cin.unget();
		double val;
		cin >> val;
		return Token(number,val);
	case '#': // Replacing 'let' with '#'
		return Token(let);
	} default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch)))
				s += ch; // Error Found: '=' -> '+='
			cin.unget();
//			if (s == "let") // Replaced with '#' above
//				return Token(let);

			if (s == exitkey)
				return Token(quit);

			if (s == "sqrt" ||
			    s == "pow")
				return Token(func,s);

			return Token(name,s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c)
			return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ",s);
}

void set_value(string s, double d)
{
	for (int i = 0; i < names.size(); ++i) // Error Found: '<=' -> '<'
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ",s);
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s)
			return true;
	return false;
}

void define_name(string name, double d)
{
	if (is_declared(name))
		error("define: attempting to define an already existing name ",name);

	names.push_back(Variable(name,d));
}

Token_stream ts;

double expression();

vector<double> primary2()
{
	// Used to get a vector of 2 doubles for the pow function.

	Token t = ts.get();
	switch (t.kind) {
	case '(': {
		vector<double> d {0.0,0.0};
		d[0] = expression();

		t = ts.get();
		if (t.kind != ',')
			error("',' expected");

		d[1] = expression();

		t = ts.get();
		if (t.kind != ')')
			error("')' expected");

		return d;
	} default:
		error("primary2 expected");
	}
}

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(': {
		double d = expression();
		t = ts.get();
		if (t.kind != ')')
			error("'(' expected");
		return d; // Error Found: Added 'return d;'
	} case '-':
		return - primary();
	case '+':
		return primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	case func:
		if (t.name == "sqrt") {
			double d = primary();
			if (d < 0)
				error("attempted to take sqrt of a negative number");
			return sqrt(d);
		} else if (t.name == "pow") {
			vector<double> d = primary2();

			// narrow cast returns an error here.
			int exp = static_cast<int>(d[1]);
			return pow(d[0],exp);
		}
		error("unknown function");
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/': {
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		} default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) {
		if (t.kind == func) {
			string name = t.name;
			if (is_declared(name))
				error(name, " reserved for a function");
		}
		error("name expected in declaration");
	}

	string name = t.name;
	if (is_declared(name))
		error(name, " declared twice");

	Token t2 = ts.get();
	if (t2.kind != '=')
		error("= missing in declaration of " ,name);

	double d = expression();
	names.push_back(Variable(name,d));

	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) // discard all "prints"
			t = ts.get();

		if (t.kind == quit)
			return;

		ts.unget(t);
		cout << result << statement() << endl;
	} catch (runtime_error &e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

const int reserved_name = INT_MAX;

int main()
try {
	// predifine names:
	define_name("k",1000);
	define_name("sqrt",reserved_name);

	calculate();

	return 0;
} catch (exception &e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin>>c && c!=';');
	return 1;
} catch (...) {
	cerr << "exception\n";
	char c;
	while (cin>>c && c!=';');
	return 2;
}
