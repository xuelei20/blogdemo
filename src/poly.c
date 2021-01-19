#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int add(double a, double b)
{
	return a + b;
}

void testAdd()
{
	int sum = add(1.1, 3.2);
	printf("sum:%d\n", sum);
}

template <typename T>
T sub(T a, T b)
{
	return a + b;
}

void testSub()
{
	int subi = sub(1, 3);
	printf("subi:%d\n", subi);
	double subd = sub(1.1, 3.3);
	printf("subd:%f\n", subd);
}

template <typename T>
class Foo
{
public:
	static T mul(T a, T b)
	{
		return a * b;
	}
};

void testMul()
{
	int mul = Foo<int>::mul(2, 3);
	printf("mul:%d\n", mul);
}

class Base
{
public:
	virtual void print()
	{
		printf("Base::print()\n");
	}
	virtual void show()
	{
		printf("Base::show()\n");
	}

	int m_b;
};

class Derive : public Base
{
public:
	virtual void print()
	{
		printf("Derive::print()\n");
	}

	int m_d;
};

class Derive2 : public Base
{
public:
	virtual void print()
	{
		printf("Derive2::print()\n");
	}
};

void testVirtual()
{
	Derive d;
	Derive2 d2;
	Base *p = &d;
	p->print();
	p = &d2;
	p->print();
}

void testMemory()
{
	Derive d;
	printf("sizeof(Derive):%ld\n", sizeof(d));

	d.m_b = 10;
	d.m_d = 2;
	printf("vtable ptr=%p, &m_b=%p, &m_d=%p\n", &d, &(d.m_b), &(d.m_d));
}

class Base2
{
public:
	virtual void msg(){}
};

class MultiDerive : public Base, public Base2
{
public:
	virtual void print()
	{
		printf("MultiDerive::print()\n");
	}
	int m_d;
};

void testMulMemory()
{
	MultiDerive md;
	printf("sizeof(MultiDerive):%ld\n", sizeof(md));
	printf("vtable ptr=%p, &m_b=%p, &m_d=%p\n", &md, &(md.m_b), &(md.m_d));
}

template <typename P>
class Math1
{
public:
	template <typename T>
	T add(T a, T b)
	{
		return a + b;
	}

	virtual int sub(int a, int b)
	{
		return a - b;
	}

	P m_a;
};

class Math2
{
public:
//	template <typename T>
//	virtual T add(T a, T b)
//	{
//		return a + b;
//	}
};


int main(int argc, char* argv[])
{
	testMulMemory();
	return 0;
}
