#include <iostream>
using namespace std;

class Admin {
protected:
    string company_name;
    int manager_salary;
    int employee_salary;

private:
    int total_staff;
    double total_annual_revenue;
    bool can_terminate;

public:
    void setAdminData() {
        company_name = "ABC Pvt Ltd";
        manager_salary = 50000;
        employee_salary = 30000;
        total_staff = 100;
        total_annual_revenue = 5000000;
        can_terminate = true;
    }

    void myAccess() {
        cout << "Admin Access:" << endl;
        cout << "Company: " << company_name << endl;
        cout << "Manager Salary: " << manager_salary << endl;
        cout << "Employee Salary: " << employee_salary << endl;
    }
};

class Manager : public Admin {
public:
    void myAccess() {   // override
        cout << "\nManager Access:" << endl;
        cout << "Company: " << company_name << endl;
        cout << "Manager Salary: " << manager_salary << endl;
    }
};

class Employee : public Manager {
public:
    void myAccess() {   // override
        cout << "\nEmployee Access:" << endl;
        cout << "Company: " << company_name << endl;
        cout << "Employee Salary: " << employee_salary << endl;
    }
};

int main() {
    Employee e;

    e.setAdminData();

    // Calling overridden functions
    e.Admin::myAccess();
    e.Manager::myAccess();
    e.myAccess();

    return 0;
}