#include "stack.h"

stack::stack()
{
  _init();
}

void stack::_init()
{
  _top = NULL;
}

void stack::push(const Element & item)
{
  node * baby = new node(item, _top);
  _top = baby;
}

void stack::pop()
{
  node * old = _top;
  _top = _top->next;
  delete old;
}

Element stack::top() const
{
  return _top->data;
}

bool stack::empty() const
{
  return _top == NULL;
}