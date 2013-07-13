#ifndef BUILD_REQUIRED_H_
#define BUILD_REQUIRED_H_

// Copy constructor and operator= are banned
// meaning no copy of an object, thus no shallow copying
// If you do need a copy, then make a function that will make it
#define DISALLOW_COPY_AND_ASSIGN(Type)\
  Type(const Type& other) = delete;\
  void operator=(const Type& other) = delete;\

#define DISALLOW_MOVE(Type)\
  Type(Type&& other) = delete;\
  Type& operator=(Type&& other) = delete

#endif // BUILD_REQUIRED_H_
