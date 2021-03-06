#ifndef SZABALYOK_H_INCLUDED
#define SZABALYOK_H_INCLUDED
#include "examplecheckbox.hpp"
#include <functional>

class Szabalyok {

public:
    std::vector<ExampleCheckBox*> vektor;
    Szabalyok(std::vector<ExampleCheckBox*> vektor);
    virtual ~Szabalyok(){}
    int handle(std::vector<ExampleCheckBox*> vektor);
};

class Lambda_Szabalyok : public Szabalyok{
protected:
    std::function<void()> lambda_fv;
public:
    Lambda_Szabalyok(std::function<void()> funct);
    void action();
};

#endif // SZABALYOK_H_INCLUDED
