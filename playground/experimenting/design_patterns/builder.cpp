#include <string>
#include <memory>

class Pizza
{
public:
    void setDough(const std::string &dough)
    {
        m_dough = dough;
    }

    void setSauce(const std::string &sauce)
    {
        m_sauce = sauce;
    }

    void setTopping(const std::string &topping)
    {
        m_topping = topping;
    }

private:
    std::string m_dough;
    std::string m_sauce;
    std::string m_topping;
};

class PizzaBuilder
{
public:
    virtual ~PizzaBuilder() {}

    Pizza *getPizza()
    {
        return m_pizza.release();
    }

    void createNewPizza()
    {
        m_pizza = std::make_unique<Pizza>();
    }

    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;

protected:
    std::unique_ptr<Pizza> m_pizza;
};

class HawaiianPizzaBuilder : public PizzaBuilder
{
public:
    virtual ~HawaiianPizzaBuilder() {}

    void buildDough() override
    {
        m_pizza->setDough("cross");
    }

    void buildSauce() override
    {
        m_pizza->setSauce("mild");
    }

    void buildTopping() override
    {
        m_pizza->setTopping("ham+pineapple");
    }
};

class SpicyPizzaBuilder : public PizzaBuilder
{
public:
    virtual ~SpicyPizzaBuilder() {}

    void buildDough() override
    {
        m_pizza->setDough("pan baked");
    }

    void buildSauce() override
    {
        m_pizza->setSauce("hot");
    }

    void buildTopping() override
    {
        m_pizza->setTopping("pepperoni+salami");
    }
};

class Cook
{
public:
    void openPizzaBuilder(PizzaBuilder *pb)
    {
        m_pizzaBuilder = pb;
        m_pizzaBuilder->createNewPizza();
    }

    Pizza *getPizza()
    {
        return m_pizzaBuilder->getPizza();
    }

    void makePizza()
    {
        m_pizzaBuilder->buildDough();
        m_pizzaBuilder->buildSauce();
        m_pizzaBuilder->buildTopping();
    }

private:
    PizzaBuilder *m_pizzaBuilder;
};

int main()
{
    Cook cook;
    HawaiianPizzaBuilder hawaiianPizzaBuilder;
    SpicyPizzaBuilder spicyPizzaBuilder;

    cook.openPizzaBuilder(&hawaiianPizzaBuilder);
    cook.makePizza();
    Pizza *hawaiianPizza = cook.getPizza();

    cook.openPizzaBuilder(&spicyPizzaBuilder);
    cook.makePizza();
    Pizza *spicyPizza = cook.getPizza();

    delete hawaiianPizza;
    delete spicyPizza;

    return 0;
}
