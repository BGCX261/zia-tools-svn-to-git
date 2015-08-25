#ifndef IREF_COUNTER_H
#define IREF_COUNTER_H

namespace ptr
{ 
  class IRefCounter
  {
    public:
      virtual void incr() = 0; 
      virtual bool decr() = 0;
      virtual bool shared() = 0;
  };
};

#endif