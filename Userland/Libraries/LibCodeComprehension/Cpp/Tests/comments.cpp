// function
void foo() {}


// struct
struct Bar {
    int x;
    // data member
    int y;

    // member function
    void getBlah() {}
};


void baz()
{
    // bar struct
    Bar bar{};
    bar.x = 2;
    bar.y = 3;
    bar.getBlah();

    foo();
    
    // var declaration
    int xy;
    xy = 10;

    if (true) {
        // inside if
        int z;
        z = 90;
    } else {
        // inside else
        int j;
        j = 3;
    }

    for(;;) {
        // inside for
        int zz;
        zz = 2;
    }
}
