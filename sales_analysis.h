#ifndef SALES_ANALYSIS_H
#define SALES_ANALYSIS_H

#include <string>
#include <vector>

class TSalesDepartment {
private:
    std::string aDepartmentName;
    int aEmployeeCount;
    std::vector<double> aSales;

public:
//constructor con valores predeterminados para pDepartmentName (string vacio) y pEmployeeCount (0)
    TSalesDepartment(std::string pDepartmentName = "", int pEmployeeCount = 0);
    ~TSalesDepartment(); 

    void AddEmployeeSales(double pSale);
    double CalculateAverageSales() const;
    //metodo que compara si el promedio supero cierta cifra (50000)
    bool MeetsPerformanceThreshold() const;
    int FindTopPerformingEmployeeIndex() const;

    std::string GetDepartmentName() const;
};

typedef TSalesDepartment SalesDepartment;

#endif// :)
