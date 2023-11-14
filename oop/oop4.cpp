#include <iostream>
using namespace std;

class Employees 
{
protected:
    float HourlyPayment;

public:

    Employees(float payment) : HourlyPayment(payment) {}
    virtual void PrintPayment() = 0;
    virtual void RecalculatePayment() 
    {
    }
};

class Worker : public Employees {

private:
    float WorkedHours;
public:
    Worker(float payment, float hours) : Employees(payment), WorkedHours(hours) {}

    void PrintPayment() override
    {
        cout << "Worker's payment by hour: " << HourlyPayment << std::endl;
    }

    void RecalculatePayment() override 
    {
        if (WorkedHours > 12)
        {
            HourlyPayment += HourlyPayment * 0.1;
        }
        else
        {
            HourlyPayment -= HourlyPayment * 0.1;
        }
    }
};

class Manager : public Employees 
{
private:
    float WorkedHours;

public:
    Manager(float payment, float hours) : Employees(payment), WorkedHours(hours) {}

    void PrintPayment() override 
    {
        cout << "Manager's payment by hour: " << HourlyPayment << std::endl;
    }

    void RecalculatePayment() override
    {
        if (WorkedHours > 12)
        {
            HourlyPayment += HourlyPayment * 0.1;
        }
        else 
        {
            HourlyPayment -= HourlyPayment * 0.1;
        }
    }
};

int main() {
    Worker worker(10.0, 15);
    Manager manager(20.0, 10);

    worker.RecalculatePayment();
    manager.RecalculatePayment();

    worker.PrintPayment();
    manager.PrintPayment();

    return 0;
}