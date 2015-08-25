#ifndef		MYSINGLETON_H_
# define	MYSINGLETON_H_

template<typename T>
class		MySingleton
{
public:
  static T&	getInstance() {
    static T	instance;
    return instance;
  }
};

#endif	// !MYSINGLETON_H_
