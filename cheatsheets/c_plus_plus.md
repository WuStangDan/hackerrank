# C++ Cheat Sheet

## Pointers and References
```c++
int main()
{
  // Pointers
  int a = 1;
  int *b = &a;
  *b += 1;
  cout << a;
  // Output: 2
  
  // References
  int &c = a;
  c += 1;
  cout << a;
  // Output : 3
}
```

## Static Variables
```c++
int AddTooStatic(int input)
{
  static int a = 0;
  a += input;
  return a;
}

int main()
{
  cout << AddTooStatic(0);
  // Output: 0
  cout << AddTooStatic(2);
  // Output: 2
  cout << AddtooStatic(3);
  // Output: 5
}
```

## Overloading
```c++
int AddTooVariable(int input)
{
  return input+2;
}

string AddTooVariable(string input)
{
  input.append(" plus Two");
  return input;
}

int main()
{
  cout << AddTooVariable(3);
  // Output: 5
  cout << AddTooVariable("Three");
  // Output: Three plus Two
}
```

## Templates
```c++
template <typename T>
T AddTooTemplate(T input)
{
  T output;
  output = input + 2;
  return output;
}

int main()
{
  int a = 2;
  cout << AddTooTemplate(a);
  // Output: 4
  double b = 2.5;
  cout << AddTooTemplate(b);
  // Output: 4.5
  char c = 'a';
  cout << AddTooTemplate(c);
  // Output: c
}
```

## Derived Classes
```c++
class TestScores
{
  public:
    int test1;
    int test2;
    void SetTestScores(int in1, int in2)
    {
      test1 = in1;
      test2 = in2;
    }
};

class TestInfo : public TestScores
{
  public:
    int TestAverage()
    {
      return (test1 + test2)/2;
    }
};

int main()
{
  TestInfo math;
  math.SetTestScores(90, 70);
  cout << math.TestAverage();
  // Output: 80
}
```

## Virtual Functions
```c++
class BaseClass
{
  public:
    void Print1()
    {
      cout << "Hello";
    }
    virtual void Print2()
    {
      cout << "Hello";
    }
};

class DerivedClass : public BaseClass
{
  public:
    void Print1()
    {
      cout << "Goodbye";
    }
    void Print2()
    {
      cout << "Goodbye";
    }
};

int main()
{
  DerivedClass derived_class;
  derived_class.Print1();
  // Output: Goodbye
  BaseClass *base_class_ptr;
  base_class_ptr = new DerivedClass;
  base_class_ptr->Print1();
  // Output: Hello
  base_class_ptr->Print2();
  // Output: Goodbye
}
```

## Iterators
```c++
int main()
{
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
  {
    std::cout<< *it << " ";
  }
  // Output: 1 2 3
}
```

## Auto
```c++
int main()
{
  map<string, int> dog_age;
  dog_age["Mindy"] = 12;
  dog_age["Lexi"] = 9;

  for (auto n : dog_age)
  {
    cout << "Dog: " << n.first << " ";
    cout << "Age: " << n.second << ", ";
  }
  // Ouptut: Dog: Lexi Age: 9, Dog: Mindy Age: 12
}
```