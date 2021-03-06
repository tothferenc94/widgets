#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include "graphics.hpp"
#include "widgets.hpp"
#include <functional>

class Button : public Widget {
protected:
    bool _checked;
public:
    Button(int x, int y, int sx, int sy);
    virtual ~Button(){}
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() const ;
    virtual void action(){};
};

class Lambda : public Button{
protected:
    std::function<void()> lambda_fv;
public:
    Lambda(int x, int y, int sx, int sy, std::function<void()> funct);
    void action();
};


#endif // BUTTON_H_INCLUDED
