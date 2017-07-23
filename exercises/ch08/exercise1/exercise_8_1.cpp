/*
	calculator from exercise 7.4 with modifications from:
		exercise(s): 8.1

	The question was unclear to me. As none of the functions outside of the Token_stream class use the input stream, I
	don't see why an istream& parameter would be necessary. (ToBeModified)
*/

#include "std_lib_facilities.h"
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
	istream& cin_ts;
public:
	Token_stream() :full(0), buffer(0), cin_ts(cin) { }
	// Logic error above; istream reference cannot be modified after default construction? ToBeModified

	Token get();
	void unget(Token t) { buffer=t; full=true; }
	void ignore(char);
	void set_stream(istream& is);
};

const char let = '#';
const char let_const = 'c';
const char quit = 'q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char func = 'f';

const string exitkey = "exit";
const string constkey = "const";

Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}

	char ch;
	cin_ts >> ch;
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
		cin_ts.unget();
		double val;
		cin_ts >> val;
		return Token(number,val);
	case '#': // Replacing 'let' with '#'
		return Token(let);
	} default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while(cin_ts.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
				s += ch; // Error Found: '=' -> '+='
			cin_ts.unget();

			if (s == exitkey)
				return Token(quit);

			if (s == "sqrt" ||
			    s == "pow")
				return Token(func,s);

			if (s == constkey)
				return Token(let_const);

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
	while (cin_ts>>ch)
		if (ch==c)
			return;
}

/*void Token_stream::set_stream(istream& is)
{
	cin_ts = is;
}*/

struct Variable {
	bool modifiable;
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v), modifiable(true) { }
	Variable(string n, double v, bool m) :name(n), value(v), modifiable(m) { }
};

class Symbol_table {
	vector<Variable> names;

public:
	double get(string s);
	void set(string s, double d);
	void add(string s, double d, bool m);
	bool is_declared(string s);
	void declare(string name, double d);
};

double Symbol_table::get(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ",s);
}


void Symbol_table::set(string s, double d)
{
	for (int i = 0; i < names.size(); ++i) // Error Found: '<=' -> '<'
		if (names[i].name == s) {
			if (!names[i].modifiable)
				error("attempting to reassign a const Variable");

			names[i].value = d;
			return;
		}
	error("set: undefined name ",s);
}

void Symbol_table::add(string s, double d, bool m)
{
	names.push_back(Variable(s,d,m));
}

bool Symbol_table::is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s)
			return true;
	return false;
}

void Symbol_table::declare(string name, double d)
{
	if (is_declared(name))
		error("define: attempting to define an already existing name ",name);

	names.push_back(Variable(name,d,false));
}

Token_stream ts;
Symbol_table st;

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
		return st.get(t.name);
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

double declaration(bool is_modifiable)
{
	Token t = ts.get();
	if (t.kind != name) {
		if (t.kind == func) {
			string name = t.name;
			if (st.is_declared(name))
				error(name, " reserved for a function");
		}
		error("name expected in declaration");
	}

	string name = t.name;
	bool previously_declared = false;
	if (st.is_declared(name))
		previously_declared = true;

	Token t2 = ts.get();
	if (t2.kind != '=')
		error("= missing in declaration of " ,name);

	double d = expression();
	if (!previously_declared)
		st.add(name,d,is_modifiable);
	else
		st.set(name,d);

	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration(true);
	case let_const:
		return declaration(false);
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
	st.declare("pi",3.14);

	st.declare("sqrt",reserved_name);


//	ts.set_stream(cin);

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
