#ifndef ILRD_RD8081_UTILITY_HPP
#define ILRD_RD8081_UTILITY_HPP

// typedefs
typedef unsigned char byte_t;

#if __cplusplus<201104 
#define noexcept throw()
#define nullptr NULL  
#endif

// stderr macro
#ifndef NDEBUG 
#define DEBUG(X) do { cerr << "Debug [" << X << "] " << __FILE__ << " "<<\
    __LINE__ << "\n"; } while (0)
#else
#define DEBUG(X) 
#endif

// other
#define UNUSED(x) (void)(x)
#define SUCCESS 0
#define FAIL 1
#define BITS_IN_BYTE 8

// return min of two numbers
#ifndef MIN
#define MIN( n1, n2 )   ((n1) > (n2) ? (n2) : (n1))
#endif

// return max of two numbers 
#ifndef MAX
#define MAX( n1, n2 )   ((n1) > (n2) ? (n1) : (n2))
#endif

// Aligns the supplied size to the specified PowerOfTwo
#define ALIGN_SIZE( size_to_align, power_of_two )\
    (((size_to_align) + (power_of_two) - 1) & ~((power_of_two) - 1))

// Implementation of Uncopyable class  
// disable copy/assignment constructors
namespace ilrd
{

class Uncopyable
{
protected:
    Uncopyable() {}
    ~Uncopyable() {}
    
private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
};

} // namespace ilrd

#define NORMAL "\033[0m"
#define RED "\033[;031m"
#define GREEN "\033[;032m"

// automation macros for tests 
#define RUN_TEST(test, error_message){\
    if (test)\
    {\
        printf(GREEN);\
        printf("SUCCESS: [%s]\n", error_message);\
        printf(NORMAL);\
    }\
    else\
    {\
        printf(RED);\
        printf("FAIL: [%s]\n", error_message);\
        printf(NORMAL);\
    }\
}

#endif // ILRD_RD8081_UTILITY_HPP

