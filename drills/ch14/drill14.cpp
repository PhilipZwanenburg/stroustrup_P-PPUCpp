#include <iostream>
#include <stdexcept>

using namespace std;

class B1 {
public:
	virtual void vf() { cout << "B1::vf "; }
	void f() { cout << "B1::f"; }
};

class D1: public B1 {
public:
	void vf() override { cout << "D1::vf "; }
};

class D1_step4: public B1 {
public:
	void vf() override { cout << "D14::vf "; }
	void f() { cout << "D14::f "; }
};

class B2 {
public:
	virtual void pvf() =0;
};

class D21 : public B2 {
public:
	D21(string str_in) : str{str_in} { }
	void pvf() override { cout << "D21:pvf. str: " << str << " "; }
private:
	string str;
};

class D22 : public B2 {
public:
	D22(int int_in) : i{int_in} { }
	void pvf() override { cout << "D22:pvf. int: " << i << " "; }
private:
	int i;
};

void f(B2 &b)
{
	b.pvf();
	cout << "\n";
}


void call(B1 &b)
{
	b.vf();
	b.f();
	cout << "\n";
}

void call_D1_step4(D1_step4 &d)
{
	d.vf();
	d.f();
	cout << "\n";
}

int main()
try {
	B1 B1_obj;
	call(B1_obj);

	D1 D1_obj;
	call(D1_obj); // D1::vf overrides B1::vf

	B1 &B1_ref {D1_obj};
	call(B1_ref); // D1::vf overrides B1::vf
	cout << "\n\n";

	// step 4
	B1 B1_obj4;
	call(B1_obj4);

	D1_step4 D1_obj4;
	call(D1_obj4);          // Passed as a B1, uses B1::f. D1_step4::vf overrides.
	call_D1_step4(D1_obj4); // Passed as a D1_step4, uses D1_step4::f. D1_step4::vf overrides.

	B1 &B1_ref4 {D1_obj4};
	call(B1_ref4); // As for the first case above.
//	call_D1_step4(B1_ref4); // Error: Passing B1 to D1_step4
	cout << "\n\n";

	// See 14.3.5 for pure virtual functions (skipped steps 5-6)
	// Cannot create an object of an abstract class, otherwise the same as virtual.

	D21 d21("hello");
	D22 d22(17);

	f(d21);
	f(d22);

	return 0;
} catch (exception &e) {
	cout << "Error: " << e.what() << '\n';
	return 1;
} catch (...) {
	cout << "Error: unhandled exception\n";
	return 2;
}
